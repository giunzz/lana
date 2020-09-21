#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct edge{
	int u,v,val;
	bool check;
}d[2003];
int n,m;
bool c[2003];
bool cmp(edge a,edge b)
{
	return a.val<b.val;
}
int timcanh()
{
	for (int i=2;i<=m;i++)
		if (!d[i].check && ( (c[d[i].u] && !c[d[i].v]) || (!c[d[i].u] && c[d[i].v])))
			return i;
}
int main()
{
	freopen("kruskal.inp","r",stdin);
	//freopen("kruskal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=m;i++)
		cin >> d[i].u >> d[i].v >> d[i].val;
	sort(d+1,d+1+m,cmp);
	c[d[1].u]=c[d[1].v]=1;
	d[1].check=1;
	int t=d[1].val;
	int dem=2;
	while (dem<n)
	{
		int k=timcanh();
		dem++;
		d[k].check=1;
        c[d[k].u]=c[d[k].v]=1;
        t+=d[k].val;
	}
	cout << t;
	return 0;
}
