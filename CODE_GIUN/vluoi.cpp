#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
#define pl pair<ll,ll>
#define ppl pair<ll , pl>
#pragma GCC optimize("Ofast")
const ll oo = 1e18;
const ll maxn = 1e3 + 7;
using namespace std;

ll n , m , a[maxn][maxn] = {{0}} , visited[maxn][maxn] = {{0}} , sl[maxn*maxn] = {0};
ll f[maxn][maxn] = {0};
ll dx[] = {0 , 0 , -1 , 1};
ll dy[] = {1 , -1 , 0 , 0};
ll tmp = 0 , color;
void bfs( ll x , ll y)
{
    color = a[x][y];
    visited[x][y] = ++tmp;
    sl[tmp] = 1;
    queue<pl> q;
    q.push({x,y});
    while (!q.empty())
    {
        ll xi = q.front().fi , yi = q.front().se;
        q.pop();
        for (int i = 0 ; i <= 3 ; i++)
        {
            ll newx = xi + dx[i] , newy = yi + dy[i];
            if (a[newx][newy] == color && !visited[newx][newy])
            {
                visited[newx][newy] = tmp , ++sl[tmp];
                q.push({newx , newy});
            }
        }
    }
}

void dijsktra()
{
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++) f[i][j] = oo;
    f[1][1] = 0;
    priority_queue< ppl , vector<ppl> , greater<ppl> > q;
    q.push({0 , {1,1}});
    while (!q.empty())
    {
        ll dis = q.top().fi;
        ll u = q.top().se.fi , v = q.top().se.se;
        q.pop();
        if (dis != f[u][v]) continue;
        if (u == n && v == m) break;
        for (int i = 0 ; i <= 3 ; i++)
        {
            ll newu = u + dx[i] , newv = v + dy[i];
            if (newu == 0 || newv == 0 || newu > n || newv > m) continue;
            if ((a[u][v] == a[newu][newv] || a[newu][newv] == 1) && f[u][v] < f[newu][newv])
            {
                f[newu][newv] = f[u][v];
                q.push({f[newu][newv] , {newu , newv}});
            }
            else if (a[u][v] != a[newu][newv] && f[u][v]  + a[newu][newv] * sl[visited[newu][newv]] < f[newu][newv])
            {
                f[newu][newv] = f[u][v] + a[newu][newv] * sl[visited[newu][newv]];
                q.push({f[newu][newv] , {newu , newv}});
            }
        }
    }
    cout << f[n][m];
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)  scanf("%lld",&a[i][j]);
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            if (!visited[i][j]) bfs(i , j);
        }
    }
    dijsktra();
}
