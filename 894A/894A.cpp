#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string s;

int main()
{
	cin >> s;
	int q = 0, prefix_sum = 0, res = 0;
	for (int i = 0; i < s.length(); ++i)
		if (s[i] == 'Q')
		{
			res += prefix_sum;
			++q;
		}
		else
		if (s[i] == 'A')
			prefix_sum += q;
	
	cout << res << endl;

	return 0;
}

