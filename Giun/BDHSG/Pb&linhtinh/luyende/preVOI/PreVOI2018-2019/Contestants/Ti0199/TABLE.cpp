#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 101;
int m,n,k;
int a[MAX][MAX];
int f[MAX][MAX];
int u,v,p,q;
int x;
signed main()
{
	freopen("TABLE.INP","r",stdin);
	freopen("TABLE.OUT","w",stdout);
	
	int best = 1e17+9;
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for(int i=1;i<=k;i++)
	{
		cin>>u>>v>>p>>q;
		for(int j1=u;j1<=p;j1++)
		{
			for(int t1=v;t1<=q;t1++)
			{
				x = a[j1][t1];
				
				if ( (j1 - u)*(t1 - v) + (j1 - u) + (t1 - v) != 0 && (p - j1)*(q - t1) + (p - j1) + (q - t1) != 0 ) 
				{
					a[j1][t1] = -99999999999;
				}
				
				for(int j=u;j<=p;j++)
				{
					for(int t=v;t<=q;t++)
					{
						f[j][t] = max(f[j-1][t],f[j][t-1]) + a[j][t];
					}
				}
//				cout<<f[p][q]<<" "<<a[p][q]<<endl;

				best = min(best,f[p][q]);
				a[j1][t1] = x;
				
				for(int j=u;j<=p;j++)
				{
					for(int t=v;t<=q;t++)
					{
						f[j][t] = 0;
					}
				}
			}
		}
		cout<<best<<endl;
		best = 1e17+9;
	}
}
