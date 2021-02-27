#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pl pair<ll,ll>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
ll R,C , a[200][200]  , visited[200][200]={{0}} , dp[200][200]={{0}};
ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};
char x ;
pl start , fi;
void bfs (pl start , pl fi)
{
    queue<pl> q;
    visited[start.first][start.second] =  1;
    q.push(start);
    while (!q.empty())
    {
        pl u = q.front();
       // cerr << u.first << " " << u.second << endl;
        q.pop();
        for (int i = 0 ; i < 4 ; i++)
        {
            ll x = u.first + dx[i];
            ll y = u.second + dy[i];
            if (1 <= x && x <= R && 1 <= y && y <= C && !visited[x][y])
            {
                q.push({x,y});
                dp[x][y] = dp[u.first][u.second]+1;
                visited[x][y] = 1;
            }
        }
    }
    cout << dp[fi.first][fi.second];
}
int main()
{
    giuncute;
    freopen("f.inp","r",stdin);
    freopen("f.out","w",stdout);
    cin >> R >> C;
    for (int i = 1 ; i <= R ; i++)
    {
        for (int j = 1 ; j <= C ; j++)
        {
            cin >> x;
            if (x == 'B') start.first = i , start.second = j;
            else if (x == 'C') fi.first = i , fi.second = j;
            else if (x == '*') visited[i][j] = 1;
        }
    }
    bfs(start,fi);
}