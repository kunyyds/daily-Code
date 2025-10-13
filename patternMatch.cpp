#include <iostream>
#include <vector>
using namespace std;

class PatternMatch
{
public:
    bool match(string &s1, string &pattern)
    {
        int len2 = pattern.length();
        vector<char> elements;
        vector<int> count;
        vector<bool> flags;
        elements.reserve(len2);
        count.reserve(len2);
        parse(pattern, elements, count, flags);

        bool result = true;
        int index = 0;
        int pindex = 0;
        while (index < s1.length())
        {
            if (elements[pindex] == '.')
            {
                ++index;
                ++pindex;
                continue;
            }
            else
            {
                if (s1[index] != elements[pindex])
                {
                    if (count[pindex] > 0)
                    {
                        result = false;
                        break;
                    }
                    ++pindex;
                }
                else
                {
                    int tmp = 0;
                    char start = s1[index];
                    while (index < s1.length() && s1[index] == start)
                    {
                        ++index;
                        ++tmp;
                    }
                    if (tmp < count[pindex] || (tmp > count[pindex] && !flags[pindex]))
                    {
                        result = false;
                        break;
                    }
                    ++pindex;
                }
            }
        }
        return result;
    }

private:
    void parse(string &pattern, vector<char> &ele, vector<int> &count, vector<bool> &flags)
    {
        char prev = -1;
        int s = 0;
        int cnt = 0;
        while (s < pattern.size())
        {
            if (prev < 0)
            {
                prev = pattern[s];
                ele.push_back(pattern[s]);
                count.push_back(1);
                flags.push_back(false);
                ++s;
                continue;
            }
            if (pattern[s] == '*' || pattern[s] == '?')
            {
                if (pattern[s] == '*')
                {
                    count.back() = 0;
                }
                flags.back() = true;
                ++s;
                continue;
            }
            if (pattern[s] == '.')
            {
                prev = -1;
                ele.push_back('.');
                count.push_back(1);
                flags.push_back(false);
                ++s;
                continue;
            }
            if (pattern[s] != prev)
            {
                prev = pattern[s];
                ele.push_back(prev);
                count.push_back(1);
                flags.push_back(false);
            }
            else
            {
                ++count.back();
            }
            ++s;
        }
    }
};

int main()
{
    string pattern = ".abca*a?bbbc*ccc";
    cout << std::boolalpha;
    string s1 = ".abcabbbccc";
    PatternMatch solver;
    cout<<solver.match(s1,pattern);
    return 0;
}