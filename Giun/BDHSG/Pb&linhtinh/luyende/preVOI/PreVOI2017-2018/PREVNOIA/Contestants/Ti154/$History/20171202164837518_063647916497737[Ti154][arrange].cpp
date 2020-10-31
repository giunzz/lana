#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,b[N],bs[N],a[N];
ll sum,res;

void read()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("arrange.inp","r",stdin);
	freopen("arrange.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;++i) { cin>>bs[i]; sum+=bs[i]; }
}

void solve()
{
	res=1e12+7;
	if ((sum%n)==0)
	{
		for (int i=1;i<=n;++i) b[i]=sum/n;
		for (int i=1;i<=n;++i) a[i]=bs[i];
		ll tmp=0;
		for (int i=1;i<=n;++i)
		{
			if (a[i]<b[i])
				for (int j=i;j<=n;++j)
				{
					if (a[i]==b[i]) break;
					if (a[j]>b[j])
					{
						int d=min(abs(a[i]-b[i]),abs(a[j]-b[j]));
						a[i]+=d;
						a[j]-=d;
						tmp+=d*(j-i);
					}
				}
			if (a[i]>b[i])
				for (int j=i;j<=n;++j)
				{
					if (a[i]==b[i]) break;
					if (a[j]<b[j])
					{
						int d=min(abs(a[i]-b[i]),abs(a[j]-b[j]));
						a[i]-=d;
						a[j]+=d;
						tmp+=d*(j-i);
					}
				}
		}
		res=min(res,tmp);
	}
	else for (int x=0;x<=n;++x)
	{
		if ((sum+x)%n!=0) continue;
		int val=(sum+x)/n-1;
		for (int i=1;i<=x;++i) b[i]=val;
		for (int i=x+1;i<=n;++i) b[i]=val+1;
		do
		{
			for (int i=1;i<=n;++i) a[i]=bs[i];
			ll tmp=0;
			for (int i=1;i<=n;++i)
			{
				if (a[i]<b[i])
					for (int j=i;j<=n;++j)
					{
						if (a[i]==b[i]) break;
						if (a[j]>b[j])
						{
							int d=min(abs(a[i]-b[i]),abs(a[j]-b[j]));
							a[i]+=d;
							a[j]-=d;
							tmp+=d*(j-i);
						}
					}
				if (a[i]>b[i])
					for (int j=i;j<=n;++j)
					{
						if (a[i]==b[i]) break;
						if (a[j]<b[j])
						{
							int d=min(abs(a[i]-b[i]),abs(a[j]-b[j]));
							a[i]-=d;
							a[j]+=d;
							tmp+=d*(j-i);
						}
					}
			}
			res=min(res,tmp);
		} while (next_permutation(b+1,b+1+n));
	}
	cout<<res;
}

int main()
{
	read();
	solve();
}