
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 1002;

int n, m, v[maxn];
long long res;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin >> x >> y;
		res += min(v[x],v[y]);
	}

	cout << res << endl;
	return 0;
}
