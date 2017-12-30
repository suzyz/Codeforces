#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n, minab,minba,maxab,maxba;
bool ab = false, ba = false, res = false;
string s;

int main()
{
	cin >> s;
	n = s.length();
	minba = minab = n;
	maxba =maxab = -1;
	for (int i = 1; i < n; ++i)
	{
		if (s[i-1] == 'A' && s[i] == 'B')
		{
			ab = true;
			minab = min(minab,i);
			maxab = max(maxab,i);
		}
		else
		if (s[i-1] == 'B' && s[i] == 'A')
		{
			ba = true;
			minba = min(minba,i);
			maxba = max(maxba,i);
		}
		else
			continue;

		if (ab && ba)
		{
			if (abs(minab - maxba) > 1 || abs(minba - maxab) > 1
			|| abs(minab - minba) > 1 || abs(maxba - maxab) > 1)
			{
				res = true;
				break;
			}
		}
	}

	if (res)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
