#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 102;

int n,sum[maxn];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		sum[i] = sum[i-1] + x;
	}

	int res = 0;
	
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			res = max(res,sum[n] - sum[j] + sum[i-1] + j - i + 1 - (sum[j] - sum[i-1]));

	cout << res << endl;

	return 0;
}
