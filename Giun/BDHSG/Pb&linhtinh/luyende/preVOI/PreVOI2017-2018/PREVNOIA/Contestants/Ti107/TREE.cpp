#include <bits/stdc++.h>

#define ff(i,a,b)       for(int i=(a), _b=(b); i<=_b; ++i)
#define gg(i,a,b)       for(int i=(a), _b=(b); i>=_b; --i)
#define REP(i,b)        for(int i=(0), _b=(b); i< _b; ++i)
#define endl            '\n'
#define long            long long
#define SX(a)           ((int)(a).size())
#define Love(a)         {cerr << #a << " = " << a << endl;}
#define _               << "," <<
#define BIT(i, x)       (((x)>>(i))&1)
#define X               first
#define Y               second
#define ALL(v)          v.begin(), v.end()

#define NAME            "TREE"

using namespace std;
const int N = 5e3 + 7;
const int INF = 1e9 + 7;

int n, c[N], dp[N][N], cntLeaf[N], tmp[N][N];
bool done[N];
vector <int> a[N];

void Enter() {
    cin >> n;
    ff(i, 1, n) cin >> c[i];
    ff(i, 1, n-1) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void GetSZ(int u, int pa) {
    if (a[u].size() == 1) cntLeaf[u] = 1;
    for (int v : a[u]) {
        if (v == pa) continue;
        GetSZ(v, u);
        cntLeaf[u] += cntLeaf[v];
    }
}

int mini(int &a, int b) {if (a>b)a=b;}

void DFS(int u, int pa) {
    if (u != 1 && a[u].size() == 1) {
        dp[u][0] = c[u];
        dp[u][1] = abs(c[u]-1);
        return;
    }
    for (int v : a[u]) {
        if (v == pa) continue;
        DFS(v, u);
        if (!done[u]) {
            ff(w, 0, cntLeaf[v])
                dp[u][w] = dp[v][w];
            done[u] = true;
        }
        else {
            ff(s, 0, cntLeaf[u]) tmp[u][s] = dp[u][s] + dp[v][0];
            gg(s, cntLeaf[u], 0)
                ff(w, 1, min(cntLeaf[v], cntLeaf[u]-s)) {
                    mini(tmp[u][w+s], dp[u][s] + dp[v][w]);
                }

            ff(s, 0, cntLeaf[u])
                dp[u][s] = tmp[u][s];
        }
    }

    //xu li tk u vs c[u]
    ff(w, 0, cntLeaf[u]) {
        dp[u][w] += abs(c[u]-w);
    }
}

bool cmp(int x, int y) {
    return cntLeaf[x] > cntLeaf[y];
}

void Process() {

    if (n == 1) {
        cout << (c[1] == 0 ? c[1] : c[1] - 1) << endl;
        return;
    }

    GetSZ(1, -1);

    ff(i, 1, n)
        sort(ALL(a[i]), cmp);

    ff(i, 1, n)
        ff(j, 0, cntLeaf[i]) dp[i][j] = tmp[i][j] = INF;

    DFS(1, -1);


    int res = INF;
    ff(w, 0, cntLeaf[1])
        mini(res, dp[1][w]);

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);
    Enter();
    Process();
    return 0;
}
