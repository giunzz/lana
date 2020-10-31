/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ll long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define pi acos(-1)
#define N 303
#define task "table"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}

using namespace std;

const ll MM = 1ll*maxc*maxc;

void MIN(ll &res, ll x)
{
    if (res > x) res = x;
}

int m, n, k, a[N][N], cnt = 0;

ll dp[N][N], f[N][N];

pii tr[N][N], luu[2*N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    read(m), read(n), read(k);//cin >> m >> n >> k;
    FOR(i, 1, m)
        FOR(j, 1, n) read(a[i][j]);//cin >> a[i][j];
    FOR(test, 1, k)
    {
        ll res = MM;
        FOR(i, 0, m)
            FOR(j, 0, n) dp[i][j] = -MM;
        int u, v, p, q;
        read(u), read(v), read(p), read(q);//cin >> u >> v >> p >> q;
        dp[u][v] = a[u][v];
        FOR(i, u, p)
            FOR(j, v, q)
            {
                if (dp[i][j] < dp[i-1][j] + a[i][j])
                {
                    dp[i][j] = dp[i-1][j] + a[i][j];
                    tr[i][j] = MP(i-1, j);
                }
                if (dp[i][j] < dp[i][j-1] + a[i][j])
                {
                    dp[i][j] = dp[i][j-1] + a[i][j];
                    tr[i][j] = MP(i, j-1);
                }
            }
        int x = tr[p][q].F, y = tr[p][q].S;
        cnt = 0;
        while (1)
        {
            luu[++cnt] = MP(x, y);
            int xx, yy;
            xx = tr[x][y].F;
            yy = tr[x][y].S;
            if (MP(xx, yy) == MP(u, v)) break;
            x = xx, y = yy;
        }
        FOR(tt, 1, cnt)
        {
            x = luu[tt].F, y = luu[tt].S;
            FOR(i, u, p)
                FOR(j, v, q) f[i][j] = dp[i][j];
            FOR(i, x, p)
                FOR(j, y, q) f[i][j] = -MM;
            FOR(i, x, p)
                FOR(j, y, q)
                {
                    int cur = a[i][j];
                    if (i == x && j == y) cur = -maxc;
                    if (f[i][j] < f[i-1][j] + cur)
                        f[i][j] = f[i-1][j] + cur;
                    if (f[i][j] < f[i][j-1] + cur)
                        f[i][j] = f[i][j-1] + cur;
                }
            MIN(res, f[p][q]);
        }
        writeln(res);//cout << res << '\n';
    }
    return 0;
}
