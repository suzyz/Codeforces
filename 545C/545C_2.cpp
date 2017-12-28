// Greedy.
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 100010;

int n;
int x[maxn],h[maxn];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> h[i];

	// add a tree.
	x[n] = x[n-1] + h[n-1] + 1;

	int res = 1;
	int last_tree = 1; // 0 is not fell, 1 is fell left, 2 is fell right.
	for (int i = 1; i < n; ++i)
	{
		if ((last_tree < 2 && x[i] - h[i] > x[i-1])
			|| (last_tree == 2 && x[i] - h[i] > x[i-1] + h[i-1]))
		{
			++res;
			last_tree = 1;
			continue;
		}

		if (x[i] + h[i] < x[i+1])
		{
			++res;
			last_tree = 2;
			continue;
		}

		last_tree = 0;
	}

	cout << res << endl;
	return 0;
}


