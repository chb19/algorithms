// Prefix function
//   one-indexed
//   returns vector p such that p[i] = length of longest prefix s that is a proper suffix of s[0..i)
//   Time complexity: O(n)
#include <vector>
#include <string>

std::vector<int> prefix_function(const std::string& s)
{
    std::vector<int> p(s.length() + 1);
    int len = 0;
    for (int i = 1; i < s.length(); i++)
    {
        while (true)
        {
            if (s[i] == s[len])
            {
                len++;
                break;
            }
            if (len == 0)
                break;
            len = p[len];
        }
        p[i + 1] = len;
    }
    return p;
}