#include <bits/stdc++.h>
using namespace std;

struct data {
    int a, b, c, d;
} circle[2005], shop[20];

int m, n, k, res;
int px, py, pz;
bool visit[2005];
vector<int> G[20];
vector<int> L, R;

bool cmp(int x, int y) {
    return shop[x].a < shop[y].a;
}

void solve(int x, int y) {
    memset(visit, 0, sizeof visit);
    int cnt = 0, sum = 0;
    for (int i = 0; i < x; ++i) {
        int cur = L[i];
        for (int j = 0; j < G[cur].size(); ++j) {
            int tmp = G[cur][j];
            if (!visit[tmp]) cnt++, visit[tmp] = 1;
        }
        sum += shop[cur].d;
    }
    for (int i = 0; i < y; ++i) {
        int cur = R[i];
        for (int j = 0; j < G[cur].size(); ++j) {
            int tmp = G[cur][j];
            if (!visit[tmp]) cnt++, visit[tmp] = 1;
        }
        sum += shop[cur].d;
    }
    if (cnt <= k) res = max(res, sum);
}

int main() {
    freopen("teaworld.inp", "r", stdin);
    freopen("teaworld.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> m >> n >> k;
    for (int i = 0; i < m; ++i) {
        cin >> circle[i].a >> circle[i].b >> circle[i].c >> circle[i].d;
    }
    for (int i = 0; i < n; ++i) {
        cin >> shop[i].a >> shop[i].b >> shop[i].c >> shop[i].d;
    }
    cin >> px >> py >> pz;
    for (int i = 0; i < n; ++i) {
        if (shop[i].a <= px) L.push_back(i);
        else R.push_back(i);
    }
    sort(L.begin(), L.end(), cmp);
    reverse(L.begin(), L.end());
    sort(R.begin(), R.end(), cmp);
    for (int i = 0; i < L.size(); ++i) {
        int cur = L[i];
        for (int j = 0; j < m; ++j) {
            bool flag = 0;
            if (circle[j].a + circle[j].d < px && circle[j].a + circle[j].d >= shop[cur].a) flag = 1;
            if (circle[j].a - circle[j].d <= px && circle[j].a - circle[j].d > shop[cur].a) flag = 1;
            if (flag) G[cur].push_back(j);
        }
    }
    for (int i = 0; i < R.size(); ++i) {
        int cur = R[i];
        for (int j = 0; j < m; ++j) {
            bool flag = 0;
            if (circle[j].a + circle[j].d >= px && circle[j].a + circle[j].d < shop[cur].a) flag = 1;
            if (circle[j].a - circle[j].d > px && circle[j].a - circle[j].d <= shop[cur].a) flag = 1;
            if (flag) G[cur].push_back(j);
        }
    }
    for (int i = 0; i <= L.size(); ++i) {
        for (int j = 0; j <= R.size(); ++j) {
            solve(i, j);
        }
    }
    cout << res;
}
