#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        set<pair<int, int> > s; // <数值, 编号>
        vector<ListNode*> cur(lists);
        for (int i = 0; i < k; i++)
        {
            if (cur[i] != NULL)
            {
                s.insert(make_pair(cur[i]->val, i));
            }
        }
        ListNode *ret = NULL;
        ListNode *curNode = NULL, *preNode = NULL;
        while (!s.empty())
        {
            pair<int, int> toDeal = *s.begin();
            s.erase(toDeal);
            curNode = new ListNode(toDeal.first);
            if (preNode == NULL) 
            {
                ret = curNode;
            }
            else
            {
                preNode->next = curNode;
            }
            preNode = curNode;
            cur[toDeal.second] = cur[toDeal.second]->next;
            if (cur[toDeal.second] != NULL)
            {
                s.insert(make_pair(cur[toDeal.second]->val, toDeal.second));
            }
        }
        return ret;
    }
};
