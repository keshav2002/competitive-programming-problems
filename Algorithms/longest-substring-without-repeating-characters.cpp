class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int start = 0, end = 0, res = INT_MIN;
        unordered_set<char> charset;
        while (end < s.length())
        {
            auto it = charset.find(s[end]);
            if (it == charset.end())
            {
                charset.insert(s[end]);
                res = max(res, (end - start + 1));
                end++;
            }
            else
            {
                charset.erase(s[start]);
                start++;
            }
        }
        return res != INT_MIN ? res : 0;
    }
};