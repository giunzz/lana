#define Link ""

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define TASK "BUBBLETEA"

using namespace std;

void OpenFile()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
}

const int maxn = 5e4 + 1;
int n,k,p[maxn],W[maxn],cnt[maxn],res;
bool b[maxn],del[maxn],use[maxn];
queue <int> qu;
vector <pair<int,int> > e[maxn];

void Enter()
{
    cin >> n >> k;
    for (;k>0;--k) {
        int x;
        cin >> x;
        b[x] = 1;
    }
    for (;n>0;--n) {
        int u,v,w;
        cin >> u >> v >> w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
}

void DelPar(int u, int par, int w)
{
    p[u] = par;
    W[u] = w;
    for (int i=e[u].size()-1;i>=0;--i)
        if (e[u][i].first == par) {
            e[u][i] = e[u].back();
            e[u].pop_back();
        }
        else
            DelPar(e[u][i].first,u,e[u][i].second);
    cnt[u] = e[u].size();
}

void Init()
{
    DelPar(1,0,0);
}

void Sub1()
{

}

void Sub2()
{
    for (int u=1;u<=n;++u)
        if (e[u].size() == 0)
            qu.push(u);
    while (!qu.empty()) {
        int v = qu.front();
        qu.pop();
        if (p[v] == 0 || del[v] || del[p[v]]) {
            cout << -1;
            return;
        }
        res = max(res,W[v]);
        del[v] = del[p[v]] = use[v] = use[p[v]] = 1;
        if (p[p[v]] != 0 && !use[p[p[v]]]) {
            use[p[p[v]]] = 1;
            qu.push(p[p[v]]);
        }
    }
    for (int u=1;u<=n;++u)
        if (!use[u]) {
            cout << -1;
            return;
        }
    cout << res;
}

void Solve()
{
    if (k <= 10)
        Sub1();
    else
        if (k == n)
            Sub2();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    OpenFile();

    Enter();
    Init();
    Solve();
}
