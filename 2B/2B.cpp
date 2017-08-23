#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;
const int maxn = 1006;

int n,f[maxn][maxn][2];
bool g[maxn][maxn][2];

void print(int x,int y,int k)
{
	if(x<=1 && y<=1) return;

	if(g[x][y][k])
	{
		print(x,y-1,k);
		printf("R");
	}
	else
	{
		print(x-1,y,k);
		printf("D");	
	}
}

int main()
{
	freopen("2B.in","r",stdin);
	freopen("2B.out","w",stdout);

	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		f[0][i][0]=f[0][i][1]=f[i][0][0]=f[i][0][1]=INT_MAX;

	int tmp,xx=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&tmp);
			if(tmp==0)
				xx=i;
			else
			{
				while((tmp&1)==0){ tmp>>=1; f[i][j][0]++; }
				while(tmp%5==0){ tmp/=5; f[i][j][1]++; }
			}

			for(int k=0;k<2;k++)
			{
				if(f[i-1][j][k]<f[i][j-1][k])
					f[i][j][k]+=f[i-1][j][k];
				else
				{
					f[i][j][k]+=f[i][j-1][k];
					g[i][j][k]=true;
				}
			}
		}		
	}

	int ans;
	ans = f[n][n][0]<f[n][n][1] ? 0:1;

	if(xx>0 && f[n][n][ans]>1)
	{
		printf("1\n");
		for(int i=1;i<xx;i++) printf("D");
		for(int i=1;i<n;i++) printf("R");
		for(int i=xx;i<n;i++) printf("D");

		return 0;
	}
	printf("%d\n",f[n][n][ans]);

	print(n,n,ans);
	printf("\n");
	return 0;
}