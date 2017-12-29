//O(N)

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 1000002;
int n,k, sum[maxn];
string s;

int main()
{
	cin >> k >> s;
	n = s.length();
	if (n == 0 || n < k)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i-1] + s[i-1] - '0';

	int st = 0, en = 0, last_v = 0;
	long long res = 0;
	for (int i = 1; i <= n; ++i)
	{
		int v = sum[i-1] + k;
	//	cout << v << endl;
		if (i > 1 && v == last_v && v == sum[st])
		{
			st = max(st,i);
			if (st <= en)
				res += en-st+1;
				
			//	cout << i << ":"<<st << " "<< en << endl;
		}
		else
		{
			if (sum[st] < v)
				st = max(en+1,i);
			else
				st = max(st,i);
				
			while (st <= n && sum[st] < v)
				++st;

			if (st > n)
				break;

			en = st;
			while (en+1 <= n && sum[en+1] == sum[st])
				++en;
			//cout << i << ":"<<st << " "<< en << endl;

			if (sum[st] == v)
				res += en-st+1;

			last_v = v;
		}
	}

	cout << res << endl;

	return 0;
}
