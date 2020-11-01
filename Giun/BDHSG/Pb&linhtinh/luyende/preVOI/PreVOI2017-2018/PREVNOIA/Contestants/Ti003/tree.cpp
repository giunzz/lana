#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define ft first
#define sd second
#define _(a) #a << " : " << (a)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 5e3 + 3;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
int a[maxn];
int c1[maxn] = {}, c2[maxn] = {}, cnum[maxn] = {};
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int u, v;
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		if (c1[u] == 0) c1[u] = v;
		else c2[u] = v;
	}
}
int f[maxn][maxn];
void dfs (int i)
{
	if (c1[i] == 0)
	{
		f[i][0] = a[i];
		f[i][1] = abs (a[i] - 1);
		cnum[i] = 1;
		return;
	}
	else
	{
		int i1 = c1[i], i2 = c2[i];
		// cerr << i << ' ' << i1 << ' ' << i2 << '\n';
		dfs (i1);
		if (i2) dfs (i2);
		cnum[i] = cnum[i1] + cnum[i2];
		for (int j = 0; j <= cnum[i]; ++j)
		{
			int o = min (j, cnum[i1]);
			for (int x = 0; x <= o; ++x)
				f[i][j] = min (f[i][j], f[i1][x] + f[i2][j - x] + abs (a[i] - j));
		}
	}
}
void solve ()
{
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < maxn; ++j)
			f[i][j] = inf;
	f[0][0] = 0;
	dfs (1);
	int res = inf;
	for (int i = 0; i <= cnum[1]; ++i)
	{
		res = min (res, f[1][i]);
		// if (res == f[1][i]) x = i;
	}
	cout << res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("tree.inp", "r", stdin);
	freopen ("tree.out", "w", stdout);
	input ();
	solve ();
}