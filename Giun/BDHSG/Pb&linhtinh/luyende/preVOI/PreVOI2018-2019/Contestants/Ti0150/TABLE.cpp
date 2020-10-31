#include<bits/stdc++.h>

using namespace std;
long long f[305][305],n,m,k,z,y,x,t,a[305][305],trc[10005],base=1000;
long long F(long long i,long long j)
{
	if(f[i][j]!=-1) return f[i][j];
	else if(i==x&&j==y)
	{
		f[i][j]=a[i][j];
		return f[i][j];
	}
	else 
	{
		long long res=0;
		if(i-1>=x)
		{
			res=max(res,F(i-1,j));
		}
		if(j-1>=y)
		{
			res=max(res,F(i,j-1));
		}
		f[i][j]=res+a[i][j];
		return f[i][j];
	}
}
main()
{
	freopen("TABLE.inp","r",stdin);
	freopen("TABLE.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	if(n<=100&&m<=100)
	{
		while(k--)
		{
			cin>>x>>y>>z>>t;
			long long kq=1e9;
			long long dau=a[x][y];
			long long cuoi=a[z][t];
			for(int i=x;i<=z;i++)
			{
				for(int j=y;j<=t;j++)
				{
					memset(f,-1,sizeof(f));
					long long qw=a[i][j];
					a[i][j]=0;
					a[x][y]=dau;
					a[z][t]=cuoi;
					kq=min(kq,F(z,t));
					a[i][j]=qw;
				}
			}
			cout<<kq<<'\n';
		}
	}
	else
	{
		while(k--)
		{
			cin>>x>>y>>z>>t;
			long long kq=1e9;
			long long dau=a[x][y];
			long long cuoi=a[z][t];
			memset(f,-1,sizeof(f));
			memset(trc,0,sizeof(trc));
			F(z,t);
			long long asd=trc[z*base+t];
			while(asd!=0)
			{
				long long i=asd/base;
				long long j=asd%base;
				memset(f,-1,sizeof(f));
				long long qw=a[i][j];
				a[i][j]=0;
				a[x][y]=dau;
				a[z][t]=cuoi;
				kq=min(kq,F(z,t));
				a[i][j]=qw;
				asd=trc[asd];
				cout<<i<<" "<<j<<'\n';
			}
			cout<<kq<<'\n';
		}
	}
}

