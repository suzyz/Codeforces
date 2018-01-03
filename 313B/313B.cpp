#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 100002;

string s;
int n, m, sum[maxn];

int main()
{
	cin >> s;
	n = s.length(); /* 2 <= n <= 10^5 */
	
	for (int i = 1; i < n; ++i)
	{
		if (s[i-1] == s[i])
			sum[i] = sum[i-1] + 1;
		else
			sum[i] = sum[i-1];
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int l,r;
		cin >> l >> r;
		cout << sum[r-1] - sum[l-1] << endl;
	}

	return 0;
}