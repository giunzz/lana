#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pl pair<ll,ll>
using namespace std;
const ll MAXN = 1e3+7;
ll m,n,x, ok = 0 ;
ll visited[MAXN][MAXN]={{0}};
ll a[MAXN][MAXN];
ll dx[]={1,-1,0,0} , dy[]={0,0,1,-1};
pl k , fi;
void blablalolo()
{
    freopen("giun.INP","r",stdin);
    freopen("giun.OUT","w",stdout);
}
void bfs (pl node)
{
    queue<pl> q;
    visited[node.first][node.second] = 1;
    q.push(node);
    while (!q.empty())
    {
        pl u = q.front();
        q.pop();
        cerr << u.first << " " << u .second << endl;
        for (int i = 0 ; i < 4 ; i++)
        {
            ll x = u.first + dx[i];
            ll y = u.second + dy[i];
            if (1 <= x and x <= m and 1 <= y and y <= n and !visited[x][y] )
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
    vector<pl>  tmp ;
    cin >> m  >> n;
    fi.first = m , fi.second = n ;
    int cc = m*n;
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ;  j <= n ; j++) 
        {
            cin >> x;
            if (x == 0 ) visited[i][j] = -1 , cc--;
            if (x == 2 ) visited[i][j] = 1  , tmp.push_back({i,j});
        }
    }
    int cnt = 0 ;
    while ( cc != cnt)
    {
        for (int i = 0 ; i < tmp.size() ; i++)
        {
             cout << visited[i]
        }
    }
}
