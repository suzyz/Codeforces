#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 100002;

int n,m,kk;
int roads[maxn][3];
bool is_warehouse[maxn];

int main()
{
	cin >> n >> m >> kk;
	if (kk == 0)
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < m; ++i)
		cin >> roads[i][0] >> roads[i][1] >> roads[i][2];

	int a,b;
	for (int i = 0; i < kk; ++i)
	{
		cin >> a;
		is_warehouse[a] = true;
	}

	int ans = INT_MAX;
	for (int i = 0; i < m; ++i)
	{
		a = roads[i][0];
		b = roads[i][1];
		if (is_warehouse[a] && !is_warehouse[b])
			ans = min(ans,roads[i][2]);
		if (!is_warehouse[a] && is_warehouse[b])
			ans = min(ans,roads[i][2]);
	}

	if (ans == INT_MAX)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}
