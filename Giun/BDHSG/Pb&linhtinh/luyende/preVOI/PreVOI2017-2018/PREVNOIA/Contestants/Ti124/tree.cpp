#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 5006;
const ll inf = 1e18; // ti nua thay long long 

ll n;
ll a[N];
vector<ll > adj[N];

void enter(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("tree.inp", "r", stdin);
	freopen("tree.out", "w", stdout);
	
	cin >> n;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	
	for (ll i = 1; i < n; i++){
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

ll hei[N];
ll dp[N][N];
bool vis[N][N];

void dfs(ll u, ll cha){
	hei[u] = 0;
	for (ll j = 0; j < (ll)adj[u].size(); j++){
		ll v = adj[u][j];
		if (v == cha) continue;
		dfs(v, u);
		hei[u] = max(hei[u], hei[v] + 1);
	}
}

ll cal(ll u, ll val, ll cha){
	if (hei[u] == 0) {
		if (val < 2) return dp[u][val] = abs(a[u] - val);
		else return inf;
	}
	else{
		if (vis[u][val]) return dp[u][val];
		vis[u][val] = 1;
		ll con1 = 0, con2 = 0;
		for (ll j = 0; j < (ll)adj[u].size(); j++)
			if (adj[u][j] != cha) {
				if (!con1) con1 = adj[u][j]; else con2 = adj[u][j];
			}
		ll bd;
		if (hei[u] > 12) 
			bd = hei[u];
		else{
			if (val > (1 << hei[u])) return inf;
			bd = min(val, (1LL << hei[u]));
		}
		if (con2)
			for (ll j = 0; j <= bd ; j++)
				dp[u][val] = min(dp[u][val], abs(a[u] - val) + cal(con1, j, u) + cal(con2, val - j, u) );
		else
			dp[u][val] = min(dp[u][val], abs(a[u] - val) + cal(con1, val, u));
	}
	return dp[u][val];
}

void solve(){
	dfs(1, 0);
	ll res = inf;
	for (ll i = 1; i <= n; i++)
		for (ll j = 0; j <= 5000; j++)
			dp[i][j] = inf;
	ll fbd = 5000;
	if (hei[1] > 12) fbd = min(fbd, hei[1]);
	for (ll j = 0; j <= fbd; j++)
		res = min(res, cal(1, j, 0));
	cout << res;
}


main(){
	enter();
	solve();
}