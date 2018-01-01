// Dijkstra with optimization. O(NlogN)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

const int maxn = 100002;

int n, m;
bool vis[maxn];
long long dist[maxn];
vector<pair<int,int>> g[maxn];
set<pair<int,int>> s(pair<int,int>,mycomparison);

class mycomparison
{
public:
  	bool operator() (const int& lhs, const int&rhs) const
  	{
    	if (reverse) return (lhs>rhs);
    	else return (lhs<rhs);
	}
};

void dijkstra()
{
	memset(dist,-1,sizeof(dist));
	dist[1] = 0;
	s.insert(make_pair(0,1));

	for (int i = 1; i < n; ++i)
	{
		if (s.empty())
			break;

		int idx = s.begin()->second;
		if (idx == n)
			break;

		int mind = s.begin()->first;

		vis[idx] = true;

		for (int j = 0; j < g[idx].size(); ++j)
		{
			int k = g[idx][j].first;
			if (!vis[k])
				if (dist[k] == -1 || dist[k] > mind + g[idx][j].second)
				{
					dist[k] =  mind + g[idx][j].second;
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

	cout << dist[n] << endl;
	return 0;
}
