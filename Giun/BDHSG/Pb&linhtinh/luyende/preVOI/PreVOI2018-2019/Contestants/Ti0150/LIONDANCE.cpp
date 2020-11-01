#include<bits/stdc++.h>

using namespace std;
long long n,k,l[4005],r[4005],f[4005][4005],max_[4005][4005];
queue<long long> q;
long long sd[4005];
main()
{
	freopen("LIONDANCE.inp","r",stdin);
	freopen("LIONDANCE.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%lld",&l[i]);
	for(int j=1;j<=n;j++) scanf("%lld",&r[j]);
	l[n+1]=1e18;
	r[n+1]=1e18;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(l[i]==r[j])
			{
				f[i][j]=f[i-1][j-1]+1;
			} 
			else f[i][j]=max(f[i-1][j],f[i][j-1]);
		}
	}
	cout<<f[n][n]<<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(l[i]==r[j]&&(i!=n&&j!=n))
			{
				sd[f[i][j]]=max(sd[f[i][j]],l[i]);
			}
		}
	}
	if(l[n]==r[n]) sd[f[n][n]]=max(sd[f[n][n]],l[n]);
	for(int i=1;i<=f[n][n];i++) cout<<sd[i]<<" ";
}
