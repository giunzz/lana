#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second

const int N = 4e3 + 5;
int n, m, delta, l[N], r[N], dp[N][N];
map<int, int> id;
map<int, vector<int> > pos;

int read_int () {
    int ret = 0; char inp;
    do { inp = getchar(); } while (!isdigit(inp) ); ret = inp - '0';
    while (isdigit(inp = getchar() ) ) { ret = 10 * ret + inp - '0'; }
    return ret;
}

struct It {
    int node[24 * N];
    void build_tree (int nd, int Left, int Right) {
        node[nd] = 0;
        if (Left == Right) return ;
        int mid = Left + Right >> 1;
        build_tree(nd << 1, Left, mid); build_tree(nd << 1 | 1, mid + 1, Right);
    }
    void update (int nd, int Left, int Right, int pos, int val) {
        if (Right < pos || pos < Left) return ;
        if (Left == Right) { node[nd] = max(node[nd], val); return ; }
        int mid = Left + Right >> 1;
        update(nd << 1, Left, mid, pos, val); update(nd << 1 | 1, mid + 1, Right, pos, val);
        node[nd] = max(node[nd << 1], node[nd << 1 | 1]);
    }
    int get (int nd, int Left, int Right, int l, int r) {
        if (Right < l || r < Left) return 0;
        if (l <= Left && Right <= r) return node[nd];
        int mid = Left + Right >> 1;
        return max(get(nd << 1, Left, mid, l, r), get(nd << 1 | 1, mid + 1, Right, l, r) );
    }
} it;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("LIONDANCE.INP", "r", stdin);
    freopen("LIONDANCE.OUT", "w", stdout);

    n = read_int();
    delta = read_int();
    for (int i = 1; i <= n; ++i) {
        l[i] = read_int();
        id[ l[i] ];
        id[ l[i] + delta ];
        id[ l[i] - delta ];
    }
    for (int i = 1; i <= n; ++i) {
        r[i] = read_int();
        pos[ r[i] ].pb(i);
        id[ r[i] ];
        id[ r[i] + delta ];
        id[ r[i] - delta ];
    }

    int curId = 0;
    for (auto _ : id) id[_.fi] = ++curId;

    for (int j = n; j > 0; --j) {
        int tmp = lower_bound(pos[ l[j] ].begin(), pos[ l[j] ].end(), n + 1) - pos[ l[j] ].begin();
        if (tmp > 0) dp[1][j] = pos[ l[j] ][tmp - 1];
    }
    for (int i = 2; i <= n; ++i) {
        it.build_tree(1, 1, id.size() );
        for (int j = n; j > 0; --j) {
            it.update(1, 1, id.size(), id[ l[j + 1] ], dp[i - 1][j + 1]);
            dp[i][j] = it.get(1, 1, id.size(), id[ l[j] - delta ], id[ l[j] + delta ]);
            int tmp = lower_bound(pos[ l[j] ].begin(), pos[ l[j] ].end(), dp[i][j]) - pos[ l[j] ].begin();
            if (tmp > 0) dp[i][j] = pos[ l[j] ][tmp - 1];
            else dp[i][j] = 0;
        }
    }

    for (int i = n; i > 0 && !m; --i) {
        for (int j = 1; j <= n && !m; ++j) if (dp[i][j] > 0) m = i;
    }

    cout << m << '\n';
    int prvL = 0, prvR = 0;
    for (int i = m; i > 0; --i) {
        int choo = -1;
        for (int j = prvL + 1; j <= n; ++j) if (!prvL || abs(l[j] - l[prvL]) <= delta) {
            if ( (choo == -1 || l[choo] < l[j]) && dp[i][j] > prvR) choo = j;
        }
        prvL = choo;
        for (int j = prvR + 1; j <= n; ++j) if (r[j] == l[prvL]) { prvR = j; break ; }
        cout << l[prvL] << ' ';
    }

    return 0;
}
