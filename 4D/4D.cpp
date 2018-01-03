#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 5002;

struct Envelope
{
	int w,h,idx;
} envelopes[maxn];

int n,total,card_w,card_h,f[maxn],pre[maxn];

bool cmp(const Envelope &a,const Envelope &b)
{
	if (a.w < b.w)
		return true;
	else
	if (a.w > b.w)
		return false;
	else
	if (a.h < b.h)
		return true;
	else
		return false;
}

int main()
{
	cin >> n >> card_w >> card_h;
	for (int i = 0; i < n; ++i)
	{
		Envelope tmp;
		cin >> tmp.w >> tmp.h;
		if (tmp.w <= card_w || tmp.h <= card_h)
			continue;

		tmp.idx = i+1;
		envelopes[total++] = tmp;
	}

	if (total == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	sort(envelopes,envelopes+total,cmp);

	int tail = 0;
	memset(pre,-1,sizeof(pre));
	for (int i = 0; i < total; ++i)
		f[i] = 1;

	for (int i = 0; i < total; ++i)
		for (int j = i+1; j < total; ++j)
			if (envelopes[i].w < envelopes[j].w && envelopes[i].h < envelopes[j].h && f[j] < f[i]+1)
			{
				f[j] = f[i]+1;
				pre[j] = i;

				if (f[j] > f[tail])
					tail = j;
			}
	
	cout << f[tail] << endl;
	vector<int> chain;
	while (tail >= 0)
	{
		chain.push_back(envelopes[tail].idx);
		tail = pre[tail];
	}

	for (int i = chain.size()-1; i >= 0; --i)
		cout << chain[i] << " ";
	cout << endl;

	return 0;
}

