#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;

int main()
{
	int a,b,c,d;

	cin >> a >> b >> c >> d;
	double x = 1.0 * a / b;
	double y = 1.0 * c / d;

	double q = (1.0 - x) * (1.0 - y);
	double ans = x / (1.0 - q);

	printf("%.7f\n", ans);

	return 0;
}

