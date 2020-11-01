#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long;
using ld=long double;
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
#define taskname "TABLE"
int n, m, k;
ll a[301][301];
ll f[301][301];
ll g[301][301];
void dp(int u, int v, int p, int q){
    FOR(i, u, p) FOR(j, v, q) f[i][j]=0;
    FOR(i, u, p) FOR(j, v, q) g[i][j]=0;
    DFOR(i, p, u) DFOR(j, q, v){
        f[i][j]+=a[i][j];
        if(i>u) f[i-1][j]=max(f[i-1][j], f[i][j]);
        if(j>v) f[i][j-1]=max(f[i][j-1], f[i][j]);
    }
    FOR(i, u, p) FOR(j, v, q){
        g[i][j]+=a[i][j];
        if(i<p) g[i+1][j]=max(g[i+1][j], g[i][j]);
        if(j<q) g[i][j+1]=max(g[i][j+1], g[i][j]);
    }
}
void solve(){
    int u, v, p, q;
    read(u);
    read(v);
    read(p);
    read(q);
    dp(u, v, p, q);
    ll ans=g[p][q];
    FFOR(k, u+v+1, p+q){
        vector <ll> all;
        FOR(x, u, p){
            int y=k-x;
            if(y>q||y<v) continue;
            all.pb(g[x][y]+f[x][y]-a[x][y]);
        }
        FFOR(i, 1, all.size()) if(all[i]<all[i-1]) swap(all[i], all[i-1]);
        all.pop_back();
        ans=min(ans, *max_element(all.begin(), all.end()));
    }
    writeln(ans);
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #else
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    #endif // Uiharu
    read(n);
    read(m);
    read(k);
    FOR(i, 1, n) FOR(j, 1, m) read(a[i][j]);
    FOR(i, 1, k) solve();
}