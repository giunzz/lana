#define Link ""

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>

#define TASK "TREE"

using namespace std;

void OpenFile()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
}

const long long oo = 1e18;
const int maxn = 1e4 + 1;
int n,a[maxn];
vector <int> e[maxn];
long long f[maxn][maxn];

void Enter()
{
    cin >> n;
    for (int i=1;i<=n;++i)
        cin >> a[i];
    for (int i=1;i<=n;++i) {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
    }
}

void Init()
{
    for (int u=1;u<=n;++u)
        fill(f[u],f[u]+n+1,+oo);
}

void DFS(int u)
{
    for (int v : e[u])
        DFS(v);
    if (e[u].size() == 0) {
        f[u][0] = a[u];
        f[u][1] = abs(a[u]-1);
    }
    else
        if (e[u].size() == 1) {
            int v = e[u].front();
            for (int k=0;k<=n;++k)
                f[u][k] = min(f[v][k]+abs(a[u]-k),+oo);
        }
        else {
            int v1 = e[u][0];
            int v2 = e[u][1];
            for (int k1=0;k1<=n;++k1)
                for (int k2=0;k2<=n;++k2)
                    f[u][k1+k2] = min(f[u][k1+k2],f[v1][k1]+f[v2][k2]+abs(a[u]-k1-k2));
        }
}

void Solve()
{
    DFS(1);
    long long res = +oo;
    for (int k=0;k<=n;++k)
        res = min(res,f[1][k]);
    cout << res;
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
