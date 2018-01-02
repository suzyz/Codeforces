// Dijkstra with optimization. O(NlogN)
// Using STL's priority_queue container.

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int maxn = 100002;

int n,m,pre[maxn];
bool vis[maxn];
long long dist[maxn];
vector<pair<int,int> > g[maxn];

struct mycomparison
{
  	bool operator() (const pair<int,int>& a, const pair<int,int>&b) const
  	{
    	return (a.second > b.second);
	}
};
priority_queue<pair<int,int>,vector<pair<int,int> >,mycomparison> h;

void dijkstra()
{
	memset(dist,-1,sizeof(dist));
	dist[1] = 0;
	h.push(make_pair<int,int>(1,0));

	while (!h.empty())
	{
		int idx = h.top().first;
		if (idx == n) /* Found the shortest path to n, no need to continue */
			break;

		if (vis[idx]) /* Vertex idx is in the set and has been used to update distances of other vertices. */
		{
			h.pop();
			continue;
		}

		vis[idx] = true;
		int mind = h.top().second;
		h.pop();

		for (int j = 0; j < g[idx].size(); ++j)
		{
			int k = g[idx][j].first;
			if (!vis[k])
				if (dist[k] == -1 || dist[k] > mind + g[idx][j].second)
				{
					pre[k] = idx;
					dist[k] = mind + g[idx][j].second;
					h.push(make_pair(k,dist[k]));
				}
		}
	}
}

int main()
{
	cin >> n >> m;
	int x,y,z;
	for (int i = 1; i <= m; ++i)
	{
		cin >> x >> y >> z;
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}

	dijkstra();

	if (dist[n] == -1)
		cout << -1 << endl;
	else
	{
		int cur = n;
		vector<int> path;
		while (cur > 0)
		{
			path.push_back(cur);
			cur = pre[cur];
		}
		for (int i = path.size()-1; i >= 0; --i)
			cout << path[i] << " ";
		cout << endl;
	}

	return 0;
}
