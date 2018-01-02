#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 102;
const int mo = 1e9 + 7;

int n,kk,d,res;
int f[maxn][maxn];

int dfs(int sum,int max_num)
{
	if (sum > n)
		return 0;
	if (f[sum][max_num] >= 0)
		return f[sum][max_num];

	if (sum == n)
	{
		f[sum][max_num] = max_num >= d ? 1:0;

		return f[sum][max_num];
	}

	f[sum][max_num] = 0;
	for (int i = 1; i <= kk; ++i)
	{
		f[sum][max_num] += dfs(sum+i,max(max_num,i));
		if (f[sum][max_num] >= mo)
			f[sum][max_num] -= mo;
	}
}

int main()
{
	cin >> n >> kk >> d;

	memset(f,-1,sizeof(f));
	dfs(0,0);

	cout << f[0][0] << endl;

	return 0;
}
