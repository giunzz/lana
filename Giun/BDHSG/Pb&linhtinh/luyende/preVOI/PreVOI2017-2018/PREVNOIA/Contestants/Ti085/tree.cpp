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

const int N=5005,INF=1e9;
int n,a[N];
vector<int> adj[N];
int sz[N],lc[N],rc[N];

void enter(){
	cin>>n;
	ff(i,1,n) cin>>a[i];
	ff(i,1,n-1){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}            

// dung cay
void dfs2(int u,int p){
	sz[u]=1;

	rep(i,0,SZ(adj[u])){
		int v=adj[u][i];
		if (v==p) continue;
		if (lc[u]==-1) lc[u]=v;
		else rc[u]=v;
		dfs2(v,u);
		sz[u]+=sz[v];
	}
}

// bay gio tinh DP

int dp[N][N];

inline void mini(int &x,int y){
	if (x>y) x=y;
}

void dfs(int u){
	if (lc[u]==-1 && rc[u]==-1) {
		// neu la nut la
		dp[u][0]=abs(a[u]); 
		dp[u][1]=abs(a[u]-1); 
	}
	else if (rc[u]==-1){
		// neu chi co mot con
		int v=lc[u];
		dfs(v);
		ff(i,0,sz[u]-1) mini(dp[u][i],dp[v][i]+abs(a[u]-i));
 	}
	else {
		int v1=lc[u],v2=rc[u];
		
		dfs(v1); 
		dfs(v2);

		ff(i,0,sz[v1]) if (dp[v1][i]!=INF){
			ff(j,0,sz[v2]){
				if (i+j>sz[u]) break;
				mini(dp[u][i+j],dp[v1][i]+dp[v2][j] + abs(a[u]-i-j));
			}
		}
	}
}


void process(){
	ff(i,1,n) {
		lc[i]=rc[i]=-1;
		ff(j,0,n+1) dp[i][j]=INF;
	}

	dfs2(1,-1);
	dfs(1);
	int ans=INF;

	// BAT DAU FOR TU 0!!!
	
	ff(i,0,n) {
		// db(i _ dp[1][i]);
		mini(ans,dp[1][i]);
	}
	
	// db(dp[3][2]);
	// db(dp[4][0]);

	cout<<ans<<endl;

}

int main(){
	// fast IO thi phai bo
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);

    enter();
    process();

    return 0;
}