#include <bits/stdc++.h>

using namespace std;
const int N = 312;

int m,n,a[N][N],sum,k,b[312][312];
pair<int,int> tr[312][312];
void sub1()
{
    while(k--)
    {
        int res = sum;
        int x,y,u,v;
        cin >> x >> y >> u >> v;
        for(int dx = x;dx <= u;dx++)
            for(int dy = y;dy <= v;dy++)
            {
                if(dx == x && dy == y) continue;
                if(dx == u && dy == v) continue;
                for(int i = 1;i <= m;i++)
                    for(int j = 1;j <= n;j++) b[i][j] = 0;
                for(int i = x;i <= u;i++)
                    for(int j = y;j <= v;j++) if(i != dx || j != dy) b[i][j] = max(b[i-1][j],b[i][j-1]) + a[i][j];
                res = min(res,b[u][v]);
            }
        cout << res << '\n';
    }
}
void tham()
{
    while(k--)
    {
        int res = sum;
        int x,y,u,v;
        cin >> x >> y >> u >> v;
        for(int i = 1;i <= m;i++)
            for(int j = 1;j <= n;j++) b[i][j] = 0;
        for(int i = x;i <= u;i++)
            for(int j = y;j <= v;j++)
            {
                if(b[i][j] < b[i-1][j] + a[i][j])
                {
                    b[i][j] = b[i-1][j] + a[i][j];
                    tr[i][j] = {i-1,j};
                }
                if(b[i][j] < b[i][j-1] + a[i][j])
                {
                    b[i][j] = b[i][j-1] + a[i][j];
                    tr[i][j] = {i,j-1};
                }
            }
        pair<int,int> run = tr[u][v];
        while(run.first != x || run.second != y)
        {
            for(int i = 1;i <= m;i++)
                    for(int j = 1;j <= n;j++) b[i][j] = 0;
            for(int i = x;i <= u;i++)
                for(int j = y;j <= v;j++) if(i != run.first || j != run.second) b[i][j] = max(b[i-1][j],b[i][j-1]) + a[i][j];
            res = min(res,b[u][v]);
            run = tr[run.first][run.second];
        }
        cout << res << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin >> m >> n >> k;
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++) cin >> a[i][j],sum += a[i][j];
    if(m <= 30 && n <= 30 && k <= 30)sub1();
    else tham();
    return 0;
}
