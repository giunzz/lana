#include <bits/stdc++.h>
using namespace std;

int a,b,n,k;
map<unsigned long long,bool> vis[100];

void bit()
{
	for(int i=0;i<(1<<n);i++)
	{
		unsigned long long r=0;
		for(int j=0;j<n;j++) if((i>>j)&1) r=(r*10+a)%(1<<n); else 
		r=(r*10+b)%(1<<n);
		if(r==k)
		{
			for(int j=0;j<n;j++) if((i>>j)&1) cout<<a; else cout<<b;
			return;
		}
	}
	cout<<-1;
	return;
}

void bfs()
{
	queue<tuple<int,int,string> > q;
	q.push(make_tuple(0,0,""));
	while(q.size())
	{
		string tmp;
		int i; unsigned long long r;
		tie(i,r,tmp)=q.front(); q.pop();
		if(i==n && r==k)
		{
			cout<<tmp;
			return;
		}
		if(i<n && vis[i+1].find((r*10+a)%(1<<n))==vis[i+1].end()) 
		{
			q.push(make_tuple(i+1,(r*10+a)%(1<<n),tmp+char(a+48)));
			vis[i+1][(r*10+a)%(1<<n)]=1;
		}
		if(i<n && vis[i+1].find((r*10+b)%(1<<n))==vis[i+1].end()) 
		{
			q.push(make_tuple(i+1,(r*10+b)%(1<<n),tmp+char(b+48)));
			vis[i+1][(r*10+b)%(1<<n)]=1;
		}
	}
	cout<<-1;
	return ;
}

int main()
{
	freopen("modulo.inp","r",stdin);
	freopen("modulo.out","w",stdout);	
	cin>>a>>b>>n>>k;
	if(n<=22) bit(); else bfs();
}