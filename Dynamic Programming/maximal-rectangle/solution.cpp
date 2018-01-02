#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0)
        {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> cum;
        cum.resize(m);
        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            cum[i].resize(n+1);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (matrix[i][j-1] == '0')
                {
                    cum[i][j] = 0;
                }
                else
                {
                    cum[i][j] = cum[i][j-1] + 1;
                }
            }
        }
        for (int j = 1; j <= n; j++)
        {
            stack<pair<int, int>> s;
            s.push(make_pair(0,-1));
            for (int i = 0; i < m; i++)
            {
                while (s.size() > 1)
                {
                    pair<int, int> t = s.top();
                    if (t.first <= cum[i][j])
                    {
                        break;
                    }
                    s.pop();
                    ret = max(ret, t.first * (i - s.top().second - 1));
                }
                s.push(make_pair(cum[i][j], i));
            }
            while (s.size() > 1)
            {
                pair<int, int> t = s.top();
                s.pop();
                ret = max(ret, t.first * (m - s.top().second - 1));
            }
        }
        return ret;
    }
};
