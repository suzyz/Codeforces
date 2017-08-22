#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 1002;

int n,m;
char names[maxn][35];

int score[maxn][maxn];
int change[maxn],change_time[maxn][maxn];

int main()
{
	freopen("2A.in","r",stdin);
	freopen("2A.out","w",stdout);

	char tmp[35];

	cin>>n;
	m=0;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		int idx = 0,d;
		for(int j=1;j<=m;j++)
			if(strcmp(tmp,names[j])==0)
			{
				idx=j;
				break;
			}

		if(idx==0)
		{
			m++;
			idx=m;
			memcpy(names[m],tmp,sizeof(tmp));
		}
		cin>>d;

		change[idx]++;
		change_time[idx][change[idx]]=i;
		score[idx][change[idx]] = score[idx][change[idx]-1]+d;
	}

	int maxs = score[1][change[1]];
	for(int i=2;i<=m;i++)
		if(score[i][change[i]]>maxs)
			maxs = score[i][change[i]];

	int winner = 0;
	int min_time = n+1;
	for(int i=1;i<=m;i++)
		if(score[i][change[i]]==maxs)
		{
			for(int j=1;j<=change[i];j++)
			{
				if(change_time[i][j]>=min_time) break;

				if(score[i][j]>=maxs)
				{
					if(change_time[i][j]<min_time)
					{
						min_time=change_time[i][j];
						winner=i;
					}
					break;
				}
			}
		}

	cout<<names[winner]<<endl;
	return 0;
}