#include <bits/stdc++.h>
using namespace std;
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, a, b) for(int i = (a), _b = (b); i < _b; ++i)
#define fd(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define SZ(x) ((int)(x).size())
#define db(x) cout << #x << " == " << x << endl
#define _ << ", " <<
#define X first
#define Y second
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define endl '\n'
#define pc putchar
#define gc getchar
#define bit(i) (1<<(i))
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
inline void read(int &x){register int c = gc();x = 0;int neg = 0;for (;((c<48 || c>57) && c != '-') ;c = gc());if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void write(int x){char buffor[12];register int i=0;int neg=0; if (x<0) {neg=1; x= -x;}do{buffor[i++]=(x%10)+'0';x/=10;} while(x);i--;if (neg) pc('-');while(i>=0) pc(buffor[i--]);}
inline void writeln(int x){write(x); pc('\n');}
inline void read(ll &x){register int c = gc();x = 0;int neg = 0;for (;((c<48 || c>57) && c != '-') ;c = gc());if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void write(ll x){char buffor[21];register int i=0;int neg=0; if (x<0) {neg=1; x= -x;}do{buffor[i++]=(x%10)+'0';x/=10;} while(x);i--;if (neg) pc('-');while(i>=0) pc(buffor[i--]);}
inline void writeln(ll x){write(x); pc('\n');}

const ll INF=1e18;
const int N=5e4+5,LOG=16;
int n,k,a[N];
vector<ii> adj[N];

void enter(){
	cin>>n>>k;
	ff(i,1,k) cin>>a[i];
	// a[i] la giao lo co khu vui choi thu i

	ff(i,1,n-1){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back(mp(v,w));
		adj[v].push_back(mp(u,w));
	}
}

int P[N][18],H[N];

ll d[N];

void dfs(int u,int p){
	rep(i,0,SZ(adj[u])){
		int v=adj[u][i].X,w=adj[u][i].Y;
		if (v==p) continue;
		d[v]=d[u]+w;
		H[v]=H[u]+1;
		P[v][0]=u;
		dfs(v,u);
	}
}

void build_lca(){
	for(int j=1;(1<<j)<=n;++j)
		ff(i,1,n) P[i][j]=P[P[i][j-1]][j-1];
}

int lca(int u,int v){
	if (H[u]<H[v]) swap(u,v);
	fd(i,LOG,0) if (H[u]-(1<<i)>=H[v]) u=P[u][i];
	if (u==v) return u;
	fd(i,LOG,0) if (P[u][i]!=P[v][i]){
		u=P[u][i];
		v=P[v][i];
	}
	return P[u][0];
}

void sub1(){
	ll ans=INF;
	
	int per[12];
	ff(i,1,k) per[i]=i;
	do {	
		ll cur=0;

		for(int i=1;i<=k;i+=2){
			int u=a[per[i]],v=a[per[i+1]];
			cur=max(cur,d[u]+d[v]-2*d[lca(u,v)]);
			if (cur>ans) break;
		}
		ans=min(ans,cur);
	} while (next_permutation(per+1,per+k+1));

	cout<<ans<<endl;
}
void process(){
	dfs(1,-1);
	build_lca();

	// if (k<=10){
		sub1();
	// }
}

int main(){
	// fast IO thi phai bo
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);

    enter();
    process();

    return 0;
}