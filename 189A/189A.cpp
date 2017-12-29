#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 4002;
int n, v[3], f[maxn];

int main()
{
	cin >> n >> v[0] >> v[1] >> v[2];
	memset(f,-1,sizeof(f));
	f[0] = 0;

	for (int i = 0; i < n; ++i)
		if (f[i] >= 0)
		{
			for (int j = 0; j < 3; ++j)
				if (i + v[j] <= n)
					f[i + v[j]] = max(f[i + v[j]], f[i] + 1);
		}

	cout << f[n] << endl;

	return 0;
}
