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

#define NAME            "BUBBLETEA"

using namespace std;
const int N = 5e4 + 7;
typedef pair<int, int> ii;
int n, k, c[N], d[N], id[N], p[N];
vector <ii> a[N];

void Enter() {
    cin >> n;
    ff(i, 1, n) {
        int  cac;
        cin >> cac;
    }

    ff(i, 1, n-1) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back(ii(y, w));
        a[y].push_back(ii(x, w));
    }
}

void DFS(int u, int pa) {
    for (ii e : a[u]) {
        int v = e.X, w = e.Y;
        if (v == pa) continue;
        c[v] = w;
        p[v] = u;
        d[v] = d[u] + 1;
        DFS(v, u);
    }
}


bool done[N];
void Process() {
    DFS(1, -1);
    ff(i, 1, n) id[i] = i;
    sort(id+1, id+1+n, [](int x, int y) {
            return d[x] > d[y];
    });

    vector<int> vv;
    int res = -1e9;
    ff(i, 1, n) {
        if (!done[i]) {
            int par = p[i];
            done[i] = true;
            vv.clear();
            for (ii e : a[par]) {
                int v = e.X;
                if (done[v]) continue;
                done[v] =true;
                vv.push_back(c[v]);
            }
            if (vv.size()&1) vv.push_back(c[i]);

            sort(vv.begin(), vv.end());
            int x = vv.size();
            REP(i, vv.size()/2) {
                int u =vv[i];
                int v = vv[x-i];
                res = max(res, u+v);
            }
        }
    }
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
