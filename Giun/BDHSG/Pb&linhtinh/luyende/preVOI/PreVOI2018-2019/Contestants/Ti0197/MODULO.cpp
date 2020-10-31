#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define FORR(i,a,b) for (int i=(a); i>=(b); --i)
#define REP(i,b) for (int i=0; i<(b); ++i)
#define input stdin
#define output stdout
#define assign freopen
#define endl '\n'
#define sz(x) (int) x.size()
#define div /
#define mod %
#define fillchar(x,y,z) memset(x,z,y)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define sqr(x) ((x)*(x))
typedef long long int64;
typedef unsigned long long qword;
using namespace std;
int a,b,n;
int64 K;
qword base;
pair<int64,int> c[2000005];
void Input()
{
    cin >> a >> b;
    cin >> n >> K;
    base=(1ull<<n)-1;
}
int64 meomeo(int64 a, int64 b)
{
    int64 res=0;
    while (b) {
        if (b&1) res=(res+a)&base;
        a=(a<<1)&base;
        b>>=1;
    }
    return res;
}
void Solve()
{
    if (n>40) {
        cout << -1;
        return;
    }
    if (K mod 2==0&&a mod 2==1&&b mod 2==1) {
        cout << -1; return;
    }
    if (K mod 2==1&&a mod 2==0&&b mod 2==0) {
        cout << -1; return;
    }
//    meomeo(1,0);
//    cout << -1;
    //sub2
    int m=n/2;
    int64 magic=1;
    FOR(i,1,n-m)
        magic=(magic*10)&base;
    REP(mask,(1<<m)) {
        int64 cur=0;
        REP(i,m)
            if (mask>>i&1)
                cur=(cur*10+a)&base;
            else
                cur=(cur*10+b)&base;
        cur=meomeo(cur,magic);
        cur=K-cur;
        if (cur<0) cur+=base+1;
        c[mask]=mp(cur,mask);
    }
    sort(c,c+(1<<m));
    int tmp=(1<<m);
    m=n-m;
    REP(mask,(1<<m)) {
        int64 cur=0;
        REP(i,m)
            if (mask>>i&1)
                cur=(cur*10+a)&base;
            else
                cur=(cur*10+b)&base;
        int l=lower_bound(c,c+tmp,mp(cur,-1))-c;
        if (c[l].fi==cur) {
            int premask=c[l].se;
            REP(i,n-m)
                if (premask>>i&1) cout << a;
                else cout << b;
            REP(i,m)
                if (mask>>i&1) cout << a;
                else cout << b;
            return;
        }
    }
    cout << -1;
}
int main()
{
    assign("MODULO.inp","r",input);
    #ifndef meomeomeooooo
        assign("MODULO.out","w",output);
    #endif // meomeomeooooo
    iostream::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Solve();
    return 0;
}
