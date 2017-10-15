#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <climits>
#include <iomanip>
#include <algorithm>
#include <utility>
using namespace std;
const int maxn = 100010;

int n,k;
int d[maxn];
bool flag = true;

void unsort(int l,int r)
{
	if (k <= 0 || l >= r-1)
		return;
	k -= 2;

	int mid = (l+r)>>1;
	swap(d[mid-1],d[mid]);

	unsort(l,mid);
	unsort(mid,r);
}

int main()
{
	scanf("%d%d",&n,&k);

	if (k%2==0)
	{
		printf("-1\n");
		return 0;
	}

	for (int i = 1; i <= n; ++i)
		d[i] = i;

	--k;
	unsort(1,n+1);
	
	if (k == 0)
	{
		for (int i = 1; i < n; ++i)
			printf("%d ",d[i]);
		printf("%d\n",d[n]);
	}
	else
		printf("-1\n");

	return 0;
}