#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli a, b, c, d, e, f ,g, h, sotest, dem, mini;
bool s[100009];
vector<lli> v, p;
void sang()
{
	b=1e5;
	c=sqrt(b);
	for(int i=2;i<=c;i++)
	{
		if(s[i]==0)
		{
			d=i+i;
			while(d<=b)
			{
				s[d]=1;
				d=d+i;
			}
		}
	}
	for(int i=2;i<=b;i++)
	{
		if(s[i]==0)
		{
			v.push_back(i);
		}
	}
}
lli gcd(lli b1, lli b2)
{
	lli m=b1, n=b2, r;
	while(n!=0)
	{
		r=m%n;
		m=n;
		n=r;
	}
	return m;
}
void quay(lli u)
{
	if(u==p.size())
	{
		if(c+d<mini)
		{
			mini=c+d;
			e=c;
			f=d;
		}
	}
	else
	{
		c=c*p[u];
		quay(u+1);
		c=c/p[u];
		d=d*p[u];
		quay(u+1);
		d=d/p[u];
	}
}
int main()
{
	freopen("MINSUM.INP","r",stdin);
	freopen("MINSUM.OUT","w",stdout);
	sang();
	cin>>sotest;
	for(int test=1;test<=sotest;test++)
	{
		cin>>a>>b;
		g=gcd(a, b);
		a=a/g;
		b=b/g;
		for(auto j: v)
		{
			dem=0;
			if(a%j==0)
			{
				while(a%j==0)
				{
					a=a/j;
					dem++;
				}
			}
			if(b%j==0)
			{
				while(b%j==0)
				{
					b=b/j;
					dem++;
				}
			}
			if(dem%2==1)
			{
				p.push_back(j);
			}
		}
		if(p.empty())
		{
			cout<<1<<" "<<1<<endl;
			continue;
		}
		c=1;
		d=1;
		mini=1e18+1;
		quay(0);
		cout<<e<<" "<<f<<endl;
		p.clear();
	}
}
