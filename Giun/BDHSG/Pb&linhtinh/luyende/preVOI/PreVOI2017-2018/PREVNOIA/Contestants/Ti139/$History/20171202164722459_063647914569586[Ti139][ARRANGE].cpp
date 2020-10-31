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
#define taskname "ARRANGE"
int n;
int a[100001];
ll s[100001];
ll d[100001];
namespace dp{
    vector <ll> f[100001];
    const ll inf=1LL<<60;
    void solve(){
        int m=s[n]%n;
        FOR(i, 0, n) FOR(j, 0, m) f[i].pb(inf);
        ll x=s[n]/n;
        f[0][0]=0;
        FFOR(i, 0, n){
            FOR(j, 0, m) if(f[i][j]!=inf){
                ll sum=s[i+1]-(i*x+j);
                f[i+1][j]=min(f[i+1][j], f[i][j]+abs(sum-x));
                if(j<m) f[i+1][j+1]=min(f[i+1][j+1], f[i][j]+abs(sum-(x+1)));
            }
        }
        writeln(f[n][m]);
    }
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    read(n);
    FOR(i, 1, n){
        read(a[i]);
        s[i]=s[i-1]+a[i];
    }
    if(s[n]%n==0){
        ll x=s[n]/n;
        ll ans=0;
        FOR(i, 1, n) ans+=abs(s[i]-x*i);
        write(ans);
        return 0;
    }
    else dp::solve();
}