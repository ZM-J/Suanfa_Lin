class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		queue<int> cl;
		vector<int> ret;
		int* deg = new int[numCourses];
		vector<int>* edge = new vector<int>[numCourses];
		memset(deg, 0, sizeof(int)*numCourses);
		for (auto i : prerequisites)
		{
			deg[i.first]++;
			edge[i.second].push_back(i.first);
		}
		for (int i = 0; i < numCourses; i++)
		{
			if (deg[i] == 0)
			{
				cl.push(i);
				ret.push_back(i);
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
					ret.push_back(q);
				}
			}
		}
		if (ret.size() != numCourses) ret.clear();
		return ret;
	}
};
