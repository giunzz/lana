#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define endl '\n'
#define pi acos(-1)
#define pque priority_queue
#define N 1000000
#define lmax LONG_LONG_MAX
#define cin fi
#define cout fo
ifstream fi("tree.inp");
ofstream fo("tree.out");
typedef pair < int, int > ii;
typedef vector < int > vi;
typedef vector < vi > vii;
int mod = 1000000007;
vi v[5009];
int n, a[5009], ans, f[5009], x, y, par[5009], d[5009];
bool check[5009];
void dfs(int u)
{
	for(int i = 0; i < v[u].size(); i ++)
		if(v[u][i] == par[u])
			v[u].erase(v[u].begin() + i);
	if(v[u].empty())
		check[u] = true;
	for(int i = 0; i < v[u].size(); i ++)
		par[v[u][i]] = u, dfs(v[u][i]);
}
void upd(int u, int val)
{
	val += (abs(f[u] + 1 - a[u]) - abs(f[u] - a[u]));
	if(check[u])
		d[u] = val;
	for(int i = 0; i < v[u].size(); i ++)
		upd(v[u][i], val);
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i < n; i ++)
		cin >> x >> y, v[x].pb(y), v[y].pb(x);
	dfs(1);
	while(1)
	{
		int tak = 0;
		upd(1, 0);
		for(int i = 1; i <= n; i ++)
			if(check[i] && d[i] <= d[tak])
				tak = i;
		if(tak == 0)
			break;
		f[tak] ++;
		check[tak] = false;
		while(tak != 1)
		{
			tak = par[tak];
			f[tak] ++;
		}
	}
	for(int i = 1; i <= n; i ++)
		ans += abs(f[i] - a[i]);
	cout << ans;
}

