#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;

const int maxn = 18;

int n, total;
double p[maxn][maxn], f[maxn][1 << maxn];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> p[i][j];
	}

	total = (1 << n) - 1;
	for (int i = 0; i < n; ++i)
		f[i][1<<i] = 1;

	for (int j = 1; j <= total; ++j)
	{
		int m = 0, tmp = j;
		while (tmp != 0)
		{
			if ((tmp&1) != 0)
				++m;
			tmp >>= 1;
		}

		if (m == 1)
			continue;

		for (int i = 0; i < n; ++i)
			if ((j & (1 << i)) != 0)
			{
				for (int k = 0; k < n; ++k) /* k is eaten next. */
					if (k != i && (j & (1 << k)) != 0)
					{
						for (int t = 0; t < n; ++t) /* t eats k */
							if (t != k && (j & (1 << t)) != 0)
								f[i][j] += p[t][k] * f[i][j - (1 << k)];
					}

				f[i][j] = f[i][j] * 2 / m / (m-1);
			}
	}

	for (int i = 0; i < n; ++i)
		printf("%.7f ", f[i][total]);

	printf("\n");
	return 0;
}
