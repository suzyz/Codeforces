#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 22;

int n,m;
int f[maxn][maxn][6];

int main()
{
	freopen("14E.in","r",stdin);
	freopen("14E.out","w",stdout);

	cin>>n>>m;
	m=2*m-1;

	if(n<m)
	{
		cout<<0<<endl;
		return 0;
	}

	for(int k=1;k<=4;k++)
		f[n][m][k]=1;

	for(int i=n-1;i>=2;i--)
		for(int j=m;j>=0;j--)
			for(int k=1;k<=4;k++)
			{
				if(j%2==0)
				{
					for(int p=k+1;p<=4;p++)
						f[i][j][k]+=f[i+1][j][p];
					for(int p=1;p<k;p++)
						f[i][j][k]+=f[i+1][j+1][p];
				}
				else
				{
					for(int p=k+1;p<=4;p++)
						f[i][j][k]+=f[i+1][j+1][p];
					for(int p=1;p<k;p++)
						f[i][j][k]+=f[i+1][j][p];					
				}
			}
	
	int ans=0;
	for(int k=2;k<=4;k++)
		ans+=(k-1)*f[2][0][k];
	
	cout<<ans<<endl;

	return 0;
}