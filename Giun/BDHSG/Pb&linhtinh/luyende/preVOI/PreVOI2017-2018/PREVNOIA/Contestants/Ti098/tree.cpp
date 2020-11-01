#include <bits/stdc++.h>
#define FILE "tree"
const int N = 5007;
using namespace std;
int n,a[N],x[N],maxh,dd[N];
vector <int> ke[N];

void dfs(int u,int h)
{
    dd[u] = 1;
    maxh = max(maxh,h);
    for (int i=0;i<ke[u].size();++i) if (!dd[ke[u][i]])
    {
        int v = ke[u][i];
        dfs(v,h+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<n;++i)
    {
        int u,v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    dfs(1,1);
    cout << maxh+1;
    return 0;
}
