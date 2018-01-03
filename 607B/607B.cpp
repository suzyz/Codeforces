// Consider a single gemstone.
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 502;

int n,c[maxn];
int f[maxn][maxn];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
		f[i][i] = 1;
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int st = 1; st <= n-i+1; ++st)
		{
			int en = st+i-1;

			f[st][en] = 1 + f[st+1][en];
			if (c[st] == c[st+1])
				f[st][en] = min(f[st][en],1 + f[st+2][en]);
			
			for (int k = st+2; k <= en; ++k)
			{
				if (c[st] == c[k])
					f[st][en] = min(f[st][en],f[st+1][k-1] + f[k+1][en]);
			}
		}
	}
	
	cout << f[1][n] << endl;

	return 0;
}
