#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

int n,m,a[52];
double ans, f[52][52][52], c[52][52];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> a[i];

	c[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	}

	f[0][0][0] = 1;
	for (int i = 0; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			for (int k = 0; k <= i; ++k)
			{
				int lim = min(i, k * a[j]);
				for (int p = 0; p <= lim; ++p)
				{
					int len = (int)ceil(1.0 * p / a[j]);
					if (len < k)
						f[i][j][k] += f[i-p][j-1][k] * c[i][p] * pow(j-1,i-p) / pow(j,i);
					else
						for (int t = 0; t <= k; ++t)
							f[i][j][k] += f[i-p][j-1][t] * c[i][p] * pow(j-1,i-p) / pow(j,i);
				}
			}
		}

	ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += f[n][m][i] * i;
	
	printf("%.10f\n", ans);

	return 0;
}
