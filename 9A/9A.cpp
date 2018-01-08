#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int gcd(int a,int b)
{
	if (b == 0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int x,y,z;
	cin >> x >> y;
	z = 6 - max(x,y) + 1;
	if (z == 0)
		cout << "0/1" << endl;
	else
	{
		int k = gcd(z,6);
		cout << z/k << "/" << 6/k << endl;
	}

	return 0;
}
