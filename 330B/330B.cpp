/*
Star graph.
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 1002;

int n, m;
bool is_free[maxn];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		is_free[i] = true;

	m <<= 1;
	for (int i = 1; i <= m; ++i)
	{
		int x;
		cin >> x;
		is_free[x] = false;
	}

	int center = 0;
	for (int i = 1; i <= n; ++i)
		if (is_free[i])
		{
			center = i;
			break;
		}

	cout << n-1 << endl;
	for (int i = 1; i <= n; ++i)
		if (i != center)
			cout << center << " " << i << endl;

	return 0;
}
