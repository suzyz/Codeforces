
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 1002;

int n,lim;
bool is_prime[maxn*maxn];

int main()
{
	cin >> n;
	lim = 1000*n + 1;

	is_prime[2] = true;
	for (int i = 3; i <= lim; i += 2)
		is_prime[i] = true;

	for (int i = 2; (i<<1) <= lim; ++i)
		if (is_prime[i])
		{
			int k = i << 1;
			while (k <= lim)
			{
				is_prime[k] = false;
				k += i;
			}
		}

	int cur = n + 1;
	for (int i = 1; i <= 1000; ++i)
		if (!is_prime[cur])
		{
			cout << i << endl;
			break;
		}
		else
			cur += n;

	return 0;
}
