#include <bits/stdc++.h>
using namespace std;
// 这两行不应该出现在解答中 仅仅为编译方便而用

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *a = &nums2, *b = &nums1;
        if (nums1.size() == 0) return (nums2[(nums2.size()-1)/2]+nums2[nums2.size()/2])/2.0;
        if (nums2.size() == 0) return (nums1[(nums1.size()-1)/2]+nums1[nums1.size()/2])/2.0;
        if (nums1[0] < nums2[0])
        {
            a = &nums1;
            b = &nums2;
        }
        int sa = a->size(), sb = b->size();
        int l = 0, r = sa - 1;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            int t = (sa + sb) / 2 - mid - 1;
            if (t < -1)
            {
                r = mid - 1;
            }
            else if (t >= sb - 1)
            {
                l = mid;
            }
            else if ((*a)[mid] > (*b)[t+1])
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
        int t = (sa + sb) / 2 - l - 1;
        if ((sa + sb) % 2 == 1)
        {
            if (t == -1) return (*a)[l];
            else return max((*a)[l],(*b)[t]);
        }
        else if (t == -1)
        {
            return ((*a)[l] + (*a)[l-1]) / 2.0;
        }
        else if ((*a)[l] > (*b)[t])
        {
            int z;
            if (l == 0) z = (*b)[t];
                else z = max((*a)[l-1],(*b)[t]);
            return ((*a)[l] + z) / 2.0;
        }
        else
        {
            int z;
            if (t == 0) z = (*a)[l];
                else z = max((*a)[l], (*b)[t-1]);
            return ((*b)[t] + z) / 2.0;
        }
    }
};
