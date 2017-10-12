#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    	ch.clear();
    	res.clear();
    	down = new int[n]; memset(down, 0, n*sizeof(int));
        down2 = new int[n]; memset(down2, 0, n*sizeof(int));
        downNode = new int[n]; memset(downNode, 0, n*sizeof(int));
        up = new int[n]; memset(up, 0, n*sizeof(int));
        fa = new int[n]; memset(fa, 0, n*sizeof(int));
        vis = new bool[n]; memset(vis, 0, n*sizeof(bool));
        for (auto i : edges)
        {
        	int from = i.first;
        	int to = i.second;
        	e[from].push_back(to);
        	e[to].push_back(from);
        }
        ans = 0x3f3f3f3f;
        fa[0] = -1;
        buildTree(0);
        findDown(0, 0);
        findUp(0);
        for (int i = 0; i < n; i++)
        {
        	int nowAns = max(up[i], down[i]);
			if (nowAns < ans)
			{
				res.clear();
				res.push_back(i);
				ans = nowAns;
			}
			else if (nowAns == ans)
			{
				res.push_back(i);
			}
		}
        delete [] down;
        delete [] down2;
        delete [] downNode;
        delete [] up;
        delete [] fa;
        delete [] vis;
        return res;
    }
private:
	void buildTree(int x)
	{
		vis[x] = true;
		for (auto i : e[x])
		{
			if (!vis[i])
			{
				fa[i] = x;
				ch[x].push_back(i);
				buildTree(i);
			}
		}
	}
	int findDown(int x, int nowdep)
	{
		int branchDepth = 0;
		for (auto i : ch[x])
		{
			branchDepth = findDown(i, nowdep + 1) - nowdep;
			if (branchDepth > down[x])
			{
				down2[x] = down[x];
				down[x] = branchDepth;
				downNode[x] = i;
			}
			else if (branchDepth > down2[x])
			{
				down2[x] = branchDepth;
			}
		}
		return down[x] + nowdep;
	}
	void findUp(int x)
	{
		if (x != 0)
		{
			int f = fa[x];
			if (downNode[f] == x)
			{
				up[x] = max(up[f],down2[f]) + 1;
			}
			else
			{
				up[x] = max(up[f],down[f]) + 1;
			}
		}
		for (auto i : ch[x])
		{
			findUp(i);
		}
	}
	unordered_map<int, vector<int> > e;
	unordered_map<int, vector<int> > ch;
	vector<int> res;
	int *down, *down2, *downNode, *up, *fa;
	bool *vis;
	int ans;
};
