#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
#define pl pair<ll,ll>
const ll maxn = 1e3 + 7;
const ll maxh = 1e6 + 7;
using namespace std;
ll dx[] = {0 , 0 , -1 , 1};
ll dy[] = {-1 , 1 , 0 , 0};
ll n , m , a[maxn][maxn] , h[maxn][maxn];
vector<pl> tmp[maxh] ;

void bfs (ll x , ll y , ll val)
{
    queue<pl> q;
    h[x][y] = val;
    q.push({x , y});
    while (!q.empty())
    {
        x = q.front().fi , y = q.front().se;
        q.pop();
        for (int i = 0 ; i < 4 ; i++)
        {
            ll new_x = x + dx[i] , new_y = y + dy[i];
            if (new_x < 1 || new_y < 1 || new_x > n || new_y > m)  continue;
            if (!h[new_x][new_y] && a[new_x][new_y] <= val)
            {
                h[new_x][new_y] = val;
                q.push({new_x , new_y});
            }
        }
    }
}

bool check (ll x , ll y)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        ll new_x = x + dx[i] , new_y = y + dy[i];
        if (h[new_x][new_y]) return 1;
    }
    return 0;
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    memset(h , -1 , sizeof h);
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
            tmp[a[i][j]].push_back({i , j});
            h[i][j] = 0 ;
        }
    }
    for (int i = 1 ; i <= 1e6 ; i++)
    {
        for (pl j : tmp[i])
        {
            ll x = j.fi , y = j.se;
            if (!h[x][y] && check(x , y)) 
                bfs(x , y , a[x][y]);
        }
    }
    ll ans = 0;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++) ans += max(0LL , h[i][j] - a[i][j]);
    cout << ans;
}
