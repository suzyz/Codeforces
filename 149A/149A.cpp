#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int k;
int month[12];

int main()
{
	cin >> k;
	if (k == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < 12; ++i)
	{
		cin >> month[i];
		for (int j = i-1; j >= 0; --j)
			if (month[j] < month[j+1])
			{
				int tmp = month[j];
				month[j] = month[j+1];
				month[j+1] = tmp;
			}
			else
				break;
	}

	int sum = 0;
	for (int i = 0; i < 12; ++i)
	{
		sum += month[i];
		if (sum >= k)
		{
			cout << i+1 << endl;
			break;
		}
	}
	if (sum < k)
		cout << -1 << endl;

	return 0;
}
