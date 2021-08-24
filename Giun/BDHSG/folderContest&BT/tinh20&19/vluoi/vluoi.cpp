#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long
#define MAX_N (ll) (1e3 + 7)
#define MAX_D (ll) (1e6 + 7)
#define ii pair<ll , ll>
#define x first
#define y second
#define inf (ll) (1e18)

ll n , m;
ll a[MAX_N][MAX_N];
map <ii ,bool> vis;
ll color[MAX_N][MAX_N];
ll dx[4] = {0 , 0 , 1 , -1};
ll dy[4] = {1 , -1 , 0 , 0};
vector <ii> adj[MAX_D];
ii val[MAX_D];
ll d[MAX_D];
ll cntnodes = 0;
queue<ii> q;
bool visited[MAX_N][MAX_N];

void BFS(ii start , ll nodes) {
	q.push(start);
	ll defaultcolor = a[start.x][start.y];
	visited[start.x][start.y] = true;
	color[start.x][start.y] = nodes;
	val[nodes].x = (defaultcolor == 1 ? 0 : defaultcolor);
	ll cnt = 1;
	while (!q.empty()) {
		ii u = q.front();
		q.pop();
		for (ll i = 0 ; i < 4 ; i++) {
			ii v = u;
			v.x += dx[i] , v.y += dy[i];
			if (v.x <= n && v.x >= 1 && v.y <= m && v.y >= 1 && !visited[v.x][v.y] && a[v.x][v.y] == defaultcolor) {
				visited[v.x][v.y] = true;
				color[v.x][v.y] = nodes;
				cnt ++;
				q.push(ii(v.x , v.y));
			}
		}
	}
	val[nodes].y = cnt;
	return;
}

void dijkstra() {
	for (int i = 1 ; i <= cntnodes ; i++) {
		d[i] = inf;
	}
	priority_queue<ii , vector<ii> , greater<ii>> pq;
	pq.push(ii(0 , 1));
	d[1] = 0;
	while (!pq.empty()) {
		ll u = pq.top().y;
		ll du = pq.top().x;
		pq.pop();
		if (du != d[u]) continue;
		for (int i = 0 ; i < adj[u].size() ; i++) {
			ll v = adj[u][i].y;
			ll uv = adj[u][i].x;
			if (d[v] > du + uv) {
				d[v] = du + uv;
				pq.push(ii(d[v] , v));
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("vluoi.inp","r",stdin);
	freopen("vluoi.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ;i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1 ; i <= n ;i++) {
		for (int j = 1 ; j <= m ;j++) {
			if (!visited[i][j]) {
				cntnodes++;
				BFS(ii(i , j) , cntnodes);
			}
		}
	}

	for (ll i = 1 ; i <= n ;i++) {
		for (ll j = 1 ; j <= m ;j++) {
			for (ll k = 0 ; k < 4 ; k++) {
				ii v = ii(i , j);
				v.x += dx[k] , v.y += dy[k];
				if (v.x <= n && v.x >= 1 && v.y <= m && v.y >= 1) {
					ll curr = color[i][j] , newc = color[v.x][v.y];
					if (!vis[ii(curr,newc)] && curr != newc){
						adj[curr].push_back(ii(val[newc].x*val[newc].y , newc));
						adj[newc].push_back(ii(val[curr].x*val[curr].y , curr));
						vis[ii(curr,newc)] = true;
					}
				}
			}
		}
	}

	dijkstra();
	cout << d[color[n][m]];
	return 0;
}
//
//#include<bits/stdc++.h>
//#define ll long long
//#define cll const ll
//#define lp(a, b, c) for(ll a = b; a <= c; ++a)
//#define lpd(a, b, c) for(ll a = b; a >= c; --a)
//#define vec(a) vector<a>
//#define pp(a, b) pair<a, b>
//#define Fname "vluoi"
//#pragma GCC optimize("Ofast")
//using namespace std;
//
//cll mxn = 1e3 + 2, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
//ll n, m, a[mxn][mxn] = {{0}}, tot[mxn * mxn] = {0}, ti = 0, d[mxn][mxn] = {{0}}, curcol, dp[mxn][mxn];
//
//void bfs(ll xr, ll yr){
//    d[xr][yr] = ++ti;
//    tot[ti] = 1;
//    curcol = a[xr][yr];
//    queue<pp(ll, ll)> q;
//    q.push({xr, yr});
//    while(q.size()){
//        ll x = q.front().first, y = q.front().second;
//        q.pop();
//        lp(i, 0, 3){
//            ll nx = x + dx[i], ny = y + dy[i];
//            if(a[nx][ny] == curcol && !d[nx][ny]){
//                d[nx][ny] = ti;
//                ++tot[ti];
//                q.push({nx, ny});
//            }
//        }
//    }
//}
//
//void dijk(){
//    lp(i, 1, n) lp(j, 1, m) dp[i][j] = 1e18;
//    dp[1][1] = 0;
//    priority_queue<pp(ll,  pp(ll, ll)), vec(pp(ll, pp(ll, ll))), greater<pp(ll, pp(ll, ll))>> q;
//    q.push({0, {1, 1}});
//    while(q.size()){
//        ll dis = q.top().first, x = q.top().second.first, y = q.top().second.second;
//        q.pop();
//        if(dis != dp[x][y]) continue;
//        if(x == n && y == m) break;
//        lp(i, 0, 3){
//            ll nx = x + dx[i], ny = y + dy[i];
//            if(!nx || !ny || nx > n || ny > m) continue;
//            if((a[x][y] == a[nx][ny] || a[nx][ny] == 1) && dp[x][y] < dp[nx][ny]){
//                dp[nx][ny] = dp[x][y];
//                q.push({dp[nx][ny], {nx, ny}});
//            } else if(a[x][y] != a[nx][ny] && dp[x][y] + a[nx][ny] * tot[d[nx][ny]] < dp[nx][ny]){
//                dp[nx][ny] = dp[x][y] + a[nx][ny] * tot[d[nx][ny]];
//                q.push({dp[nx][ny], {nx, ny}});
//            }
//        }
//    }
////    cout << dp[n][m];
//    printf("%lld", dp[n][m]);
//}
//
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
////    cin >> n >> m;
//    scanf("%lld %lld", &n, &m);
//    lp(i, 1, n) lp(j, 1, m) scanf("%lld", &a[i][j]);
//    lp(i, 1, n) lp(j, 1, m)
//        if(!d[i][j]) bfs(i, j);
//    dijk();
//}
