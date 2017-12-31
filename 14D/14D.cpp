#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 202;

int n;
int edges[maxn][2],degree[maxn];
bool g[maxn][maxn];
bool co[maxn],vis[maxn];

void color(int cur)
{
	co[cur] = true;
	for (int i = 1; i <= n; ++i)
		if (g[cur][i] && !co[i])
			color(i);
}

int dfs(int cur)
{
	int maxl = 0;
	vis[cur] = true;

	for (int i = 1; i <= n; ++i)
		if (g[cur][i] && !vis[i])
			maxl = max(maxl,dfs(i) + 1);

	return maxl;
}

int longest_path(bool c)
{
	int ret = 0;
	for (int i = 1; i <= n; ++i)
		if (co[i] == c && degree[i] == 1)
		{
			memset(vis,0,sizeof(vis));
			ret = max(ret,dfs(i));
		}

	return ret;
}

int main()
{
	cin >> n;
	int a,b;
	for (int i = 1; i < n; ++i)
	{
		cin >> a >> b;
		edges[i][0] = a;
		edges[i][1] = b;
		++degree[a];
		++degree[b];
		g[a][b] = g[b][a] = true;
	}
	
	int x,y, res = 0;
	for (int i = 1; i < n; ++i)
	{
		a = edges[i][0];
		b = edges[i][1];
		--degree[a];
		--degree[b];
		g[a][b] = g[b][a] = false;

		memset(co,false,sizeof(co));
		color(a);

		x = longest_path(true);
		y = longest_path(false);

		res = max(res,x*y);

		g[a][b] = g[b][a] = true;
		++degree[a];
		++degree[b];
	}

	cout << res << endl;

	return 0;
}

