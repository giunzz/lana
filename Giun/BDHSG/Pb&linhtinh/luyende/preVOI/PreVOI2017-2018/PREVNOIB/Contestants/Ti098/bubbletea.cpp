#include <bits/stdc++.h>
#define FILE "bubbletea"
const int N = 50007;
using namespace std;
int n,k,vc[N],dd[N],t;
long long deep[N],ans;
vector <pair<int,int> > ke[N];

void dfs(int u,int h,long long tmp)
{
    if (dd[u]!=t) dd[u]=t; else return;
    if (vc[u]) deep[h] = min(deep[h],tmp);
    for (int i=0;i<ke[u].size();++i) if (dd[ke[u][i].first]!=t)
    {
        int v = ke[u][i].first;
        int w = ke[u][i].second;
        dfs(v,h+1,tmp+w);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n >> k;
    for (int i=1;i<=k;++i)
    {
        int x;
        cin >> x;
        vc[x] = 1;
    }
    for (int i=1;i<n;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        ke[u].push_back({v,w});
        ke[v].push_back({u,w});
    }
    memset(deep,60,sizeof(deep));
    for (int i=1;i<=n;++i) if (vc[i])
    {
        ++t;
        dfs(i,1,0);
    }
    for (int i=1;i<=n;++i) if (deep[i]!=deep[0]) ans = max(ans,deep[i]);
    cout << ans;
    return 0;
}
