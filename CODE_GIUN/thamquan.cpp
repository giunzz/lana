#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const long maxn = 1e4+7;
const long oo = 1e9;
long m, n,s,t, G[maxn][maxn], L[maxn], Tr[maxn]={0};
bool C[maxn] = {false};
void Init(){
	for (int i=1;i<=n;i++) L[i]=oo;
	L[s]=0;
}
int MinLab(){
	int v = 0;
	long ml = oo;
	for (int i=1;i<=n;i++){
		if (!C[i] && L[i]< ml){
			ml = L[i];
			v=i;
		}
	}
	return v;
}
void Dijsktra(int x){
	int u,v;
	do {
		u = MinLab();
		if (u==0) break;
		C[u] = true;
		for (v=1; v<=n; v++){
			if (G[u][v] != oo){
				if (L[v]>L[u]+G[u][v]){
					L[v] = L[u]+G[u][v];
					Tr[v] = u;
				}
			}
		} 
	} while (u != x);
}
long ans ;
void Trace(int u)
{
	if (Tr[u]==0) return;
	Trace(Tr[u]);
    ans = min(ans,G[u][Tr[u]]);
}
int main(){
	freopen("thamquan.INP","r",stdin);
	freopen("thamquan.OUT","w",stdout);
	cin >> n >> m >>  t;
	int u,v, val;
    s = 1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			G[i][j]=oo;
		}
	}
	for (int i=1;i<=m;i++){
		cin >> u >> v >> val;
		G[u][v] = G[v][u] = val;
	}
	Init();
	Dijsktra(n);
    int x;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> x ;
        ans = INT8_MAX;
        Trace(x);
        cout <<  ans << endl ;
    }
}