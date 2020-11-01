#include<bits/stdc++.h>
#define mp make_pair
#define st first
#define nd second
using namespace std;
typedef long long int lli;
lli a, b, c, d, e, f, g, h, dd[50009], l, m, dd1[50009], p[50009];
vector<pair<lli, lli> > D[50009];
vector<lli> q[50009];
bool ok;
void Inp()
{
	cin>>a>>b;
	for(int i=1;i<=b;i++)
	{
		cin>>c;
		dd[c]=1;
	}
	for(int i=1;i<a;i++)
	{
		cin>>c>>d>>e;
		D[c].push_back(mp(d, e));
		D[d].push_back(mp(c, e));
	}
}
void DSF(lli u)
{
	if(ok==false)
	{
		return ;
	}
	if(dd[u]==1)
	{
		q[u].push_back(0);
	}
	for(auto v: D[u])
	{
		if(v.st!=p[u])
		{
			p[v.st]=u;
			DSF(v.st);
			if(!q[v.st].empty())
			{
				q[u].push_back(q[v.st].back()+v.nd);
				if(q[v.st].back()+v.nd>m)
				{
					ok=false;
					return ;
				}
			}
		}
	}
	sort(q[u].begin(), q[u].end());
	d=q[u].size()-1;
	for(int i=d;i>=0;i--)
	{
		dd1[i]=0;
	}
	e=d+1;
	for(int i=d;i>=0;i--)
	{
		if(dd1[i]!=0)
		{
			continue;
		}
		for(int j=i-1;j>=0;j--)
		{
			if(dd1[j]!=0)
			{
				continue;
			}
			if(q[u][i]+q[u][j]<=m)
			{
				dd1[i]=1;
				dd1[j]=1;
				e=e-2;
				break;
			}
		}
	}
	if(e>=2)
	{
		ok=false;
		return ;
	}
	for(int i=d;i>=0;i--)
	{
		if(dd1[i]==0)
		{
			f=q[u][i];
		}
	}
	q[u].clear();
	q[u].push_back(f);
	
}
void Solve()
{
	l=1, h=5e15+1;
	while(l<=h)
	{
		m=(l+h)/2;
		ok=true;
		DSF(1);
		if(ok)
		{
			h=m-1;
		}
		else
		{
			l=m+1;
		}
		for(int i=1;i<=a;i++)
		{
			q[i].clear();
		}
	}
	cout<<l<<endl;
}
int main()
{
	freopen("BUBBLETEA.INP","r",stdin);
	freopen("BUBBLETEA.OUT","w",stdout);
	Inp();
	Solve();
}
