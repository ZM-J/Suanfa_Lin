#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int longestValidParentheses(string s) {
        int h = 0;
        int ans = 0;
        int l = s.length();
        vector<int> zuizao;
        zuizao.reserve(l+1);
        zuizao[0] = -1;
        for (int i = 0; i < l; i++)
        {
            if (h == 0 && s[i] == ')')
            {
                zuizao[0] = i;
            }
            else
            {
                if (s[i] == '(')
                {
                    h++;
                    zuizao[h] = i;
                }
                else
                {
                    h--;
                    ans = max(ans, i - zuizao[h]);
                }
            }
        }
        return ans;
    }
};
