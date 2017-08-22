#include <iostream>
#include <cstdio>

using namespace std;
const int maxk = 510;

int n,m,kk;
int x[maxk],y[maxk];

struct Block
{
	int x,y;
} loc[maxk];

class SegmentTree2
{
	int l,r;
	bool mark;
	SegmentTree2() { mark = false; }
}

class SegmentTree1
{
public:
	int l,r;
	SegmentTree2 tree2[maxk<<1];
	//SegmentTree1() { tree2 = NULL; }
} tree1;


bool cover(int time)
{
	tree1.build
	for(int i=1;i<=kk;i++)
	{
		a = x[i]-time; if(a<1) a=1;
		b = x[i]+time; if(b>n) b=n;

		c = y[i]-time; if(c<1) c=1;
		d = y[i]+time; if(d>m) d=m;

		add(a,b,c,d);
	}

	if(tree1.query(1,n,1,m))
		return true;
	else
		return false;
}

bool cmp1(int a,int b)
{
	if(x[a]<x[b]) return true;
	return false;
}

bool cmp2(int a,int b)
{
	if(y[a]<y[b]) return true;
	return false;
}

int main()
{
	freopen("845E.in","r",stdin);
	freopen("845E.out","w",stdout);

	cin>>n>>m>>kk;
	for(int i=1;i<=kk;i++)
	{
		fin>>x[i]>>y[i];
		idx1[i]=idx2[i]=i;
	}
	
	sort(idx1+1,idx1+kk+1,cmp1);
	sort(idx2+1,idx2+kk+1,cmp2);

	for(int i=1;i<=kk;i++)
	{
		if(i==1 || x[idx1[i]]!=x[idx1[i-1]])
		{
			num1++;
			
		}
	}

	int l,r,mid;

	l=0;
	r=n>m ? n:m;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(cover(mid))
			r=mid;
		else
			l=mid+1;
	}
	
	cout<<l<<endl;

	return 0;
}