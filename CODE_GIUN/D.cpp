#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pl pair<ll,ll>
using namespace std;
ll m , n , p , s[10] , visited[1008][1008]={0};
ll dx[]={1,-1,0,0} , dy[]={0,0,1,-1};
char x;
pl k , fi;
void blablalolo()
{
    freopen("giun.INP","r",stdin);
    freopen("giun.OUT","w",stdout);
}
void bfs (pl node , pl nodefi)
{
    queue<pl> q;
    visited[node.first][node.second] = 1;
    q.push(node);
    while (!q.empty())
    {
        pl u = q.front();
        cerr << u.first << " " << u.second << endl;
        q.pop();
        for (int i = 0 ; i < 4 ; i++)
        {
            ll x = u.first + dx[i];
            ll y = u.second + dy[i];
            if (1 <= x and x <= R and 1 <= y and y <= C and !visited[x][y]  )
            {
                q.push(pl(x,y)) ;
                visited[x][y] = 1 ;
                ans[x][y] = ans[u.first][u.second]+1;
            }
        }
    }
    cout << ans[nodefi.first][nodefi.second];
}
int main()
{
    giuncute;
    blablalolo();
    cin >> m >> n >> p ;
    for (int i = 1 ; i <= p ; i++) cin >> s[i];
    for (int i = 1 ; i <= m ; i++)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> x; 
            if (x >= '0' && x <= '9') 
            else if (x == '#') G.push_back(x);
        }
    }

}
