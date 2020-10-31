#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a), _b = (b) ; i <= _b ; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b) ; i >= _b ; --i)
#define For(i, a, b) for(int i = (a), _b = (b) ; i < _b ; ++i)
#define Ford(i, a, b) for(int i = (a), _b = (b) ; i > _b ; --i)
#define ll long long
#define ii pair <int,int>
#define mp make_pair
#define pb push_back
#define X first
#define Y second

using namespace std;

const int N = 5e3+5;
const int oo = 1e9;

int n, u, v;
int c[N], b[N];
int f[N], par[N];
int cur = 0, res = oo;
vector <int> a[N];

void dfs(int u, int p) {
	For(i, 0, a[u].size()) {
		v = a[u][i];
		if(v == p) continue;
		par[v] = u;
		dfs(v, u);
	}
}

void update(int u, int w) {
	while (u != 0) {
		f[par[u]] += w;
		u = par[u];
	}
}

void sub_1(void) {

	dfs(1, 1);

	int top = 0;
	FOR(i, 2, n) if(a[i].size() == 1) b[++top] = i;

	int lim = (1 << top) - 1, cur = 0;
	///cout << lim << endl;
	FOR(mask, 0, lim)
	///int mask = 7;
	{
		cur = 0;
		FOR(i, 1, n) f[i] = 0;
		FOR(i, 1, top) {
			if(mask >> (i-1) & 1) f[b[i]] = 1;
		}
		///cout << endl; FOR(i, 1, top) cout << b[i] << " " << f[b[i]] << " "; cout << endl;
		FOR(i, 1, top) update(b[i], f[b[i]]);
		FOR(i, 1, n) cur += abs(c[i] - f[i]);
		///cout << endl; FOR(i, 1, n) cout << f[i] << " " ; cout << endl;
		///cout << endl; FOR(i, 1, n) cout << f[i] << " " ; cout << endl;
		res = min(res, cur);
	}
	cout << res << endl;
}

void sub_2(void) {

}

int main()
{
	freopen("TREE.INP", "r", stdin); freopen("TREE.OUT", "w", stdout);
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", &c[i]);
	For(i, 1, n) {
		scanf("%d%d", &u, &v);
		a[u].pb(v), a[v].pb(u);
	}

	sub_1();
    return 0;
}
