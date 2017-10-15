#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;
const int maxn = 100010;

int n,diff[maxn];
char s[maxn];

int min_idx[maxn*2 + 10];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);

	int sum0 = 0, sum1 = 0;
	memset(min_idx,-1,sizeof(min_idx));

	min_idx[maxn] = 0;
	for (int i = 1; i<=n; ++i)
	{
		if (s[i] == '0')
			++sum0;
		else
			++sum1;

		diff[i] = sum0 - sum1;
		if (min_idx[diff[i] + maxn] == -1)
			min_idx[diff[i] + maxn] = i;
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int idx = min_idx[diff[i] + maxn];
		if (idx != -1)
			ans = max(ans,i - idx);
	}
	
	printf("%d\n",ans);
	return 0;
}