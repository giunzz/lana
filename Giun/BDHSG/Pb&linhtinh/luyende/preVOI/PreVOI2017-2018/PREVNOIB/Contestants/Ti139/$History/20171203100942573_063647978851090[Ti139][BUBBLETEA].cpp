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
#define taskname "BUBBLETEA"
int n, k;
bool sp[50001];
ll d[50001];
bool done[50001];
vector <pair <int, int> > g[50001];
vector <int> h[50001];
void dfs(int u){
    done[u]=1;
    for(pair <int, int> p: g[u]) if(!done[p.first]){
        h[u].pb(p.first);
        d[p.first]=p.second;
        dfs(p.first);
    }
}
ll s;
ll f[50001];
bool up[50001];
vector <ll> temp[50001];
ll best(vector <ll> &v){
    int l=0, r=v.size()-1, m, res=-1;
    while(l<=r){
        m=(l+r)/2;
        int i=0, j=v.size()-1;
        bool good=1;
        while(i<j){
            if(i==m) i++;
            if(j==m) j--;
            if(i>=j) break;
            if(v[i]+v[j]>s){
                good=0;
                break;
            }
            i++;
            j--;
        }
        if(good){
            res=v[m];
            r=m-1;
        }
        else l=m+1;
    }
    return res;
}
bool dp(int u){
    if(h[u].empty()){
        if(sp[u]){
            up[u]=1;
            f[u]=d[u];
        }
        else up[u]=0;
        return 1;
    }
    else{
        temp[u].clear();
        for(int v: h[u]){
            bool res=dp(v);
            if(!res) return 0;
            if(up[v]) temp[u].pb(f[v]);
        }
        if(sp[u]) temp[u].pb(0);
        sort(temp[u].begin(), temp[u].end());
        if(temp[u].size()%2==0){
            int i=0;
            int j=temp[u].size()-1;
            while(i<j){
                if(temp[u][i]+temp[u][j]>s) return 0;
                i++;
                j--;
            }
            up[u]=0;
            return 1;
        }
        f[u]=best(temp[u]);
        if(f[u]==-1) return 0;
        f[u]+=d[u];
        up[u]=1;
        return 1;
    }
}
bool check(ll m){
    s=m;
    return dp(1);
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    read(n);
    read(k);
    FOR(i, 1, k){
        int x;
        read(x);
        sp[x]=1;
    }
    FFOR(i, 1, n){
        int u, v, c;
        read(u);
        read(v);
        read(c);
        g[u].pb(mp(v, c));
        g[v].pb(mp(u, c));
    }
    dfs(1);
    ll l=1, r=1e14, m, ans=-1;
    while(l<=r){
        m=(l+r)/2;
        if(check(m)){
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    write(ans);
}