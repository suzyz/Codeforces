#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 2010;
int n,res;
vector<int> g[maxn];
bool vis[maxn];

void dfs(int cur,int depth)
{
	res = max(res,depth);
	for (int i = 0; i < g[cur].size(); ++i)
		if (!vis[g[cur][i]])
			dfs(g[cur][i],depth+1);
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int tmp;
		cin >> tmp;
		if (tmp == -1)
			continue;

		g[tmp].push_back(i);
	}

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			dfs(i,1);

	cout << res << endl;

	return 0;
}