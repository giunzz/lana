#include <bits/stdc++.h>
#define NAME "bubbletea"
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i,a ,b) for(int i = (a), _b = (b); i >= _b; --i)
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int maxN = 5e4 + 10;
int n, k, par[maxN],  b[maxN], d[maxN], p[maxN][50], dd[maxN], s[20], ss[20];
ll l[maxN];
ll ans;
typedef pair<int, int> ii;
vector<ii> a[maxN];
void io()
{
	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);
}
void dfs(int u)
{
	FOR(i, 0, a[u].size() - 1)
	{
		int v = a[u][i].fi;
		ll _l = a[u][i].se;
		if (!d[v])
		{
			d[v] = d[u] + 1;
			l[v] = l[u] + _l;
			par[v] = u;
			dfs(v);
		}
	}
}
int init()
{
	int _log = log2(n);
	FOR(i, 1, n) p[i][0] = par[i];
	FOR(j, 1, _log)
	{
		FOR(i, 1, n) p[i][j] = p[p[i][j - 1]][j - 1];
	}
}
int lca(int x, int y)
{
	if (d[x] < d[y]) swap(x, y);
	int _log = log2(n);
	FORD(j, _log, 0)
	if (d[p[x][j]] >= d[y]) x = p[x][j];
	if (x == y) return x;
	FORD(j, _log, 0)
	{
		if (p[x][j] != p[y][j]) x = p[x][j], y = p[y][j];
	}
	return p[x][0];
}
void bt(int x)
{
	if (x == k + 1)
	{
		FOR(i, 1, k) ss[s[i]] = b[i];
		ll sum = 0;
		for (int i = 2; i <= k; i += 2)
		{
			int u = ss[i], v = ss[i - 1];
			int t = lca(u, v);
			sum = max(sum, l[u] + l[v] - 2 * l[t]);
			if(sum > ans) return;
		}
		ans = min(ans, sum);
		return;
	}
	FOR(i, 1, k)
	{
		if (!dd[i])
		{
			dd[i] = 1;
			s[x] = i;
			bt(x + 1);
			dd[i] = 0;
		}
	}
}
int main()
{
	io();
	cin >> n >> k;
	if(k > 11)
	{
		cout << -1;
		return 0;
	}
	FOR(i, 1, k) cin >> b[i];
	int x, y;
	ll w;
	FOR(i, 1, n - 1)
	{
		cin >> x >> y >> w;
		a[x].pb(ii(y, w));
		a[y].pb(ii(x, y));
	}
	d[1] = 1;
	par[1] = 1;
	dfs(1);
	init();
	ans = 1e18;
	bt(1);
	cout << ans;
	return 0;
}
/*
8 6
1 4 5 6 7 8
1 2 1
2 3 1
3 4 1
2 5 1
2 6 1
3 7 1
3 8 1

8 8
1 2 3 4 5 6 7 8
1 2 1
2 3 10
3 4 1
2 5 6
2 6 6
3 7 6
3 8 6
*/