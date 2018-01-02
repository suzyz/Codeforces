#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

const int maxn = 100002;

int n;
long long freq[maxn], f[maxn];

int main()
{
	cin >> n;
	int x,maxv = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		freq[x]++;
		maxv = max(maxv,x);
	}

	f[1] = freq[1];
	for (int i = 1; i <= maxv; ++i)
		f[i] = max(f[i-1], f[i-2] + freq[i] * i);

	cout << f[maxv] << endl;
	return 0;
}
