/*
3 4 2
5 2 4 2
3 2 6 8
7 8 9 3
1 1 3 4
1 2 2 4
*/

/*
3 4 4
1 1 1 1
1 2 2 2
1 2 2 2
1 1 2 2
1 1 3 4
1 3 3 4
1 1 2 4
*/

/*
4 4 1
1 2 1 1
2 9 3 3
1 4 1 1
1 2 1 5
1 1 4 4
*/

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

int m, n, k;
int a[302][302];
pair< pair<int, int>, pair<int, int> > p[302];
int op[302][302];
int dp[31][31];

vector<int> g[90004];
int num[302][302], low[90004], parent[90004], dis[90004], root[90004], vis[90004], ap[90004];
int ccc = 0, tim;


void dfs(int pos){
    tim++;
    int child = 0;
    vis[pos] = 1;
    dis[pos] = low[pos] = tim;
    for (int j = 0; j < g[pos].size(); j++) {
        if (!vis[g[pos][j]]) {
            child ++;
            parent[g[pos][j]] = pos;
            dfs(g[pos][j]);
            low[pos] = min(low[pos], low[g[pos][j]]);
            if (root[pos] && child > 1) {
                ap[pos] = 1;
            }
            if (!root[pos] && low[g[pos][j]] >= dis[pos]) {
                ap[pos] = 1;
            }
        }
        else {
            if (g[pos][j] != parent[pos]) {
                low[pos] = min(low[pos], dis[g[pos][j]]);
            }
        }
    }
}

signed main() {
  freopen("TABLE.inp", "r", stdin);
  freopen("TABLE.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      ccc++;
      num[i][j] = ccc;
    }
  }
  memset(low, 0, sizeof(low));
  memset(root, 0, sizeof(root));
  memset(vis, 0, sizeof(vis));
  memset(dis, 0, sizeof(dis));
  for (int i = 1; i <= k; i++) {
    scanf("%d%d%d%d", &p[i].x.x, &p[i].x.y, &p[i].y.x, &p[i].y.y);
  }
  if (m <= 30 && n <= 30 && k <= 30) {
    for (int i = 1; i <= k; i++) {
      int res = INT_MAX;
      for (int bi = p[i].x.x; bi <= p[i].y.x; bi++) {
        for (int bj = p[i].x.y; bj <= p[i].y.y; bj++) {
          if (bi == p[i].x.x && bj == p[i].x.y) continue;
          if (bi == p[i].y.x && bj == p[i].y.y) continue;
          memset(dp, 0, sizeof(dp));
          for (int x = p[i].x.x; x <= p[i].y.x; x++) {
            for (int y = p[i].x.y; y <= p[i].y.y; y++) {
              if (x == bi && y == bj) {
                dp[x][y] = -INT_MAX;
              }
              else {
                dp[x][y] = max(dp[x-1][y], dp[x][y-1]) + a[x][y];
              }
            }
          }
          res = min(res, dp[p[i].y.x][p[i].y.y]);
        }
      }
      cout << res << '\n';
    }
    return 0;
  }
  for (int i = 1; i <= k; i++) {
    //pre-processing
    for (int x = p[i].x.x; x <= p[i].y.x; x++) {
      for (int y = p[i].x.y; y <= p[i].y.y; y++) {
        if (op[x-1][y] > op[x][y-1]) {
          g[num[x][y]].push_back(num[x-1][y]);
          g[num[x-1][y]].push_back(num[x][y]);
          op[x][y] = op[x-1][y] + a[x][y];
        }
        if (op[x][y-1] > op[x-1][y]) {
          g[num[x][y]].push_back(num[x][y-1]);
          g[num[x][y-1]].push_back(num[x][y]);
          op[x][y] = op[x][y-1] + a[x][y];
        }
        if (op[x][y-1] == op[x-1][y]) {
          g[num[x][y]].push_back(num[x][y-1]);
          g[num[x][y]].push_back(num[x-1][y]);
          g[num[x][y-1]].push_back(num[x][y]);
          g[num[x-1][y]].push_back(num[x][y]);
          op[x][y] = op[x-1][y] + a[x][y];
        }
      }
    }
    int preres = op[p[i].y.x][p[i].y.y];
    tim = 0;
    root[num[p[i].y.x][p[i].y.y]] = 1;
    dfs(num[p[i].y.x][p[i].y.y]);
    int px, py, ma = -1;
    for (int x = p[i].x.x; x <= p[i].y.x; x++) {
      for (int y = p[i].x.y; y <= p[i].y.y; y++) {
        if (x == p[i].x.x && y == p[i].x.y) continue;
        if (x == p[i].y.x && y == p[i].y.y) continue;
        op[x][y] = 0;
        if (ap[num[x][y]]) {
          if (a[x][y] > ma || (num[x][y] > num[px][py] && a[x][y] >= ma)) {
            ma = a[x][y];
            px = x;
            py = y;
          }
        }
      }
    }
    if (ma == -1) {
      cout << preres << '\n';
    }
    else {
      for (int x = p[i].x.x; x <= p[i].y.x; x++) {
        for (int y = p[i].x.y; y <= p[i].y.y; y++) {
          if (x == px && y == py) {
            op[x][y] = -INT_MAX;
            continue;
          }
          if (op[x-1][y] > op[x][y-1]) {
            op[x][y] = op[x-1][y] + a[x][y];
          }
          if (op[x][y-1] > op[x-1][y]) {
            op[x][y] = op[x][y-1] + a[x][y];
          }
          if (op[x][y-1] == op[x-1][y]) {
            op[x][y] = op[x-1][y] + a[x][y];
          }
        }
      }
      cout << op[p[i].y.x][p[i].y.y] << '\n';
    }
    //post-processing
    for (int x = p[i].x.x; x <= p[i].y.x; x++) {
      for (int y = p[i].x.y; y <= p[i].y.y; y++) {
        op[x][y] = 0;
        g[num[x][y]].clear();
        root[num[x][y]] = 0;
        vis[num[x][y]] = 0;
        dis[num[x][y]] = 0;
        low[num[x][y]] = 0;
        ap[num[x][y]] = 0;
      }
    }
  }
}
