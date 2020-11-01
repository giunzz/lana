#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "TREE"
const int inf=1000000000;
int n;
int a[5001];
int amax[5001];
vector <int> g[5001];
int f[5001][5001];
bool done[5001][5001];
void dfs(int u){
    if(g[u].empty()) amax[u]=1;
    else{
        for(int v: g[u]){
            dfs(v);
            amax[u]+=amax[v];
        }
    }
}
int F(int u, int k){
    if(done[u][k]) return f[u][k];
    done[u][k]=1;
    if(g[u].empty()) return f[u][k]=abs(a[u]-k);
    if(g[u].size()==1) return f[u][k]=abs(a[u]-k)+F(g[u][0], k);
    int lmin=max(0, k-amax[g[u][1]]);
    int lmax=min(k, amax[g[u][0]]);
    f[u][k]=inf;
    FOR(i, lmin, lmax) f[u][k]=min(f[u][k], F(g[u][0], i)+F(g[u][1], k-i));
    f[u][k]+=abs(a[u]-k);
    return f[u][k];
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    read(n);
    FOR(i, 1, n) read(a[i]);
    int x, y;
    FFOR(i, 1, n){
        read(x);
        read(y);
        g[x].pb(y);
    }
    dfs(1);
    int ans=inf;
    FOR(i, 0, amax[1]) ans=min(ans, F(1, i));
    write(ans);
}