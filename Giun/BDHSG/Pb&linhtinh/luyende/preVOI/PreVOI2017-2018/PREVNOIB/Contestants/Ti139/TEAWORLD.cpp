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
#define taskname "TEAWORLD"
#define sqr(x) ((x)*(x))
int m, n, k;
vector <ll> v[15];
namespace real{
    typedef long double num;
    struct point{
        num x, y, z, r;
    } g[2000], s[15], A;
    num sqdist(point A, point B){
        return sqr(A.x-B.x)+sqr(A.y-B.y)+sqr(A.z-B.z);
    }
    num ans=0;
    bool block(point A, point B, point C){///distance from C to segment line AB<=G.r
        num AC=sqdist(A, C);
        num BC=sqdist(B, C);
        num AB=sqdist(A, B);
        if(max(AC, BC)<=sqr(C.r)) return 0;
        if(AC+AB<=BC||BC+AB<=AC) return min(AC, BC)<=sqr(C.r);
        AB=sqrt(AB);
        BC=sqrt(BC);
        AC=sqrt(AC);
        num p=(AB+BC+AC)/2;
        num S=p*(p-AB)*(p-BC)*(p-AC);
        return S*4<=sqr(C.r)*sqdist(A, B);
    }
    void update(int state){
        vector <ll> a;
        FFOR(i, 0, v[0].size()) a.pb(0);
        num res=0;
        FFOR(i, 0, n) if((state>>i)&1){
            res+=s[i].r;
            FFOR(j, 0, v[0].size()) a[j]|=v[i][j];
        }
        int cnt=0;
        FFOR(j, 0, v[0].size()) cnt+=__builtin_popcountll(a[j]);
        if(cnt<=k) ans=max(ans, res);
    }
    void solve(){
        FFOR(i, 0, n){
            ll now=0;
            FFOR(j, 0, m){
                if(j>0&&j%50==0){
                    v[i].pb(now);
                    now=0;
                }
                if(block(A, s[i], g[j])) now|=1<<(j%50);
            }
            v[i].pb(now);
        }
        int smax=1<<n;
        FFOR(i, 0, smax) update(i);
        if(ans==round(ans)) cout<<(ll)ans;
        else cout<<setprecision(10)<<fixed<<ans;
    }
    bool check_integer(){
        FFOR(i, 0, m) if(round(g[i].x)!=g[i].x) return 0;
        FFOR(i, 0, m) if(round(g[i].y)!=g[i].y) return 0;
        FFOR(i, 0, m) if(round(g[i].z)!=g[i].z) return 0;
        FFOR(i, 0, m) if(round(g[i].r)!=g[i].r) return 0;
        FFOR(i, 0, n) if(round(s[i].x)!=s[i].x) return 0;
        FFOR(i, 0, n) if(round(s[i].y)!=s[i].y) return 0;
        FFOR(i, 0, n) if(round(s[i].z)!=s[i].z) return 0;
        FFOR(i, 0, n) if(round(s[i].r)!=s[i].r) return 0;
        if(round(A.x)!=A.x) return 0;
        if(round(A.y)!=A.y) return 0;
        if(round(A.z)!=A.z) return 0;
        return 1;
    }
};
namespace integer{
    typedef long long num;
    struct point{
        num x, y, z, r;
    } g[2000], s[15], A;
    num sqdist(point A, point B){
        return sqr(A.x-B.x)+sqr(A.y-B.y)+sqr(A.z-B.z);
    }
    bool block(point A, point B, point C){///distance from C to segment line AB<=G.r
        num AC=sqdist(A, C);
        num BC=sqdist(B, C);
        num AB=sqdist(A, B);
        if(max(AC, BC)<=sqr(C.r)) return 0;
        if(AC+AB<=BC||BC+AB<=AC) return min(AC, BC)<=sqr(C.r);
        ld dAB=sqrt((ld)AB);
        ld dBC=sqrt((ld)BC);
        ld dAC=sqrt((ld)AC);
        ld p=(dAB+dBC+dAC)/2;
        ld S=p*(p-dAB)*(p-dBC)*(p-dAC);
        return S*4<=sqr(C.r)*AB;
    }
    num ans=0;
    void update(int state){
        vector <ll> a;
        FFOR(i, 0, v[0].size()) a.pb(0);
        num res=0;
        FFOR(i, 0, n) if((state>>i)&1){
            res+=s[i].r;
            FFOR(j, 0, v[0].size()) a[j]|=v[i][j];
        }
        int cnt=0;
        FFOR(j, 0, v[0].size()) cnt+=__builtin_popcountll(a[j]);
        if(cnt<=k) ans=max(ans, res);
    }
    void solve(){
        FFOR(i, 0, n){
            ll now=0;
            FFOR(j, 0, m){
                if(j>0&&j%50==0){
                    v[i].pb(now);
                    now=0;
                }
                if(block(A, s[i], g[j])) now|=1<<(j%50);
            }
            v[i].pb(now);
        }
        int smax=1<<n;
        FFOR(i, 0, smax) update(i);
        cout<<ans;
    }
};
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    cin>>m>>n>>k;
    FFOR(i, 0, m) cin>>real::g[i].x>>real::g[i].y>>real::g[i].z>>real::g[i].r;
    FFOR(i, 0, n) cin>>real::s[i].x>>real::s[i].y>>real::s[i].z>>real::s[i].r;
    cin>>real::A.x>>real::A.y>>real::A.z;
    bool unreal=real::check_integer();
    if(unreal){
        FFOR(i, 0, m) integer::g[i].x=round(real::g[i].x);
        FFOR(i, 0, m) integer::g[i].y=round(real::g[i].y);
        FFOR(i, 0, m) integer::g[i].z=round(real::g[i].z);
        FFOR(i, 0, m) integer::g[i].r=round(real::g[i].r);
        FFOR(i, 0, m) integer::s[i].x=round(real::s[i].x);
        FFOR(i, 0, m) integer::s[i].y=round(real::s[i].y);
        FFOR(i, 0, m) integer::s[i].z=round(real::s[i].z);
        FFOR(i, 0, m) integer::s[i].r=round(real::s[i].r);
        integer::A.x=round(real::A.x);
        integer::A.y=round(real::A.y);
        integer::A.z=round(real::A.z);
        integer::solve();
    }
    else real::solve();
}