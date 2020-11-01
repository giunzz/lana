#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct Node
{
	lli x, y, z, w;
};
Node m[2009], n[16], s;
bool sub1=true, sub2=true;
vector<lli> p[16];
lli a, b, c, d, e, f, g, h, kq, x[17], tim[5009]={}, cnt=1;
void Inp()
{
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++)
	{
		cin>>m[i].x>>m[i].y>>m[i].z>>m[i].w;
		if(m[i].y!=0||m[i].z!=0)
		{
			
			sub1=false;
		}
		if(m[i].z!=0)
		{
			sub2=false;
		}
	}
	for(int j=1;j<=b;j++)
	{
		cin>>n[j].x>>n[j].y>>n[j].z>>n[j].w;
		if(n[j].y!=0||n[j].z!=0)
		{
			
			sub1=false;
		}
		if(n[j].z!=0)
		{
			sub2=false;
		}
	}
	cin>>s.x>>s.y>>s.z;
	if(s.y!=0||s.z!=0)
	{
		sub1=false;
	}
	if(s.z!=0)
	{
		sub2=false;
	}
}
void quay1(lli u)
{
	if(u==b+1)
	{
		for(int i=1;i<=b;i++)
		{
			if(x[i]==1)
			{
				for(auto j: p[i])
				{
					tim[j]=cnt;
				}
			}
		}
		lli dem=0;
		for(int i=1;i<=a;i++)
		{
			if(tim[i]==cnt)
			{
				dem++;
			}
		}
		if(dem<=c)
		{
			kq=max(kq, d);
		}
		cnt++;
	}
	else
	{
		x[u]=0;
		quay1(u+1);
		x[u]=1;
		d=d+n[u].w;
		quay1(u+1);
		d=d-n[u].w;
		x[u]=0;
	}
}
void Sub1()
{
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=a;j++)
		{
			d=m[j].x+m[j].w;
			e=m[j].x-m[j].w;
			if(!((n[i].x<e&&s.x<e)||(n[i].x>d&&s.x>d)||(n[i].x>=e&&s.x>=e&&n[i].x<=d&&s.x<=d)))
			{
				p[i].push_back(j);
			}
		}
	}
	kq=0;
	d=0;
	quay1(1);
	cout<<kq;
}
int main()
{
	freopen("TEAWORLD.INP","r",stdin);
	freopen("TEAWORLD.OUT","w",stdout);
	Inp();
	if(sub1)
	{
		Sub1();
	}
}
