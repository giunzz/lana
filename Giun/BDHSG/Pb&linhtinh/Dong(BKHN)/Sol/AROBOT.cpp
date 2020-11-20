#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
#define fi first
#define se second

const int N = 505, oo = 1e9;
int h, w, dp[10][10][N][N], mark[N][N][4], dfs_t, inqueue[N][N], n;
int V[N * N], order[N * N];
string grid[N];
ii go[N][N][4];

int dx[] = {0, -1, 0, 1},
	dy[] = {-1, 0, 1, 0};
deque <ii> buffer;

ii dfs(int x, int y, int dir) {
	if (mark[x][y][dir] == dfs_t) {
		return go[x][y][dir] = {-1, -1};
	}
	if (go[x][y][dir].fi && go[x][y][dir].se) return go[x][y][dir];
	mark[x][y][dir] = dfs_t;
	int ndir = dir, nx = x + dx[dir], ny = y + dy[dir];
	if (grid[nx][ny] == 'A') ndir--;
	else if (grid[nx][ny] == 'C') ndir++;
	ndir = (ndir + 4) % 4;
	if (grid[nx][ny] == 'x' || nx == 0 || nx == h + 1 || ny == 0 || ny == w + 1) {
		go[x][y][dir] = {x, y};
		return go[x][y][dir];
	}
	return go[x][y][dir] = dfs(nx, ny, ndir); 
}

void bfs01(int l, int r) {
	int mx = 0;
	deque <ii> v1, v2; v1.clear(); v2.clear();
	memset(V, 0, sizeof V);
	for (int i = 0; i < buffer.size(); ++i) {
		V[dp[l][r][buffer[i].fi][buffer[i].se]]++;
		mx = max(mx, dp[l][r][buffer[i].fi][buffer[i].se]);
		inqueue[buffer[i].fi][buffer[i].se] = 1;
	}
	for (int i = 0; i <= mx; ++i) {
		V[i] += V[i - 1];
	}
	for (int i = 0; i < buffer.size(); ++i) {
		order[V[dp[l][r][buffer[i].fi][buffer[i].se]] - 1] = i;
		V[dp[l][r][buffer[i].fi][buffer[i].se]]--;
	}
	for (int i = 0; i < buffer.size(); ++i)  {
		v1.push_back(buffer[order[i]]);
	}
	v2.clear();
	while (!v1.empty() || !v2.empty()) {
		int mx = -oo; ii u;
		if (!v1.empty()) {
			if (dp[l][r][v1.front().fi][v1.front().se] > mx) {
				mx = dp[l][r][v1.front().fi][v1.front().se];
				u = v1.front();
			}
		}
		if (!v2.empty()) {
			if (dp[l][r][v2.front().fi][v2.front().se] > mx) {
				mx = dp[l][r][v2.front().fi][v2.front().se];
				u = v2.front();
			}
		}
		if (u == v1.front()) v1.pop_front();
		else v2.pop_front();
		inqueue[u.fi][u.se] = false;
		for (int dir = 0; dir < 4; ++dir) {
			ii v = go[u.fi][u.se][dir];
			if (v.fi == -1 || v.se == -1) continue;
			if (dp[l][r][u.fi][u.se] + 1 < dp[l][r][v.fi][v.se]) {
				dp[l][r][v.fi][v.se] = dp[l][r][u.fi][u.se] + 1;
				if (!inqueue[v.fi][v.se]) {
					v2.push_back(v);
					inqueue[v.fi][v.se] = 1;
				}
			}
		}
		// exit(0);
	}
	buffer.clear();
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("AROBOT.INP", "r", stdin);
	// freopen("AROBOT.OUT", "w", stdout);

	cin >> n >> w >> h;
	for (int i = 1; i <= h; ++i) {
		cin >> grid[i];
		grid[i] = ' ' + grid[i];
	}
	// Calculate go[]
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) if (grid[i][j] != 'x') {
			for (int dir = 0; dir < 4; ++dir) {
				dfs_t++;
				dfs(i, j, dir);
			}
		}
	}
	// End calculate go[]
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			for (int a = 1; a <= n; ++a) {
				for (int b = 1; b <= n; ++b) {
					dp[a][b][i][j] = oo;
				}
			}
		}
	}

	// Calculating base-case
	int cnt = 0;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) if (grid[i][j] >= '1' && grid[i][j] <= '9') {
			int term = grid[i][j] - '0';
			cnt++;
			dp[term][term][i][j] = 0;
			buffer.push_back({i, j});
			bfs01(term, term);
		}
	}
	//End Calculating base-case
	for (int len = 2; len <= cnt; ++len) {
		for (int i = 1; i <= cnt - len + 1; ++i) {
			int j = i + len - 1;
			for (int x = 1; x <= h; ++x) {
				for (int y = 1; y <= w; ++y) {
					for (int k = i; k < j; ++k) {
						dp[i][j][x][y] = min(dp[i][j][x][y], dp[i][k][x][y] + dp[k + 1][j][x][y]);
					}
					if (dp[i][j][x][y] < oo) {
						inqueue[x][y] = 1;
						buffer.push_back({x, y});
					}
				}
			}
			bfs01(i, j);
		}
	}
	int ans = oo;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			ans = min(ans, dp[1][cnt][i][j]);
		}
	}
	if (ans == oo) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}