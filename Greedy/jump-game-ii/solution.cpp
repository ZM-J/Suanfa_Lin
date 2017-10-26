#include <bits/stdc++.h>
using namespace std;
// 这两行不应该出现在解答中 仅仅为编译方便而用

class Solution {
public:
    int jump(vector<int>& nums) {
    	int cost = 0;
        int l = 0, r = 0;
        int n = nums.size();
		while (r < n - 1)
		{
			cost++;
			int nxtl = r + 1, nxtr = r + 1;
			for (int i = l; i <= r; i++)
			{
				nxtl = min(nxtl, i + nums[i]);
				nxtr = max(nxtr, i + nums[i]);
			}
			l = nxtl, r = nxtr;
		}
		return cost;
    }
};
