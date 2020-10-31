#include <bits/stdc++.h>

#define rep(i,a,b) for (int i = a,_b = b;i <= _b;++i)
#define per(i,a,b) for (int i = a,_b = b;i >= _b;--i)
#define fore(i,c) for (__typeof(c) i = c.begin();i!=c.end();i++)

#define i64 long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back

#define All(x) x.begin(),x.end()
#define rAll(x) x.rbegin(),x.rend()
#define SZ(x) (int) x.size()

#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }
#define PR(A,l,r) {cerr << #A << " = "; rep(_,l,r) cerr << A[_] <<' '; cerr << endl;}
#define fast_io ios_base :: sync_with_stdio(false),cin.tie(0)

using namespace std;

i64 Read() {i64 x = 0; char c = getchar(); bool neg = false;while (c!='-' && (c < '0' || c > '9')) c=getchar(); if (c=='-') neg=true, c = getchar();while (c>='0' && c<='9') x = x*10+c-'0',c=getchar();if (neg) x = -x; return x;}
void Write(i64 x) {if (x < 0) {putchar('-'); Write(-x); return;};if (x > 9) Write(x/10);putchar(x % 10 + '0');}

const i64 lim = 1e17;
const int maxn = 302;

int n,m,k;
i64 a[maxn][maxn],b[maxn][maxn];
struct truy {
    int u,v,x,y;
} Q[maxn];
i64 ans[maxn];

void Calc(int o) {
    i64 s[33][33];
    rep(i,1,n) rep(j,1,m) s[i][j] = -lim;
    s[Q[o].u][Q[o].v] = b[Q[o].u][Q[o].v];
    rep(i,Q[o].u,Q[o].x) rep(j,Q[o].v,Q[o].y) {
        s[i+1][j] = max(s[i+1][j],s[i][j]+b[i+1][j]);
        s[i][j+1] = max(s[i][j+1],s[i][j]+b[i][j+1]);
    }
    ans[o] = min(ans[o],s[Q[o].x][Q[o].y]);
}

void Sub1() {
    rep(o,1,k) {
        ans[o] = lim;
        rep(i,1,n) rep(j,1,m) {
            if (i == Q[o].u && j == Q[o].v) continue;
            if (i == Q[o].x && j == Q[o].y) continue;
            b[i][j] = -lim;
            Calc(o);
            b[i][j] = a[i][j];
        }
    }
    rep(o,1,k) cout << ans[o] <<'\n';
}

inline void maximize(i64 &a,const i64 &b) {
    if (a < b) a = b;
}

i64 dp[82][82][82][82];

void Calc(int x,int y) {
    rep(i,1,k) if ((x == Q[i].u && y == Q[i].v) || (x == Q[i].x && y == Q[i].y)) return;
    rep(i,1,k) {
        if (dp[Q[i].u][Q[i].v][x][y]+dp[x][y][Q[i].x][Q[i].y]-a[x][y] != dp[Q[i].u][Q[i].v][Q[i].x][Q[i].y]) {
            ans[i] = max(ans[i],dp[Q[i].u][Q[i].v][x][y]+dp[x][y][Q[i].x][Q[i].y]-a[x][y]);
        }
    }
}

void Solve() {
    rep(i,1,n) rep(j,1,m) {
        dp[i][j][i][j] = a[i][j];
        rep(o,i,n) rep(k,j,m) {
            maximize(dp[i][j][o+1][k],dp[i][j][o][k]+a[o+1][k]);
            maximize(dp[i][j][o][k+1],dp[i][j][o][k]+a[o][k+1]);
        }
    }
    rep(i,1,k) ans[i] = 0;
    rep(i,1,n) rep(j,1,n) Calc(i,j);
    rep(i,1,k) cout << ans[i] <<'\n';
}

#define task "table"
main() {
   freopen(task".inp","r",stdin);
   freopen(task".out","w",stdout);
   cin >> n >> m >> k;
   rep(i,1,n) rep(j,1,m) {
        cin >> a[i][j];
        b[i][j] = a[i][j];
   }
   rep(i,1,k) cin >> Q[i].u >> Q[i].v >> Q[i].x >> Q[i].y;
   if (n <= 30 && m <= 30 && k <= 30) Sub1(); else Solve();
}
//cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC <<" s.\n";
