#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const long long INF = 1e15;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int k,n,m,u,v,p,q,a[302][302],Front,Back;
long long f[302][302];
ii d[605],trace[302][302];
bool check(int i, int j, int x, int y)
{
    return ((i != x || j != y) && i <= m && i > 0 && j <= n && j > 0);
}
void bfs(int u, int v, int p, int q, int x, int y)
{
    priority_queue<iii> pq;
    for (int i = 0; i <= m; i++) fill(f[i],f[i]+n+1,-INF);
    f[u][v] = a[u][v];
    pq.push(iii(f[u][v],ii(u,v)));
    while (!pq.empty())
    {
        int i = pq.top().se.fi, j = pq.top().se.se;
        int w = pq.top().fi; pq.pop();
        if (f[i][j] > w) continue;
        if (check(i+1,j,x,y) && f[i+1][j] < a[i+1][j] + f[i][j])
        {
            f[i+1][j] = a[i+1][j] + f[i][j];
            pq.push(iii(f[i+1][j],ii(i+1,j)));
            trace[i+1][j] = ii(i,j);
        }
        if (check(i,j+1,x,y) && f[i][j+1] < a[i][j+1] + f[i][j])
        {
            f[i][j+1] = a[i][j+1] + f[i][j];
            pq.push(iii(f[i][j+1],ii(i,j+1)));
            trace[i][j+1] = ii(i,j);
        }
    }
}
int main()
{
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) scanf("%d",&a[i][j]);
    while (k--)
    {
        int cnt = 0;
        scanf("%d%d%d%d",&u,&v,&p,&q);
        bfs(u,v,p,q,0,0);
        int i = p, j = q;
        while (i != u || j != v)
        {
            d[++cnt] = trace[i][j];
            i = d[cnt].fi, j = d[cnt].se;
        }
        long long ans = f[p][q];
        for (int i = 1; i < cnt; i++)
        {
            bfs(u,v,p,q,d[i].fi,d[i].se);
            ans = min(ans,f[p][q]);
        }
        cout<<ans<<"\n";
    }
}
