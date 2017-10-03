#include <bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if (node == NULL) return NULL; // 特判 
        unordered_map<int, UndirectedGraphNode *> ans;
        queue<UndirectedGraphNode *> old;
        UndirectedGraphNode* ret = new UndirectedGraphNode(node->label);
        ans.insert(make_pair(node->label, ret));
        old.push(node);
        while (!old.empty())
        {
        	UndirectedGraphNode* deal = old.front();
        	old.pop();
        	UndirectedGraphNode* nn = ans.find(deal->label)->second;
        	for (int i = 0; i < deal->neighbors.size(); i++)
        	{
        		UndirectedGraphNode* nxtold = deal->neighbors[i];
        		UndirectedGraphNode* nxtnew;
        		if (ans.find(nxtold->label) == ans.end())
        		{
        			old.push(nxtold);
        			nxtnew = new UndirectedGraphNode(nxtold->label);
        			ans.insert(make_pair(nxtold->label, nxtnew));
        		}
        		else
        		{
        			nxtnew = ans.find(nxtold->label)->second;
        		}
        		nn->neighbors.push_back(nxtnew);
        	}
        }
        return ret;
    }
};
