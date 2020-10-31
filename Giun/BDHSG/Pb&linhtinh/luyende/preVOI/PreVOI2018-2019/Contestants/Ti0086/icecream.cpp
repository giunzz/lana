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

const int MOD = 1e9 + 9;
const int maxn = 301;

int n,nmax,ans;
int m[3],a[maxn];

bool Check() {
    int mm[3] = {m[0],m[1],m[2]};
    rep(i,1,n) {
        mm[a[i]]++;
        if (mm[a[i]] > nmax) return false;
        if (a[i] == 1) {
            if (mm[0] > 0) mm[0]--; else return false;
        }
        if (a[i] == 2) {
            if (mm[0] > 0 && mm[1] > 0) {
                mm[0]--;
                mm[1]--;
            } else if (mm[0] > 2) mm[0] -= 3; else return false;
        }
    }
    return true;
}

void DFS(int i) {
    rep(j,0,2) {
        a[i] = j;
        if (i == n) ans += Check(); else DFS(i+1);
    }
}

void Sub1() {
    DFS(1);
    cout << ans;
}

const int maxm = 10001;

int dp[55][55][55][55];

void Sub2() {
    dp[0][0][0][0] = 1;
    rep(i,0,n) rep(m0,0,n) rep(m1,0,n) rep(m2,0,n) {
        int val = dp[i][m0][m1][m2];
        dp[i+1][m0+1][m1][m2] += val;
        dp[i+1][m0-1][m1+1][m2] += val;
        dp[i+1][m0-3][m1][m2+1] += val;
        dp[i+1][m0-1][m1-1][m2+1] += val;
    }
    i64 ans = 0;
    rep(i,0,n) rep(j,0,n) rep(k,0,n) if (i <= nmax && j <= nmax && k <= maxn) {
        ans += dp[n][i][j][k];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans <<'\n';
}

#define task "icecream"
main() {
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n >> nmax >> m[0] >> m[1] >> m[2];
    if (n <= 15) Sub1(); else {
        Sub2();
    }
}
//cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC <<" s.\n";
