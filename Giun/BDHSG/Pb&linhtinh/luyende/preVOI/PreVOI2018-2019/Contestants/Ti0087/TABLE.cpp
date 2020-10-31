#include <bits/stdc++.h>
#define int long long
#define MAXN 305
#define MOD 1000000007
#define sz(a) static_cast<long long>(a.size())
#define INF 2000000000000000000
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
int m,n,k,a[MAXN][MAXN],f[MAXN][MAXN],g[MAXN][MAXN];
bool ngang[MAXN][MAXN],doc[MAXN][MAXN];
int u,v,p,q;
void dietngang(int i,int j){
	return;
	while (j>=v && ngang[i][j]==true){
		ngang[i][j]=false; j--;
	}
}
void dietdoc(int i,int j){
	return;
	while (i>=u && doc[i][j]==true){
		doc[i][j]=false; i--;
	}
}
void g_tinh(){
	int i,j,l;
	for (i=u;i<=p;i++)
	for (j=v;j<=q;j++) g[i][j]=0;
		g[p][q]=a[p][q];
		for (i=p-1;i>=u;i--) g[i][q]=g[i+1][q]+a[i][q];
		for (i=q-1;i>=v;i--) g[p][i]=g[p][i+1]+a[p][i];
		for (i=p-1;i>=u;i--){
			for (j=q-1;j>=v;j--){
				g[i][j]=max(g[i][j+1],g[i+1][j])+a[i][j];
			}
		}
}
void f_tinh(){
	int i,j,l;
	for (i=u;i<=p;i++){
		for (j=v;j<=q;j++){
			f[i][j]=0; ngang[i][j]=true; doc[i][j]=true;
		}
	}
	f[u][v]=a[u][v];
	for (i=u+1;i<=p;i++){
		f[i][v]=f[i-1][v]+a[i][v];
	}
	for (i=v+1;i<=q;i++){
		f[u][i]=f[u][i-1]+a[u][i];
	}
	for (i=u+1;i<=p;i++){
		for (j=v+1;j<=q;j++){
			if (f[i-1][j]==f[i][j-1]){
				dietdoc(i-1,j); dietngang(i,j-1);
				f[i][j]=f[i-1][j]+a[i][j];
			}
			else if (f[i-1][j]>f[i][j-1]){
				dietngang(i,j-1); f[i][j]=f[i-1][j]+a[i][j];
			}
			else{
				dietdoc(i-1,j); f[i][j]=f[i][j-1]+a[i][j];
			}
		}
	}
	int ans=f[p][q],val1,val2,zolo;
	for (i=u;i<=p;i++){
		for (j=v;j<=q;j++){
			if (i==u&&j==v){
				;
			}
			else if (i==p&&j==q){
				;
			}
			else if (ngang[i][j]&&doc[i][j]){
				val1=INF; val2=INF; zolo=0;
				if (j==q) val1=INF;
				else if (i!=u) val1=f[i-1][j+1]+a[i][j+1];
				if (i==p) val2=INF;
				else if (j!=v) val2=f[i+1][j-1]+a[i+1][j];
				//cout<<i<<' '<<j<<' '<<val1<<' '<<val2<<'\n';
				if (val1!=INF) zolo=max(zolo,val1+g[i][j+1]-a[i][j+1]);
				if (val2!=INF) zolo=max(zolo,val2+g[i+1][j]-a[i+1][j]);
				ans=min(ans,zolo);
				
			}
		}
	}
	cout<<ans<<'\n';
}
main(){
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("inp.txt","r",stdin); //freopen("out.txt","w",stdout);
	freopen("TABLE.INP","r",stdin); freopen("TABLE.OUT","w",stdout);
	cin>>m>>n>>k;
	int i,j;
	for (i=1;i<=m;i++){
		for (j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for (i=1;i<=k;i++){
		cin>>u>>v>>p>>q;
		g_tinh();
		f_tinh();
	}
}
