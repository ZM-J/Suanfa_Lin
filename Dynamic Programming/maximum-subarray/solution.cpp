#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cumsum = 0, mincs = 0, ans = 0x80000000;
        for (int i = 0; i < n; i++)
        {
            cumsum += nums[i];
            ans = max(ans, cumsum - mincs);
            mincs = min(mincs, cumsum);
        }
        return ans;
    }
};
