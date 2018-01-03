#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 150002;

int n,k,sum[maxn];

int main()
{
	cin >> n >> k;
	int best = 0, min_sum = INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		int h;
		cin >> h;
		sum[i] = sum[i-1] + h;
		if (i >= k)
			if (min_sum > sum[i] - sum[i-k])
			{
				min_sum = sum[i] - sum[i-k];
				best = i-k+1;
			}
	}
	
	cout << best << endl;

	return 0;
}


