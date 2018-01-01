/*
Consider this:
3
1 2
2 1
2 2
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 10002;

int n,m,lim;
vector<int> g[maxn<<1];
int dist[maxn<<1];
bool vis[maxn<<1];

void dijkstra()
{
	for (int i = 1; i <= lim; ++i)
		dist[i] = lim+1;

	dist[n] = 0;
	for (int i = 1; i < lim; ++i)
	{
		int idx = 0, mind = lim+1;
		for (int j = 1; j <= lim; ++j)
			if (!vis[j] && dist[j] < mind)
			{
				idx = j;
				mind = dist[j];
			}

		if (idx == 0 || idx == m)
			break;

		vis[idx] = true;
		for (int j = 0; j < g[idx].size(); ++j)
			if (!vis[g[idx][j]] && dist[g[idx][j]] > mind + 1)
				dist[g[idx][j]] = mind + 1;
	}
}

int main()
{
	cin >> n >> m;
	if (n == m)
	{
		cout << 0 << endl;
		return 0;
	}

	lim = max(n,m)<<1;
	for (int i = 2; i <= lim; ++i)
		g[i].push_back(i-1);
	
	for (int i = 1; (i<<1) <= lim; ++i)
		g[i].push_back(i<<1);
	
	dijkstra();

	cout << dist[m] << endl;

	return 0;
}
