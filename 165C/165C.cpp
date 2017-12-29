//O(N*logN)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 1000002;
int n,k, sum[maxn];
string s;

pair<int,int> binary_search(int st,int v)
{
	pair<int,int> res;
	int l = st, r = n;
	while (l < r)
	{
		int mid = l + ((r-l) >> 1);
		if (sum[mid] == v)
			r = mid;
		else
		if (sum[mid] < v)
			l = mid+1;
		else
			r = mid-1;
	}

	if (l <= n && sum[l] == v)
		res.first = l;
	else
	{
		res.first = res.second = n+1;
		return res;
	}

	r = n;
	while (l < r)
	{
		int mid = l + ((r-l) >> 1) + 1;
		if (sum[mid] == v)
			l = mid;
		else
		if (sum[mid] < v)
			l = mid+1;
		else
			r = mid-1;
	}

	res.second = r;
	return res;
}

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

	long long res = 0;
	for (int i = 1; i <= n; ++i)
	{
		pair<int,int> cur = binary_search(i,sum[i-1] + k);
		if (cur.first <= n)
			res += cur.second - cur.first + 1;
	}

	cout << res << endl;

	return 0;
}
