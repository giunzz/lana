#include <bits/stdc++.h>
using namespace std;

const long long oo=(int) (1e9 + 7);
bool ck[100001],check[100001];
long long n,m,k,F[10001][10001],path[100001],a,b;

long long find_min(int n)
{
    long long ret,mn=oo;
    for (int i = 1 ; i <= n ; i++)
    {
        if (ck[i]&&path[i]<mn)
        {
            ret=i;
            mn=path[i];
        }
    }
    ck[ret]=0;
    return ret;
}

void dijkstra(long long u)
{
    for (int i=1;i<=n;i++)
    {
        ck[i]=1; 
        path[i]=oo;
    }
    path[u]=0;
    for (int i=1;i<=n;i++)
    {
        long long x=find_min(n);
        for (int j=1;j<=n;j++)
            if (F[x][j]+path[x]<path[j]&&ck[j])
                path[j]=F[x][j]+path[x];
    }
    for (int i=1;i<=n;i++)
        if (path[i]<=k) check[i]=1;
    return;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);

    freopen("warranty.inp","r",stdin);
    freopen("warranty.out","w",stdout);
    cin >> n >> m >> a >> b >> k;
    for (int i=1;i<=n;i++)
    {
        check[i]=0;
        for (int j=1;j<=n;j++) F[i][j]=oo;
    }
    int u,v,val;
    for (int i=1;i<=m;i++)
    {
        cin >> u >> v >> val;
        F[u][v]=val;
        F[v][u]=val;
    }
    dijkstra(a);
    dijkstra(b);
    bool check1=1;
    for (int i=1;i<=n;i++)
        if (!check[i])
        {
            cout << i << " ";
            check1=0;
        } 
    if (!check) cout << "-1";
    return 0;
}