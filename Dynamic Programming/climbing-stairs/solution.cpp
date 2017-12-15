#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3)
        {
            return n;
        }
        int p = 1, q = 2, r;
        for (int i = 3; i <= n; i++)
        {
            r = p + q;
            p = q;
            q = r;
        }
        return r;
    }
};
