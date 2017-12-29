#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 502;
int n,m,lim,mo,bug[maxn],f[maxn][maxn];

int main()
{
	cin >> n >> m >> lim >> mo;
	for (int i = 1; i <= n; ++i)
		cin >> bug[i];

	f[0][0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			for (int k = bug[i]; k <= lim; ++k)
				f[j][k] = (f[j][k] + f[j-1][k-bug[i]]) % mo;
	}

	int res = 0;
	for (int j = 0; j <= lim; ++j)
		res = (res + f[m][j]) % mo;

	cout << res << endl;

	return 0;
}
