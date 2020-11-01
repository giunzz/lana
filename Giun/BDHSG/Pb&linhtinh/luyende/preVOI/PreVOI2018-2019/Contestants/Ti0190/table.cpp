#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define FRE freopen("table.inp","r",stdin),freopen("table.out","w",stdout)
using namespace std;
typedef long long ll;
const int maxn=300;
int m,n,k,a[maxn+1][maxn+1],u,v,p,q,ans,l[3],res=0,kq[10000],chot,e[3];
ll b[maxn+1][maxn+1];
bool kt[maxn+1][maxn+1];

void get(int u,int v,int p,int q,int pre)
{
	int chot=pre;
	if (u>p || v>q) return ;
	b[u][v]=max(b[u-1][v],b[u][v-1])+(ll)a[u][v];
	if (u==p && v==q) {
	if (ans<b[u][v]) ans=b[u][v],e[1]=l[1],e[2]=l[2];b[u][v]=0;return ;}
	if (chot<a[u][v]) {chot=a[u][v];l[1]=u;l[2]=v;}
	get(u+1,v,p,q,chot);
	get(u,v+1,p,q,chot);
	b[u][v]=0;
}

void get1(int u,int v,int p,int q)
{
	if (u>p || v>q) return ;
	if (kt[u][v]) return ;
	b[u][v]=max(max(b[u-1][v],b[u][v-1])+(ll)a[u][v],b[u][v]);
	if (u==p && v==q) {ans=max((ll)ans,b[u][v]);b[u][v]=0;return ;}
	get1(u+1,v,p,q);
	get1(u,v+1,p,q);
	b[u][v]=0;
}

int main()
{
	IOS;
	FRE;
	cin>>m>>n>>k;
	for (int i=1;i<=m;i++) 
	for (int j=1;j<=n;j++) cin>>a[i][j];
	while (k-->0)
	{
		chot=0;
		ans=0;res=0;
		cin>>u>>v>>p>>q;
		get(u,v,p,q,chot);
		ans=0;kt[e[1]][e[2]]=true;
		get1(u,v,p,q);
		kt[e[1]][e[2]]=false;
		cout<<ans<<"\n";
	}
}
