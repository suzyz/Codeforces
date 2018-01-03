// Greedy.
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 202;

int n,m,ans;

int main()
{
	cin >> n >> m;
	while (n > 0 && m > 0)
	{
		if (n > m)
		{
			int tmp = n;
			n = m;
			m = tmp;
		}

		if (m == 1)
			break;
		if (m == 2)
		{
			++ans;
			break;
		}

		int now = (m-1)>>1;
		ans += now;
		n += now;
		m -= (now<<1);
	}
	
	cout << ans << endl;

	return 0;
}