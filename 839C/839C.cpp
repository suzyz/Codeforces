#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;
const int maxn = 100002;

int n,len[maxn];
double p[maxn], ans = 0;
vector<int> g[maxn];
bool vis[maxn];
queue<int> q;

void bfs()
{
	len[1] = 0; 
	p[1] = 1.0;

	vis[1] = true;
	for (int i = 0; i < g[1].size(); ++i)
	{
		int x = g[1][i];
		len[x] = 1;
		p[x] = 1.0/g[1].size();

		vis[g[1][i]] = true;
		q.push(g[1][i]);
	}

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int j = 0; j < g[x].size(); ++j)
		{
			int y = g[x][j];
			if (vis[y])
				continue;

			len[y] = len[x] + 1;
			p[y] = p[x] / (g[x].size() - 1);

			vis[y] = true;
			q.push(y);
		}
	}
}

int main()
{
	cin >> n;
	if (n == 1)
	{
		printf("%.7f\n", ans);
		return 0;
	}

	for (int i = 1; i < n; ++i)
	{
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	bfs();

	for (int i = 1; i <= n; ++i)
		if (g[i].size() == 1) /* i is a leaf */
			ans += p[i] * len[i];

	printf("%.7f\n", ans);

	return 0;
}

