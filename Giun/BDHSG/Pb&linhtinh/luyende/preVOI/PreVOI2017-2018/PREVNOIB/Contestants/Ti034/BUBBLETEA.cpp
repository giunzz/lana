#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define ll long long
#define pb push_back

using namespace std;

typedef pair <ll, int> ii;
const int N = 5e4 + 2;
int k, n, x, y, p[N];
ll adj[5002][5002], res = 1e18, w;
ll d[N];
vector <ii> a[N];
priority_queue <ii, vector <ii>, greater <ii> > pq;
bool dd[N];

void fr()
{
    freopen("BUBBLETEA.inp", "r", stdin);
    freopen("BUBBLETEA.out", "w", stdout);
}

void inp()
{
    scanf("%d %d", &n, &k);
    fti(i, 1, k) scanf("%d", &p[i]);
    fti(i, 1, n - 1) scanf("%d %d %lld", &x, &y, &w), a[x].pb(ii(w, y)), a[y].pb(ii(w, x));
}

void dijkstra(int s, int id)
{
    int du, u, uv, v;
    fti(i, 1, n) d[i] = 1e18;
    pq.push(ii(0, s));
    d[s] = 0;
    while(!pq.empty()) {
        du = pq.top().first;
        u = pq.top().second;
        pq.pop();
        if(du != d[u]) continue;
        fti(i, 0, int(a[u].size() - 1)) {
            v = a[u][i].second;
            uv = a[u][i].first;
            if(d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
    fti(i, 1, k) adj[id][i] = d[p[i]];
}

void btr(int u, ll S)
{
    if(S > res) return;
    if(u > k / 2) {
        res = min(res, S);
        return;
    }
    fti(i, 1, k - 1) {
        if(dd[i]) continue;
        dd[i] = true;
        fti(j, i + 1, k) {
            if(dd[j]) continue;
            dd[j] = true;
            btr(u + 1, max(adj[i][j], S));
            dd[j] = false;
        }
        dd[i] = false;
    }
}

void proc()
{
    fti(i, 1, k) dijkstra(p[i], i);
    btr(1, 0);
    if(res >= 1e18) printf("-1\n");
    else printf("%lld\n", res);
}

int main()
{
    fr();
    inp();
    if(k <= 10) proc();
    else printf("-1\n");
    return 0;
}
