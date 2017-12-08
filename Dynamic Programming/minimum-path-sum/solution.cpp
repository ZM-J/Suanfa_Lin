#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m, n;
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> f;
        f.resize(m);
        for (int i = 0; i < m; i++)
        {
            f[i].resize(n);
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int numa, numb;
                if (i == 0 && j == 0)
                {
                    numa = numb = 0;
                }
                else
                {
                    if (i == 0)
                    {
                        numa = 0x7FFFFFFF;
                    }
                    else
                    {
                        numa = f[i-1][j];
                    }
                    if (j == 0)
                    {
                        numb = 0x7FFFFFFF;
                    }
                    else
                    {
                        numb = f[i][j-1];
                    }
                }
                f[i][j] = min(numa,numb) + grid[i][j];
            }
        return f[m-1][n-1];
    }
};
