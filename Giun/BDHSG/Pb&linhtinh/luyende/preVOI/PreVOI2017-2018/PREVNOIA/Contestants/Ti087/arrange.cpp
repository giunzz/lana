#include <bits/stdc++.h>
#define int long long
#define oo (LLONG_MAX/2)
using namespace std;

int f[2007][2007];
int a[2007],su[2007];

signed main()
{
	freopen("arrange.inp","r",stdin);
	freopen("arrange.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		su[i]=su[i-1]+a[i];
	}
	int k=su[n]%n;
	int t=(su[n]/n);
	int p=0;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			p=p+abs(su[i]-t*i);
		}
		cout << p << "\n";
		return 0;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			f[i][j]=oo;
		}
	}
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			f[i][j]=min(f[i][j],f[i-1][j]+abs(su[i]-t*i-j));
			if(j>0) f[i][j]=min(f[i][j],f[i-1][j-1]+abs(su[i]-t*i-j));
		}
	}
	cout << f[n][k] << endl;
	return 0;
}