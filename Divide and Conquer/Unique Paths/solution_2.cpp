class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ret = 1;
        m--, n--;
        for (int i = m+1; i <= m+n; i++)
        {
            ret *= i;
            ret /= i-m;
        }
        return ret;
    }
};
