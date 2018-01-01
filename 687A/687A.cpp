
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 100002;

int n,m;
vector<int> g[maxn], color_set[2];
int co[maxn];


bool color(int cur,int c)
{
	co[cur] = c;
	color_set[c].push_back(cur);

	for (int i = 0; i < g[cur].size(); ++i)
	{
		int x = g[cur][i];
		if (co[x] == -1)
		{
			if (!color(x,1-c))
				return false;
		}
		else
		{
			if (co[x] != 1-c)
				return false;
		}
	}

	return true;
}

int main()
{
	cin >> n >> m;
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	memset(co,-1,sizeof(co));

	bool bipartite = true;
	for (int i = 0; i < n; ++i)
		if (co[i] == -1 && g[i].size() > 0)
		{
			if (!color(i,0))
			{
				bipartite = false;
				break;
			}
		}

	if (bipartite)
	{
		for (int i = 0; i < 2; ++i)
		{
			cout << color_set[i].size() << endl;
			for (int j = 0; j < color_set[i].size(); ++j)
				cout << color_set[i][j]+1 << " ";
			cout << endl;
		}
	}
	else
		cout << -1 << endl;

	return 0;
}
