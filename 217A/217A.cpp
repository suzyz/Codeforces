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

const int maxn = 102;

int n;
int pos[maxn][2];
bool g[maxn][maxn],vis[maxn];

void dfs(int cur)
{
	vis[cur] = true;
	for (int i = 0; i < n; ++i)
		if (g[cur][i] && !vis[i])
			dfs(i);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> pos[i][0] >> pos[i][1];
		for (int j = 0; j < i; ++j)
			if (pos[i][0] == pos[j][0] || pos[i][1]  == pos[j][1])
				g[i][j] = g[j][i] = true;		
	}
	
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (!vis[i])
		{
			dfs(i);
			++res;
		}

	cout << res-1 << endl;

	return 0;
}


