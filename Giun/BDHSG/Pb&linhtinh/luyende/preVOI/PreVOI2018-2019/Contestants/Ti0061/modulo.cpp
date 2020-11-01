#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define P pair<lli, lli>
using namespace std;
typedef long long int lli;
const lli N=64, M=(1<<20);
lli a, b, n, k, poww[N], mod, kk;
P trace[21][M+9];
void Pre()
{
	cin>>a>>b>>n>>k;
	kk=k;
	mod=(1<<n);
	poww[1]=1;
	for(int i=2;i<=n;i++)
	{
		poww[i]=(poww[i-1]*10)%mod;
	}
}
void Quay(lli l, lli r, lli k)
{
	if(l>r)
	{
		return ;
	}
	else
	{
		trace[l][(k+a*poww[l])%mod]=mp(k, a);
		Quay(l+1, r, (k+a*poww[l])%mod);
		trace[l][(k+b*poww[l])%mod]=mp(k, b);
		Quay(l+1, r, (k+b*poww[l])%mod);
	}
}
void Sub1()
{
	Quay(1, n, 0);
	if(trace[n][k].x==0&&trace[n][k].y==0)
	{
		cout<<-1;
		return ;
	}
	deque<lli> ans;
	for(int i=n;i>=1;i--)
	{
		ans.push_back(trace[i][k].y);
		k=trace[i][k].x;
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
	}
}
lli mul(lli p, lli q)
{
	if(q==0)
	{
		return 0;
	}
	if(q==1)
	{
		return p;
	}
	lli t=mul(p, q/2);
	if(q%2==0)
	{
		return (t+t)%mod;
	}
	else
	{
		return (t+t+p)%mod;
	}
}
void Sub2()
{
	lli l1=n/2+(n%2), l2=n/2;
	Quay(1, l1, 0);
	for(int i=0;i<mod;i++)
	{
		if(trace[l1][i].x==0&&trace[l1][i].y==0)
		{
			continue;
		}
		lli x=mul(i, poww[l2+1]), q=(kk-x+mod)%mod;
		if(trace[l2][q].x==0&&trace[l2][q].y==0)
		{
			continue;
		}
		deque<lli> ans;
		lli p=i;
		for(int i=l1;i>=1;i--)
		{
			ans.push_back(trace[i][p].y);
			p=trace[i][p].x;
		}
		for(int i=l2;i>=1;i--)
		{
			ans.push_back(trace[i][q].y);
			q=trace[i][q].x;
		}
		for(int i=0;i<n;i++)
		{
			cout<<ans[i];
		}
		return ;
	}
	cout<<-1;
}
int main()
{
	freopen("modulo.inp","r",stdin);
	freopen("modulo.out","w",stdout);
	Pre();
	if(n<=20)
	{
		Sub1();
		return 0;
	}
	if(n<=40)
	{
		Sub2();
		return 0;
	}
}
