//Trương Minh Trí
#include <bits/stdc++.h>
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define FORN(i, x, y) for(int i = x; i >= y; --i)
#define Task "TABLE"
#define maxn 305
#define maxc 1000000000
#define pii pair <int,int>
#define pll pair <long long, long long>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define reset(x) memset(x, 0, sizeof(x));
#define resett(x,n) FOR(i,1,n) x[i] = 0;
using namespace std;
int m, n, k;
int a[maxn][maxn];
int tr[maxn][maxn];
long long dp[maxn][maxn];
vector<pii> res;
long long maxx(long long &a, long long &b)
{
    if(a > b) return a;
    return b;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> m >> n >> k;
    FOR(i, 1, m)
        FOR(j, 1, n) cin >> a[i][j];
    FOR(testt, 1, k)
    {
        long long ans = 1e18;
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        FOR(i, u, p)
            FOR(j, v, q) dp[i][j] = tr[i][j] = 0;
        dp[u-1][v] = dp[u][v-1] = -maxc;
        dp[u][v] = a[u][v];
        FOR(i, u, p)
            FOR(j, v, q)
            {
                if(dp[i][j] < dp[i-1][j] + a[i][j])
                {
                    dp[i][j] = dp[i-1][j] + a[i][j];
                    tr[i][j] = 1;
                }
                if(dp[i][j] < dp[i][j-1] + a[i][j])
                {
                    dp[i][j] = dp[i][j-1] + a[i][j];
                    tr[i][j] = -1;
                }
            }
//        if(ans > dp[p][q] - a[u][v]) ans = dp[p][q] - a[u][v];
//        if(ans > dp[p][q] - a[p][q]) ans = dp[p][q] - a[p][q];
        int s = p, t = q;
        while(tr[s][t] != 0)
        {
            if(tr[s][t] == 1) s--;
            else t--;
            if(tr[s][t] !=0) res.pb({s, t});
        }
        FOR(h, 0, res.size()-1)
        {
            pii id = res[h];
            FOR(i, u, p)
                FOR(j, v, q) dp[i][j] = 0;
            dp[u][v] = a[u][v];
            FOR(i, u, p)
                FOR(j, v, q)
                {
                    if(i==id.F && j == id.S) continue;
                    if(dp[i][j] < dp[i-1][j] + a[i][j])
                        dp[i][j] = dp[i-1][j] + a[i][j];
                    if(dp[i][j] < dp[i][j-1] + a[i][j])
                        dp[i][j] = dp[i][j-1] + a[i][j];
                }
            if(ans > dp[p][q]) ans = dp[p][q];
        }
        cout << ans << "\n";
    }
}
























template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
