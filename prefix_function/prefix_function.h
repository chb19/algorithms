vector<int> prefix_function(const string& s)
{
    vector<int> p(s.length() + 1);
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