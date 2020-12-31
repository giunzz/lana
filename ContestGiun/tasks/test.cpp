#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 55;
int n, root = 1, totNode = 1, automaton[(int)1e6 + 2][2], dp[50][(int)1e6][2];
string s;

struct Node {
	int link, child[2], val;
	Node() {
		link = 0; val = 0;
		child[0] = child[1] = 0;
	}
} node[(int)1e6 + 5];

void addString(string s) {
	int p = root;
	for (int i = 0; i < s.size(); ++i) {
		int cur = s[i] - '0';
		if (node[p].child[cur] == 0) {
			node[p].child[cur] = ++totNode;
		}
		p = node[p].child[cur];
	}
	node[p].val++;
}

void AhoCorasick() {
	queue <int> q; while (!q.empty()) q.pop();
	q.push(root);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int nxt = 0; nxt < 2; ++nxt) {
			int cur = u;
			while (1) {
				if (node[cur].child[nxt] != 0) {
					automaton[u][nxt] = node[cur].child[nxt];
					break;
				}
				if (cur == root) {
					automaton[u][nxt] = root;
					break;
				}
				cur = node[cur].link;
			}
		}
		for (int nxt = 0; nxt < 2; ++nxt) if (node[u].child[nxt]) {
			if (u == 1) node[node[u].child[nxt]].link = root;
			else node[node[u].child[nxt]].link = automaton[node[u].link][nxt];
			q.push(node[u].child[nxt]);
		}
	}
}

void go_dp() {
	dp[0][root][0] = 1;
	for (int id = 0; id < n; ++id) {
		int i = id & 1;
		for (int nod = 1; nod <= totNode; ++nod) {
			for (int cur = 0; cur < 2; ++cur) {
				for (int nxt = 0; nxt < 2; ++nxt) {
					int trans = automaton[nod][nxt];
					dp[i ^ 1][trans][cur | (node[trans].val > 0)] += dp[i][nod][cur];
				}
			}
		}
		memset(dp[i], 0, sizeof dp[i]);
	}
	int res = 0;
	for (int i = 1; i <= totNode; ++i) {
		res += dp[n & 1][i][1];
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("SEED.INP", "r", stdin);
	// freopen("SEED.OUT", "w", stdout);

	cin >> n >> s;
	int m = s.size(), cnt = 0;
	for (int i = 0; i < m; ++i) {
		if (s[i] == '*') {
			cnt++;
		}
	}
	for (int mask = 0; mask < (1 << cnt); ++mask) {
		int c = 0;
		string t; t.clear();
		for (int i = 0; i < m; ++i) {
			if (s[i] == '*') {
				if (mask & (1 << c)) t = t + "1";
				else t = t + "0";
				c++;
			} else t = t + "1";
		}
		addString(t);
	}
	AhoCorasick();
	go_dp();

	return 0;
}