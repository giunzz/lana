#include <bits/stdc++.h>
#define NAME "tree"
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i,a ,b) for(int i = (a), _b = (b); i >= _b; --i)
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int maxN = 5e3 + 10;
int n, a[maxN], d[maxN];
int ans, f[maxN], _f[maxN][maxN];
vector<int> vt[maxN];
bool leaf[maxN];
void io()
{
	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);
}
void dfs(int u)
{
	d[u] = 1;
	FOR(i, 0, vt[u].size() - 1)
	{
		int v = vt[u][i];
		if (!d[v])
		{
			dfs(v);
			if (!leaf[v]) {
				f[v]++;
			}
			f[u] += f[v];
		}
	}
}
int _dfs(int u, int num)
{
	if(num > f[u]) return _f[u][num] = 1e9;
	if(!leaf[u]) return _f[u][num] = abs(a[u] - num);
	_f[u][num] = 1e9;
	if(vt[u].size() == 1)
	{
		int v = vt[u][0];
		_f[u][num] = _dfs(v, num);
	}
	if(vt[u].size() == 2)
	{
		int v = vt[u][0];
		int t = vt[u][1];
		FOR(i, 0, f[v])
		{
			_f[u][num] =  min(_f[u][num], _dfs(v, i) + _dfs(t, num - i));
		}
	}
	return _f[u][num] + abs(a[u] - num);
}
int main()
{
	io();
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	int x, y;
	FOR(i, 1, n - 1)
	{
		cin >> x >> y;
		vt[x].pb(y);
		leaf[x] = 1;
	}
	dfs(1);
	ans = 1e9;
	FOR(i, 0, f[1]) {
		if(abs(a[1] - i) >= ans) continue;
		ans = min(ans, _dfs(1, i));
	}
	cout << ans;
	return 0;
}
/*
5
5 1 3 0 1
1 2
1 3
3 4
3 5
*/