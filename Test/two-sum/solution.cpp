#include <bits/stdc++.h>
using namespace std;
// 这两行不应该出现在解答中 仅仅为编译方便而用

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
        	auto it = m.find(target - nums[i]);
        	if (it == m.end())
        	{
        		m.insert(make_pair(nums[i], i));
        	}
        	else
        	{
        		vector<int> ret;
        		ret.push_back(it->second);
        		ret.push_back(i);
        		return ret;
        	}
        }
    }
};
