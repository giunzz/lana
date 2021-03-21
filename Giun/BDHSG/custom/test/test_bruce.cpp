#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int oo = 1000111000;
typedef pair<int, int> ii;

vector<ii> a[2309];
int n, m;

int d[2309];

void dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++)
        d[i] = oo;
    d[1] = 0;
    pq.push(ii(0, 1));

    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
    int p, q, m, w;
    cin >> n;
    while (!cin.eof()) {
        // scanf("%d%d%d", &p, &q, &w);
        cin >> p >> q >> w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        printf("%d\n", d[i]);
}