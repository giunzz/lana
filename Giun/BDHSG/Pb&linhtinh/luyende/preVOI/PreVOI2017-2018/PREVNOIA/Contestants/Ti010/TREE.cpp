				///************** H.A.N Smile **************///
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define MOD 1000000007
#define HAN "TREE"
#define ii pair<int , int>
#define lii pair <long long , int>
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e3 + 5;

void make_test()
{
	freopen(HAN".inp", "w", stdout);
	srand(time(0));
}

int n , gt[N] , pr[N], id, tp[N], sta[N] , sto[N], b[N], dp[N], c[N];
vector <int> a[N];
bool dd[N];

void dfs(int u)
{
    dd[u] = 1;
    tp[++id] = u;
    sta[u] = id;
    for (int i = 0 ; i < a[u].size(); ++i)
    {
        int v = a[u][i];
        if (!dd[v]) pr[v] = u, dfs(v);
    }
    sto[u] = id;
}

void sub1()
{
    int dem = 0, ans = MOD;
    for (int i = 1; i <= n; ++i) if (sta[i] == sto[i]) b[++dem] = i;

    for (int x = 0 ; x < (1 << dem); ++x)
    {
    memset(c , 0 , sizeof(c));
    int res = 0;
    for (int j = 1 ; j <= dem ; ++j) c[b[j]] = (x >> (j-1)) & 1;
    for (int i = n; i > 0 ; --i)
    {
        int u = tp[i];
        int w = pr[u];
        c[w] += c[u];
    }
    for (int i = 1 ; i <= n; ++i) res += abs(gt[i] - c[i]);
    ans = min(ans, res);
    }

    cout <<ans;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//make_test();
	freopen(HAN".inp" , "r", stdin);
	freopen(HAN".out" , "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> gt[i];

    for (int i = 1; i < n ; ++i)
    {
        int u , v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    dfs(1);

    //if (n <= 30)
        sub1();
}
