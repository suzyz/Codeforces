#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 100002;

int n,m,res;
bool cat[maxn], vis[maxn];
vector<int> g[maxn];

void dfs(int cur,int consecutive)
{
	vis[cur] = true;

	if (cat[cur])
		++consecutive;
	else
		consecutive = 0;

	if (consecutive > m)
		return;

	if ((cur > 0 && g[cur].size() <= 1) || (n == 1)) /* if cur is a leaf */
	{
		++res;
		return;
	}

	for (int i = 0; i < g[cur].size(); ++i)
		if (!vis[g[cur][i]])
			dfs(g[cur][i],consecutive);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		if (x == 1)
			cat[i] = true;
	}
	
	for (int i = 0; i < n-1; ++i)
	{
		int x,y;
		cin >> x >> y;
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(0,0);

	cout << res << endl;

	return 0;
}
