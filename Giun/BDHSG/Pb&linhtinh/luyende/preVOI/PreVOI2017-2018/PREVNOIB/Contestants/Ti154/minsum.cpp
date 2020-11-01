#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,minv,r1,r2;
int t;
bool vis[1003][1003];

void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("minsum.inp","r",stdin);
	freopen("minsum.out","w",stdout);
}

void trai(int a, int b)
{
	if (vis[a][b] || vis[b][a]) return;
	vis[a][b]=vis[b][a]=true;
	if (a+b<minv) { r1=a;r2=b;minv=a+b; }
	int x=__gcd(a,b);
	if (x!=1) trai(a/x,b/x);
	for (int i=2;i<=trunc(sqrt(a));++i) if ((a%i)==0) trai(a/i,b*i);
	for (int i=2;i<=trunc(sqrt(b));++i) if ((b%i)==0) trai(a*i,b/i);
}

void tritue()
{
	ll x=__gcd(a,b);
	a=a/x;b=b/x;
	ll tmp=1, tmp2=1;
	for (int i=2;i<=trunc(sqrt(a));++i)
		if (a%i==0 && a%(i*i)==0) tmp=tmp*i;
	for (int i=2;i<=trunc(sqrt(b));++i)
		if (b%i==0 && b%(i*i)==0) tmp=tmp*i;
	a=a/(tmp*tmp);
	b=b/(tmp2*tmp2);
	if (a<=100 && b<=100)
		trai(a,b);
	else r1=a,r2=b;
}

void solve()
{
	cin>>t;
	while (t--)
	{
		cin>>a>>b;
		minv=2e9;
		if (a<=50 && b<=50)
		{
			memset(vis,false,sizeof(vis));
			trai(a,b);
			//cout<<r1<<' '<<r2<<'\n';
		}
		else tritue();
		cout<<r1<<' '<<r2<<'\n';
	}
}

int main()
{
	init();
	solve();
}