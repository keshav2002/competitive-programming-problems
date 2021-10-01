#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s2.size() > s1.size() || (s2.size() == s1.size() && s1 != s2))
        {
            cout << -1 << endl;
            continue;
        }
        int need[256] = {0};
        for (int i = 0; i < s2.size(); i++)
            need[s2[i]]++;
        int count = s2.size(), i = 0, j = 0, l = 0, r = 0;
        while (r < s1.size())
        {
            if (need[s1[r]] > 0)
                count--;
            need[s1[r]]--;
            while (count == 0)
            {
                if (j == 0 || r - l < j - i)
                    i = l, j = r;
                need[s1[l]]++;
                if (need[s1[l]] > 0)
                    count++;

                l++;
            }
            r++;
        }
        if (i == 0 && j == 0)
            cout << -1;
        else
            for (; i <= j; i++)
                cout << s1[i];
        cout << endl;
    }
}