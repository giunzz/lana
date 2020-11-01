#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+6;
int n,k,a[N],ds[N];
ll sum[N],res;

void read()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("gifts.inp","r",stdin);
	freopen("gifts.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
}

void trau()
{
	res=sum[n];
	for (int i=1;i<=n-k+1;++i)
	{
		ll tmp=0;
		for (int j=1;j<=i-k+1;++j)
			tmp=max(tmp,sum[j+k-1]-sum[j-1]);
		for (int j=i+1;j<=n-k+1;++j)
			tmp=max(tmp,sum[j+k-1]-sum[j-1]);
		res=min(res,tmp);
	}
	cout<<res;
}

void tritue()
{
	res=sum[n];
	ll d=-sum[n],c=sum[n];
	while (d<=c)
	{
		ll g=(d+c)/2;
		int dem=0;
		for (int i=1;i<=n-k+1;++i)
			if (sum[i+k-1]-sum[i-1]>=g) ds[++dem]=i;
		int tmp=1,be=ds[1];
		for (int i=2;i<=dem;++i)
			if (ds[i]>be+k-1)
			{
				be=ds[i];
				tmp++;
			}
		if (tmp<=2)
		{
			res=min(res,g);
			c=g-1;
		}
		else d=g+1;
	}
	cout<<res;
}

int main()
{
	read();
	if (n<=5000) trau();
		else tritue();
}