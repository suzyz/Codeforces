#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;

/* ans = -(1^n + 2^n + ... + (m-1)^n)/(m^n) + m */

int m,n;
double ans;

int main()
{
	cin >> m >> n;

	ans = m;

	if (m == 1)
	{
		printf("%.5f\n", ans);
		return 0;
	}
	
	for (int i = 1; i < m; ++i)
		ans -= pow(1.0 * i / m, n);

	printf("%.5f\n", ans);
	return 0;
}
