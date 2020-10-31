#include <bits/stdc++.h>
#define int long long
#define oo (LLONG_MAX/2)
using namespace std;

int dem[500007];
vector <int> v,vnone;
int ka,ans;
int tich,curl,curr;

void backtrack(int id)
{
	if(id==v.size()+1)
	{
		ans=min(ans,tich+(ka/tich));
		if(ans==tich+ka/tich) curl=tich,curr=ka/tich;
		return ;
	}
	backtrack(id+1);
	tich*=v[id-1];
	backtrack(id+1);
	tich/=v[id-1];
	return ;
}

void solve()
{
	int a,b,c,d;
	cin >> a >> b;
	c=a,d=b;
	for(int i=2;i<=sqrt(max(a,b));i++)
	{
		dem[i]=0;
	}
	for(int i=2;i<=sqrt(a);i++)
	{
		while(a%i==0) a/=i,dem[i]=(dem[i]+1)%2;
	}
	for(int i=2;i<=sqrt(b);i++)
	{
		while(b%i==0) b/=i,dem[i]=(dem[i]+1)%2;
	}
	v=vnone;
	for(int i=2;i<=sqrt(max(c,d));i++)
	{
		if(dem[i]) v.push_back(i);
	}
	if(a!=1)
	{
		if(b!=1)
		{
			if(a==b) ; else v.push_back(min(a,b)),v.push_back(max(a,b));
		}
		else v.push_back(a);
	}
	else v.push_back(b);
	ka=1;
	tich=1;
	for(int i=0;i<v.size();i++) ka=ka*v[i];
	ans=oo,curl=0,curr=0;
	backtrack(1);
	cout << curl << " " << curr << "\n";
	return ;
}

signed main()
{
	freopen("minsum.inp","r",stdin);
	freopen("minsum.out","w",stdout);
	int test;
	cin >> test;
	while(test--) solve();
	return 0;
}