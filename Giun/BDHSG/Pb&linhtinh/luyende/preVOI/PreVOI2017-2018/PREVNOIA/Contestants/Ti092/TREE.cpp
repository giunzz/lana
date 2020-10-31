
#include <bits/stdc++.h>

#define ll long long
#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; --i)
#define pb push_back

using namespace std;

const int maxn = 5001;
const int oo = 1e9;
int n, a[maxn], cnt, topo[maxn], end_topo[maxn], T[4*maxn], res, t;

vector<int> adj[maxn], leaf;

void update(int k, int l, int r, int i, int w)
{
    if(i < l || r < i) return;
    if(l == r){
        T[k] = w;
        return;
    }
    int mid = (l + r) >> 1;
    update(2 * k, l, mid, i, w);
    update(2 * k + 1, mid + 1, r, i, w);
    T[k] = T[2 * k] + T[2 * k + 1];
}
int get(int k, int l, int r, int i, int j)
{
    if(j < l || r < i) return 0;
    if(i <= l && r <= j) return T[k];
    int mid = (l + r) >> 1;
    return (get(2 * k, l, mid, i, j) + get(2 * k + 1, mid + 1, r, i, j));
}
void Input()
{
    cin >> n;
    int u, v;
    fti(i, 1, n) cin >> a[i];
    fti(i, 1, n - 1){
        cin >> u >> v;
        adj[u].push_back(v);
    }
}
void DFS_topo(int u)
{
    topo[u] = ++cnt;
    fti(i, 0, int(adj[u].size()) - 1)
        DFS_topo(adj[u][i]);
    end_topo[u] = cnt;
}
int btr(int u)
{
    int s = 0;
    int x, q;
    fti(i, 0, int(leaf.size()) - 1){
        q = leaf[i];
        x = (u >> i) & 1;
        update(1, 1, n, topo[q], x);
    }
    fti(i, 1, n) s += abs(a[i] - get(1, 1, n, topo[i], end_topo[i]));
    return s;
}
void Process()
{
    res = oo;
    DFS_topo(1);
    fti(i, 1, n) if(topo[i] == end_topo[i]) leaf.pb(i);
    int t = leaf.size();
    for(int i = 0; i < (1 << t); ++ i){
        res = min(res, btr(i));
    }
    cout << res;
}
void io()
{
    freopen("TREE.inp", "r", stdin);
    freopen("TREE.out", "w", stdout);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    io();
    Input();
    Process();
}
