#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		queue<int> cl;
		int* deg = new int[numCourses];
		vector<int>* edge = new vector<int>[numCourses];
		memset(deg, 0, sizeof(int)*numCourses);
		for (auto i : prerequisites)
		{
			deg[i.first]++;
			edge[i.second].push_back(i.first);
		}
		int fin = 0;
		for (int i = 0; i < numCourses; i++)
		{
			if (deg[i] == 0)
			{
				cl.push(i);
				fin++;
			}
		}
		while (!(cl.empty()))
		{
			int p = cl.front();
			cl.pop();
			for (auto q : edge[p])
			{
				deg[q]--;
				if (deg[q] == 0)
				{
					cl.push(q);
					fin++;
				}
			}
		}
		return fin == numCourses;
	}
};
