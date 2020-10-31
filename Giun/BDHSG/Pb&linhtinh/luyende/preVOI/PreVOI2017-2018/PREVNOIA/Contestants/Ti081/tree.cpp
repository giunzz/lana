#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define y second
#define db(x) cerr << #x << " = " << x << endl;

using namespace std;

inline void read(int &x){register int c = getchar();x = 0; int neg = 0;for (;((c<48 || c>57) && c != '-') ;c = getchar());if(c=='-') {neg=1;c=getchar();}for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void read(long long &x){register int c = getchar();x = 0; int neg = 0;for (;((c<48 || c>57) && c != '-') ;c = getchar());if(c=='-') {neg=1;c=getchar();}for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
inline void writeln(long long x){char buffor[21];register int i=0;int neg=0; if (x<0) {neg=1; x= -x;}do{buffor[i++]=(x%10)+'0';x/=10;} while(x);i--;if (neg) putchar('-');while(i>=0) putchar(buffor[i--]);putchar('\n');}
inline void write(long long x){char buffor[21];register int i=0;int neg=0; if (x<0) {neg=1; x= -x;}do{buffor[i++]=(x%10)+'0';x/=10;} while(x);i--;if (neg) putchar('-');while(i>=0) putchar(buffor[i--]);putchar(' ');}

const long long oo = 1e18 + 7;
const int N = 5e3 + 7;

int n, u, v;
int child[N], a[N], C[N][10], g[N], able[N];
long long res;
long long f[N][N];
vector <int> adj[N];

void DFSInit(int u){
	child[u] = 1;
	for (int v: adj[u])
		if (!child[v]){
			C[u][++g[u]] = v;
			DFSInit(v);
			child[u] += child[v];
		}
}

void DFS(int u, int p){
	if (child[u] == 1)
		able[u] = 1;
	for (int v: adj[u])
		if (v != p){
			DFS(v, u);
			able[u] += able[v];
		}
}

long long F(int u, int need){
	if (f[u][need] != oo) return f[u][need];
	if (child[u] == 1){
		if (need > 1) return oo;
		return f[u][need] = abs(a[u] - need);
	}
	if (need > able[u])
		return oo;
	long long res = oo;
	if (g[u] == 1){
		res = F(C[u][1], need);
	}
	else
	if (g[u] == 2){
		for (int i = 0; i <= need; i++)
			res = min(res, F(C[u][1], i) + F(C[u][2], need - i));
	}
	res += abs(a[u] - need);
	return f[u][need] = res;
}	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("tree.inp", "r", stdin);
	freopen("tree.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i < n; i++){
		read(u); read(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFSInit(1);
	DFS(1, -1);
	res = oo;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			f[i][j] = oo;
	for (int i = 0; i <= able[1]; i++)
		res = min(res, F(1, i));
	writeln(res);
}