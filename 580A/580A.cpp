#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int n, res = 0, pre = -1, cur, len = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> cur;
		if (cur >= pre)
		{
			++len;
			res = max(res,len);
		}
		else
			len = 1;

		pre = cur;
	}

	cout << res << endl;
	return 0;
}
