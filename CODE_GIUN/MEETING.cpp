#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const long maxn = 2005;
const long oo = 1e9;
long m, n,s,t, G[maxn][maxn], L[maxn], Tr[maxn]={0};
bool C[maxn] = {false}, vn = false;
void Init()
{
	for (int i=1;i<=n;i++) L[i]=oo;
	L[s]=0;
}
int MinLab()
{
	int v = 0;
	long ml = oo;
	for (int i=1;i<=n;i++)
		if (!C[i] && L[i]< ml) ml = L[i], v=i;
	return v;
}
void Dijsktra()
{
	int u,v;
	do {
		u = MinLab();
		if (u==0) break;
		C[u] = true;
		for (v=1; v<=n; v++)
		{
			if (G[u][v] != oo)
			{
				if (L[v]>L[u]+G[u][v])
				{
					L[v] = L[u]+G[u][v];
					Tr[v] = u;
				}
			}
		} 
	} while (u != t);
}
void Trace(int u)
{
	if (Tr[u]==0) 
	{
		cout << u;
		return;
	}
	Trace(Tr[u]);
	cout << " " << u;
}
int main()
{
	freopen("dijsktra.INP","r",stdin);
	freopen("dijsktra.OUT","w",stdout);
	cin >> n >> m >> s >> t;
	int u,v, val;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) G[i][j]=oo;

	for (int i=1;i<=m;i++)
	{
		cin >> u >> v >> val >> x ;
		G[u][v] = G[v][u] = val;
	}
	Init();
	Dijsktra();
	if (vn) cout << -1;
	else {
		cout << L[t] << endl;
		Trace(t);
	}
}