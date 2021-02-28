#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pl pair<ll,ll>
using namespace std;
ll n  , m , t , visited[100][100];
ll dx[]={-1,1,0,0}, dy[]={0,0,1,-1};
char  x ;
void blablalolo()
{
    freopen("PREOLP2.INP","r",stdin);
    freopen("PREOLP2.OUT","w",stdout);
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
            if (1 <= x and x <= n and 1 <= y and y <= m and !visited[x][y]  )
            {
                q.push(pl(x,y)) ;
                visited[x][y] = 1 ;
            }
        }
    }
}

int main()
{
    giuncute;
    blablalolo();
    cin >> t;
    while (t--)
    {
        vector<pl>hang , chuot;
        ll ans = 0;
        cin >> n >> m;
        for (int i = 0 ; i <= n ; i++)
            for (int j = 0 ; j <= m ; j++ ) visited[i][j] = 0;
        for (int i = 1 ; i <= n ; i ++)
        {
            for (int j = 1 ; j <= m ; j++)
            {
                cin >> x;
                if (x == 'R') visited[i][j] = 1;
                if (x == 'E') hang.push_back(make_pair(i,j));
                if (x == 'M') chuot.push_back(make_pair(i,j));
            }
        }
        for (int i = 0 ; i <(int) hang.size() ; i++) bfs(hang[i]);
        for (int i = 0 ; i < (int) chuot.size() ;i++)
        {
            if (visited[chuot[i].first][chuot[i].second] == 1) ans++;
        }
        cout << ans << endl;
    }
}
