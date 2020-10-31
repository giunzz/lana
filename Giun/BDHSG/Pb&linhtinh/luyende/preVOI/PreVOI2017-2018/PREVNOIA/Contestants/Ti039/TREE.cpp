#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int n,e[10000],Size[10000],f[5005][5005];
vector <int> a[10000];
void Enter()
{
    cin >> n;
    for (int i=1;i<=n;i++) cin >> e[i];
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }
}
void DFS(int u)
{
    if (a[u].size()==0)
    {
        Size[u]=1;
        f[u][0]=e[u];
        f[u][1]=abs(e[u]-1);
        return;
    }
    for (int v:a[u])
    {
        DFS(v);
        Size[u]+=Size[v];
    }
    for (int i=0;i<=Size[u];i++)
    {
        if (a[u].size()==1) f[u][i]=f[a[u][0]][i]+abs(e[u]-i);
        else
        {
            f[u][i]=1e9;
            int v1=a[u][0],v2=a[u][1];
            for (int j=0;j<=i;j++)
            {
                if (Size[v1]<j||Size[v2]<i-j) continue;
                f[u][i]=min(f[u][i],f[v1][j]+f[v2][i-j]+abs(e[u]-i));
            }
        }
    }
}
void Init()
{
    DFS(1);
}
void Solve()
{
    int kq=1e9;
    for (int i=0;i<=Size[1];i++) kq=min(kq,f[1][i]);
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("TREE.INP","r",stdin);
    freopen("TREE.OUT","w",stdout);
    Enter();
    Init();
    Solve();
}
