#pragma once
#include <string>
#include <iostream>
#include "input_day7_2022.h"
#include "Util.h"
#include <cassert>

class Day7_2022_File
{
public:
    Day7_2022_File(std::string name, int64_t size)
    {
        m_name = name;
        m_size = size;
    }
    ~Day7_2022_File() = default;

    int64_t GetSize() const
    {
        return m_size;
    }

private:
    std::string m_name;
    int64_t m_size;
};

class Day7_2022_Directory
{
public:
    Day7_2022_Directory(std::string name, Day7_2022_Directory* pParent)
    {
        m_name = name;
        m_size = -1;
        m_pParent = pParent;
    }
    ~Day7_2022_Directory() = default;

    int64_t GetSize() const
    {
        if (m_size >= 0)
        {
            return m_size;
        }

        m_size = 0;
        for (Day7_2022_Directory* d : m_children)
        {
            m_size = m_size + d->GetSize();
        }
        for (Day7_2022_File* f : m_files)
        {
            m_size = m_size + f->GetSize();
        }

        return m_size;
    }

    std::string GetName() const
    {
        return m_name;
    }

    void AddDirectory(std::string name)
    {
        Day7_2022_Directory* newDir = new Day7_2022_Directory(name, this);
        m_children.push_back(newDir);
    }

    void AddFile(int64_t size, std::string name)
    {
        Day7_2022_File* newFile = new Day7_2022_File(name, size);
        m_files.push_back(newFile);
    }

    Day7_2022_Directory* GetDirectory(std::string name)
    {
        for (int i = 0; i < m_children.size(); ++i)
        {
            if (m_children[i]->GetName() == name)
            {
                return m_children[i];
            }
        }
        return nullptr;
    }

    Day7_2022_Directory* GetParent() { return m_pParent; }

    std::vector<Day7_2022_Directory*>& GetChildren() { return m_children; }
private:
    std::vector<Day7_2022_Directory*> m_children;
    std::vector<Day7_2022_File*> m_files;

    std::string m_name;

    mutable int64_t m_size;

    Day7_2022_Directory* m_pParent = nullptr;
};


class Day7_2022
{
public:
    Day7_2022() = default;
    ~Day7_2022() = default;

    int64_t total(std::vector<std::string> input, bool secondPart)
    {
        int64_t totalSpace = 70000000ll;
        int64_t requiredSpace = 30000000ll;

        // build directory tree
        Day7_2022_Directory homeDir("/", nullptr);
        Day7_2022_Directory* pCurrentDir = &homeDir;
        bool inLSCommand = false;
        for (std::string line : input)
        {
            if (line[0] == '$')
            {
                inLSCommand = false;
                std::string cdL = line;
                Util::replaceAll(cdL, "$ cd ", "");
                if (cdL != line)
                {
                    if (cdL == "..")
                    {
                        pCurrentDir = pCurrentDir->GetParent();
                        continue;
                    }
                    else if (cdL == "/")
                    {
                        pCurrentDir = &homeDir;
                    }
                    else
                    {
                        pCurrentDir = pCurrentDir->GetDirectory(cdL);
                    }

                }
                else
                {
                    Util::replaceAll(cdL, "$ ls", "");
                    if (cdL != line)
                    {
                        inLSCommand = true;
                        continue;
                    }
                }
            }
            else
            {
                assert(inLSCommand);
                std::vector<std::string> sp = Util::split(line, " ");
                if (sp[0] == "dir")
                {
                    pCurrentDir->AddDirectory(sp[1]);
                }
                else
                {
                    pCurrentDir->AddFile(stoll(sp[0]), sp[1]);
                }
            }
        }

        // traverse directory tree
        std::vector<Day7_2022_Directory*> directories_to_test;
        directories_to_test.push_back(&homeDir);

        int64_t p1Total = 0;
        int64_t p2Min = totalSpace;
        int64_t rootDirSpace = homeDir.GetSize();
        int64_t requiredSize = requiredSpace - (totalSpace - rootDirSpace);
        while (!directories_to_test.empty())
        {
            Day7_2022_Directory* pDir = directories_to_test.back();
            if (pDir->GetSize() <= 100000)
            {
                p1Total = p1Total + pDir->GetSize();
            }
            if (pDir->GetSize() > requiredSize && pDir->GetSize() < p2Min)
            {
                p2Min = pDir->GetSize();
            }
            directories_to_test.pop_back();
            std::vector<Day7_2022_Directory*>& dirs = pDir->GetChildren();
            for (auto dir : dirs)
            {
                directories_to_test.push_back(dir);
            }
        }
        if (!secondPart)
        {
            return p1Total;
        }
        else
        {
            return p2Min;
        }
    }



};
