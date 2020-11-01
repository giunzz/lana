				///************** H.A.N Smile **************///
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define MOD 1000000000000000007
#define HAN "BUBBLETEA"
#define ii pair<int , int>
#define lii pair <long long , int>
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e4 + 5;

void make_test()
{
	freopen(HAN".inp", "w", stdout);
	srand(time(0));
}
int n , k, b[N], pr[N][20] , h[N], tp[N] , id, sta[N] , sto[N];
long long d[N], ans = MOD;
vector <ii> a[N];
bool dd[N];
void dfs(int u)
{
    dd[u] = 1;
    tp[++id] = u;
    sta[u] = id;
    for (int i = 0 ; i < a[u].size(); ++i)
    {
        int v = a[u][i].s;
        int dv = a[u][i].f;
        if (!dd[v])
        {
            h[v] = h[u] + 1;
            d[v] = d[u] + dv;
            pr[v][0] = u;
            for (int j = 1 ; j < 19 ; ++j) pr[v][j] = pr[pr[v][j-1]][j-1];
            dfs(v);
        }
    }
    sto[u] = id;
}

int lca(int u , int v)
{
    if (h[u] < h[v])
        swap (u, v);
    int d = h[u] - h[v];
    for (int i = 18 ; i >= 0 ; i--)
        if ( (d>>i) & 1)
        u = pr[u][i];
    if (u==v) return u;

    for (int i = 18; i>=0 ; i--)
        if (pr[u][i]!=pr[v][i])
        {
            u= pr[u][i];
            v= pr[v][i];
        }
    return pr[u][0];
}
int dem[6], luu[6][6];
void trau(int u)
{
    if (u == k + 1)
    {
        long long res = 0;
        for (int i = 1; i <= k/2; ++i){
            int u = luu[i][1];
            int v = luu[i][2];
            int w = lca(u , v);
            res = max(d[u] + d[v] - d[w]*2, res);
        }
        ans = min(ans , res);
        return;
    }

    for (int i = 1 ; i <= k/2; ++i) if (dem[i] <= 1)
    {
        dem[i]++;
        luu[i][dem[i]] = b[u];
        trau(u+1);
        dem[i]--;
    }
}

void sub1()
{
    trau(1);
    cout <<(ans != MOD ? ans : -1);
}

void sub2()
{
    ans = 0;
    memset(dd , 0 , sizeof(dd));
    for (int i = n; i > 0 ; --i)
    {
        int u = tp[i];
        if (sta[u] == sto[u] || dd[u]) continue;
        int res = 0;
        for (int j = 0 ; j < a[u].size(); ++j){
            int v = a[u][j].s;
            if (!dd[v]) res++;
        }

        sort(a[u].begin(), a[u].end());
        int l = 0 , r = a[u].size() - 1;
        if (res % 2 == 0) dd[pr[u][0]] = 1;
        while (l < r)
        {
            while (dd[a[u][l].s] && l <= res) l++;
            while (dd[a[u][r].s] && r >= 0) r--;
            if (l < r)
            {
                dd[a[u][l].s] = 1;
                dd[a[u][r].s] = 1;
                ans = max(ans , 1ll*a[u][l].f + a[u][r].f);
                l++ , r--;
            }
            if (l == r) ans = max(ans, 1ll*a[u][l].f) , dd[a[u][l].s] = 1 , dd[u] = 1;
        }
        if (res % 2 == 0) dd[pr[u][0]] = 0;
    }

    cout <<(ans != 0 ? ans : -1);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//make_test();
	freopen(HAN".inp" , "r", stdin);
	freopen(HAN".out" , "w", stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= k; ++i) cin >> b[i];

    for (int i = 1; i < n; ++i)
    {
        int u , v , w;
        cin >> u >> v >> w;
        a[u].pb(mp(w, v));
        a[v].pb(mp(w, u));
    }
    dfs(1);
    if (k <= 10)
        sub1();
    else
    sub2();
}
