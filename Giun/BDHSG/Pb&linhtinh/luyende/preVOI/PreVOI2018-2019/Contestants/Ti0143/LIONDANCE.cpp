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
#define taskname "LIONDANCE"
#define up fail
int k, n, m;
int d;
int _a[4001];
int _b[4001];
int a[4001];
int b[4001];
int next_a[4001][4001];
int next_b[4001][4001];
int value[4001];
int low[4001];
int high[4001];
vector <int> g[4001];
set <int> up;
set <int> dw;
map <int, int> M;
bool done[4001][4001];
int f[4001][4001];
int F(int u, int v){///u, v is the last chosen couple
    if(done[u][v]) return f[u][v];
    done[u][v]=1;
//    FOR(x, low[a[u]], high[a[u]]) if(next_a[u][x]&&next_b[v][x]) f[u][v]=max(f[u][v], F(next_a[u][x], next_b[u][x]));
    for(int x: g[u]) if(next_a[u][x]&&next_b[v][x]) f[u][v]=max(f[u][v], F(next_a[u][x], next_b[u][x]));
    f[u][v]++;
    return f[u][v];
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #else
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    #endif // Uiharu
    read(k);
    read(d);
    FOR(i, 1, k){
        read(_a[i]);
        up.insert(_a[i]);
    }
    FOR(i, 1, k){
        read(_b[i]);
        dw.insert(_b[i]);
    }
    for(int x: up) if(dw.find(x)!=dw.end()){
        M[x]=M.size();
        value[M[x]]=x;
    }
    FOR(i, 1, k) if(M.find(_a[i])!=M.end()){
        n++;
        a[n]=M[_a[i]];
    }
    FOR(i, 1, k) if(M.find(_b[i])!=M.end()){
        m++;
        b[m]=M[_b[i]];
    }
    k=M.size();
    FOR(i, 1, k){
        low[i]=high[i]=i;
        while((low[i]>1)&&(value[i]-value[low[i]-1]<=d)) low[i]--;
        while((high[i]<k)&&(value[high[i]+1]-value[i]<=d)) high[i]++;
    }
    DFOR(i, n-1, 0){
        FOR(j, 1, k) next_a[i][j]=next_a[i+1][j];
        next_a[i][a[i+1]]=i+1;
    }
    DFOR(i, m-1, 0){
        FOR(j, 1, k) next_b[i][j]=next_b[i+1][j];
        next_b[i][b[i+1]]=i+1;
    }
    FOR(i, 1, n) DFOR(j, high[a[i]], low[a[i]]) if(next_a[i][j]) g[i].pb(j);
    int ans=0;
    FOR(i, 1, k) ans=max(ans, F(next_a[0][i], next_b[0][i]));
    writeln(ans);
    int u=0, v=0;
    while(ans>0){
        DFOR(i, k, 1) if(next_a[u][i]&&next_b[v][i]) if(F(next_a[u][i], next_b[v][i])==ans){
            ans--;
            u=next_a[u][i];
            v=next_b[v][i];
            write(value[i]);
            putchar(' ');
            break;
        }
    }
}