#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e3 + 10;
const int oo = 1e9 + 7;
const int dx[] = {0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define ii pair < int, int >
#define fi first
#define se second

int n, m, k, ans = 0;
int ok[N][N], cnt[N][N];
queue < ii > q;

bool Inside(int x, int y) {
	return (1 <= x and x <= n and 1 <= y and y <= m);
}

int main() {
    FileOpen;
    cin >> n >> m >> k;
	memset(ok, 0, sizeof(ok));
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		ok[x][y] = 1;
		q.push(ii(x, y));22
		cnt[x][y] = 0;
	}
	while (!q.empty()) {
		ii u = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int x = u.fi + dx[i];
			int y = u.se + dy[i];
			if (Inside(x, y) and !ok[x][y]) {
				q.push(ii(x, y));
				ok[x][y] = 1;
				cnt[x][y] = cnt[u.fi][u.se] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cerr << cnt[i][j] << " ";
        }
        cerr << endl;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (cnt[i][j] > 2) ans++;
		}
	}
	cout << ans << endl;
}