// DP.
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 100010;

int n;
int x[maxn],h[maxn],f_stay[maxn],f_left[maxn],f_right[maxn];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> h[i];

	// add a tree.
	x[n] = x[n-1] + h[n-1] + 1;

	f_left[0] = 1;
	if (n == 1 || (n > 1 && x[1] > x[0] + h[0]))
		f_right[0] = 1;

	for (int i = 1; i < n; ++i)
	{
		f_stay[i] = max(f_stay[i-1], max(f_left[i-1],f_right[i-1]));

		if (x[i] - h[i] > x[i-1])
		{
			f_left[i] = max(f_stay[i-1],f_left[i-1]) + 1;
			if (x[i] - h[i] > x[i-1] + h[i-1])
				f_left[i] = max(f_left[i],f_right[i-1] + 1);
		}
		else
			f_left[i] = 0;

		if (x[i] + h[i] < x[i+1])
			f_right[i] = max(f_stay[i-1], max(f_left[i-1], f_right[i-1])) + 1;		
		else
			f_right[i] = 0;
	}

	cout << max(f_stay[n-1], max(f_left[n-1],f_right[n-1])) << endl;
	return 0;
}


