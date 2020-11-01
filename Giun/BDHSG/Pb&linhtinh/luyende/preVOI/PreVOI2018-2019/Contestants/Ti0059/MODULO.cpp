#include <bits/stdc++.h>
#define int long long
#define bit bit43208794
#define pb push_back
#define pf push_front

using namespace std;

int m10[20], a, b, n, k, ans=0, mod;
deque<int> dq;
void back(int i)
{
	if(i==n)
	{
		if(ans%mod==k)
		{
			while(dq.size())
			{
				cout<<dq.front();
				dq.pop_front();
			}
			exit(0);
		}
		return;
	}
	
	ans+=a*m10[i]%mod;
	dq.pf(a);
	back(i+1);
	dq.pop_front();
	ans-=a*m10[i]%mod;
	
	ans+=b*m10[i]%mod;
	dq.pf(b);
	back(i+1);
	dq.pop_front();
	ans-=b*m10[i]%mod;
}

signed main()
{
	freopen("MODULO.INP", "r", stdin);
	freopen("MODULO.OUT", "w", stdout);
	cin>>a>>b>>n>>k;
	if(a%2==0&&b%2==0&&k%2==1)
	{
		cout<<-1;
		return 0;
	}
	if(a%2==1&&b%2==1&&k%2==0)
	{
		cout<<-1;
		return 0;
	}
	mod=1;
	m10[0]=1;
	mod<<=(n);
	for(int i=1; i<=15; i++)
	{
		m10[i]=m10[i-1]*10;
		m10[i]%=mod;
	}
	back(0);
	cout<<-1;
}
