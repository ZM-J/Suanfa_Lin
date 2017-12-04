#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m, n;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>> f;
        f.resize(m+1);
        for (int i = 0; i <= m; i++)
        {
            f[i].resize(n+1);
        }
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (obstacleGrid[i-1][j-1]) 
                {
                    f[i][j] = 0;
                }
                else
                {
                    if (i == 1 && j == 1)
                    {
                        f[i][j] = 1;
                    }
                    else
                    {
                        f[i][j] = f[i][j-1] + f[i-1][j];
                    }
                }
        return f[m][n];
    }
};
