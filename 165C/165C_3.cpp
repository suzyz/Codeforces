//O(N). Neat.
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 1000002;
int n,k, sum[maxn],count_same[maxn];
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
	
	int st = 0, en = 0;
	long long res = 0;
	count_same[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		int v = sum[i] - k;
		if (v >= 0)
			res += count_same[v];
			
		++count_same[sum[i]];
	}

	cout << res << endl;

	return 0;
}
