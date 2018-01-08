
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int n,m,k,c,d;

	cin >> c >> d >> n >> m >> k;

	if (k >= n*m)
		cout << 0 << endl;
	else
	{
		int req = n * m - k;
		int ans = req * d; // all rounds are additional.
		ans = min(ans, (int)(c * ceil(1.0 * req / n))); // all rounds are main.
		ans = min(ans, (int)(c * floor(1.0 * req / n) + d * (req % n))); // mixed
		cout << ans << endl;
	}
	return 0;
}
