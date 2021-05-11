// #include<bits/stdc++.h>
// using namespace std;
// #define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
// #define ll long long 
// const int MAXN = 1e3+7;
// const ll oo = 1e9 + 7;
// ll N,M,u , v , w , visited[MAXN] ={0} , cost[MAXN][MAXN] ={0} , ans = 0 , p[MAXN] , size[MAXN];
// vector<ll> G[MAXN] ;
// vector<pair<ll,pair<ll,ll>>> G1;
// void dfs(ll node , ll color)
// {
//     visited[node] = color ;
//     for (int v : G[node])
//         if (!visited[v]) dfs(v,color);
// }
// ll GET (ll u )
// {
//     if(p[u] == u) return u;
//     return p[u] = GET(p[u]);
// }
// bool ghep(pair<ll,pair<ll,ll>> a)
// {
//     ll x = GET(visited[a.second.first]), y = GET(visited[a.second.second]);
//     if(x == y) return 0;
//     if( size[x] < size[y]) swap(x, y);
//     size[x] += size[y];
//     p[y] = x;
//     return 1;
// }

// bool cmp(pair<ll,pair<ll,ll>> &a, pair<ll,pair<ll,ll>> &b){
//     return a.first < b.first;
// }

// int main()
// {
//     vector<pair<ll,ll>> res;
//     giuncute;
//     freopen("giun.inp","r",stdin);
//     freopen("giun.out","w",stdout);
//     cin >> N >> M ;
//     for (int i = 1 ; i <= M ; i++)
//     {
//         cin >> u >> v ; 
//         G[u].push_back(v) ;
//         G[v].push_back(u);
//     }
//     for (int i = 1 ; i <= N ; i++) p[i] = i , size[i] = 1;
//     for (int i = 1 ; i <= N ; i++)
//         for (int j = 1 ; j <= N ; j++) cin >> cost[i][j] ;
//     ll TPLT = 0 , cnt = 0  ;
//     for (int i = 1 ;i <= N ; i++)
//         if (!visited[i]) TPLT++ , cnt++ , dfs(i,cnt);
//     for (int i = 1 ; i <= N ; i++)
//     {
//         for (int j = i+1 ; j <= N ; j++)
//             if (visited[i] != visited[j]) 
//                 G1.push_back(make_pair(cost[i][j] , make_pair(i,j)));
//     }
//     sort(G1.begin(), G1.end(), cmp);
//     for (int i = 0 ; i < G1.size() ; i++ )
//     {
//         if(ghep(G1[i]) && cnt != TPLT - 1)
//         {
//             ++cnt;
//             ans += G1[i].first;
//             res.push_back(make_pair(G1[i].second.first,G1[i].second.second));
//         }
//     }
//     cout << ans << endl;
//     if (ans > 0 )
//         for (int i = 0 ; i < res.size() ; i++) cout << res[i].first << " " << res[i].second << endl;
// }
#include <bits/stdc++.h>

using namespace std;

struct giuncute {
	long long  u , v , w;
};

struct quangcute {
	long long  u , v;
};

bool cmp(giuncute &a , giuncute &b) {
	return a.w < b.w;
}

vector <giuncute> adj;
bool meo[2000][2000];
long long  n , m ,u , v , w;
vector <long long > root(2000);
vector <giuncute> go;

void init() {
	for (long long  i = 1 ; i <= n ; i++) 
		root[i] = i;
	return;
}

long long  findroot(long long  u) {
	if (root[u] == u) return u;
	else {
		root[u] = findroot(root[u]);
	}
	return root[u];
}

void unionset(long long  u , long long  v) {
	long long  rootu = findroot(u);
	long long  rootv = findroot(v);
	if (rootu != rootv) 
		root[root[u]] = rootv;
	return;
}

bool checking(long long  u , long long  v) {
	long long  rootu = findroot(u);
	long long  rootv = findroot(v);
	if (rootu == rootv) return true;
	return false;
}

int  main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("mgt.inp","r",stdin);
	freopen("mgt.out","w",stdout);
	cin >> n >> m;
	for (long long  i = 0 ; i < m ; i++) {
		cin >> u >> v;
		adj.push_back({u , v , 0});
		adj.push_back({v , u , 0});
		meo[u][v] = meo[v][u] = true;
	}
	for (long long  i = 1 ; i <= n ; i++) {
		for (long long  j = 1 ; j <= n ; j ++) {
			cin >> w;
			if (!meo[i][j] && !meo[j][i]){ 
				adj.push_back({i , j , w});
			}
		}
	}
	init();
	sort(adj.begin() + 2*m , adj.end() , cmp);
	for (long long  i = 0 ; i < (long long ) adj.size() ; i++) {
		if (!checking(adj[i].u , adj[i].v)) {
			unionset(adj[i].u , adj[i].v);
			go.push_back({adj[i].u , adj[i].v , adj[i].w});
		}
	}
	long long  ans = 0;
	vector <quangcute> res;
	for (long long  i = 0 ; i < (long long ) go.size() ; i++) {
		ans += go[i].w;
		if (!meo[go[i].u][go[i].v] && !meo[go[i].v][go[i].u]) 
			res.push_back({go[i].u , go[i].v});
	}
	cout << ans;
	cout << '\n';
	for (long long  i = 0 ; i < (long long ) res.size() ; i++) 
		cout << res[i].u << " " << res[i].v << '\n';

	return 0;
}