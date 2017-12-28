#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxm = 52;

int n,m;
int difficulty[maxm];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> difficulty[i];
	
	sort(difficulty,difficulty + m);

	int res = INT_MAX;
	for (int i = 0; i+n-1 < m; ++i)
		res = min(res,difficulty[i+n-1] - difficulty[i]);
	
	cout << res << endl;

	return 0;
}
