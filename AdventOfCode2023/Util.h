#pragma once
#include <string>
#include <vector>

class Util
{
public:
    // https://stackoverflow.com/a/3418285
    static void replaceAll(std::string& str, const std::string& from, const std::string& to) {
        if (from.empty())
            return;
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
    }

    // https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
    static std::vector<std::string> split(std::string s, std::string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }

    // https://stackoverflow.com/a/65920738
    static std::string strip(const std::string& inpt)
    {
        auto start_it = inpt.begin();
        auto end_it = inpt.rbegin();
        while (std::isspace(*start_it))
            ++start_it;
        while (std::isspace(*end_it))
            ++end_it;
        return std::string(start_it, end_it.base());
    }

    // https://stackoverflow.com/a/65920738 modified
    static std::string strip(const std::string& inpt, char toStrip)
    {
        bool ok = false;
        for (char c : inpt)
        {
            if (c != toStrip)
            {
                ok = true;
            }
        }
        if (!ok)
        {
            return "";
        }
        auto start_it = inpt.begin();
        auto end_it = inpt.rbegin();
        while (*start_it == toStrip)
            ++start_it;
        while (*end_it == toStrip)
            ++end_it;
        return std::string(start_it, end_it.base());
    }

    // https://stackoverflow.com/a/9331125
    static int nChoosek(int n, int k)
    {
        if (k > n) return 0;
        if (k * 2 > n) k = n - k;
        if (k == 0) return 1;

        int result = n;
        for (int i = 2; i <= k; ++i) {
            result *= (n - i + 1);
            result /= i;
        }
        return result;
    }
};

