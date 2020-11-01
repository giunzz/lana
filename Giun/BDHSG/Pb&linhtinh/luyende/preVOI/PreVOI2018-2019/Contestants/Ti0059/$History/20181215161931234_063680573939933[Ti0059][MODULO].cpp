#include <bits/stdc++.h>
#define int long long
#define bit bit43208794
using namespace std;

int m10[20], a, b, n, k, ans=0, mod;

void back(int i)
{
	if(i==n)
	{
		if(ans%mod==k)
		{
			cout<<ans;
			exit(0);
		}
		return;
	}
	
	ans+=a*m10[i];
	back(i+1);
	ans-=a*m10[i];
	
	ans+=b*m10[i];
	back(i+1);
	ans-=b*m10[i];
}

signed main()
{
	freopen("MODULO.INP", "w", stdin);
	freopen("MODULO.OUT", "r", stdout);
	cin>>a>>b>>n>>k;
	mod=1;
	m10[0]=1;
	mod<<=(n);
	for(int i=1; i<=15; i++)
	{
		m10[i]=m10[i-1]*10;
	}
	back(0);
	cout<<-1;
}
