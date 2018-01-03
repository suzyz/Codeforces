// DP.
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 202;

int n,m,ans,vis[maxn][maxn][maxn];

void dfs(int minute,int a,int b)
{
	if (a < 0 || b < 0 || vis[minute][a][b])
		return;
	vis[minute][a][b] = true;

	ans = max(ans,minute);

	if (a == 0 || b == 0)
		return;

	if (a >= 2)
		dfs(minute+1,a-2,b+1);
	if (b >= 2)
		dfs(minute+1,a+1,b-2);
}

int main()
{
	cin >> n >> m;
	dfs(0,n,m);
	
	cout << ans << endl;

	return 0;
}