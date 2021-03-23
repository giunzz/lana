#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pl pair<ll,ll>
using namespace std;
ll n  , m , t , visited[50][50];
ll dx[]={-1,1,0,0}, dy[]={0,0,1,-1};
char  x ;
void blablalolo()
{
    freopen("SC5.INP","r",stdin);
    freopen("SC5.OUT","w",stdout);
}
void bfs (pl node )
{
    queue<pl> q;
    visited[node.first][node.second] = 1;
    q.push(node);
    while (!q.empty())
    {
        pl u = q.front();
        q.pop();
        for (int i = 0 ; i < 4 ; i++)
        {
            ll x = u.first + dx[i];
            ll y = u.second + dy[i];
            if (1 <= x and x <= n and 1 <= y and y <= m and visited[x][y] == 0  )
            {
                q.push(pl(x,y)) ;
                visited[x][y] = 1 ;
            }
        }
    }
    if  (visited[n][m] == 1 )  cout << "possible" << endl;
    else cout << "impossible" << endl;
}
int main()
{
    giuncute;
    blablalolo();
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0 ; i <= n ; i++)
            for (int j = 0 ; j <= m ; j++ ) visited[i][j] = 0;
        for (int i = 1 ; i <= n ; i ++)
        {
            for (int j = 1 ; j <= m ; j++)
            {
                cin >> x;
                if (x == '#') visited[i][j] = 2;
            }
        }
        pl tmp ;
        tmp.first = 1 , tmp.second  = 1;
        bfs(tmp);
    }
}
