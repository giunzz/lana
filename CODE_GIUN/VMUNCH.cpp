#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pl pair<ll,ll>
using namespace std;
ll R,C;
ll visited[200][200]={{0}};
ll a[200][200];
ll dx[]={1,-1,0,0} , dy[]={0,0,1,-1};
ll ans[200][200]={{0}};
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
//    blablalolo();
    cin >> R  >> C;
    for (int i = 1 ; i <= R ; i++)
    {
        for (int j = 1 ;  j <= C ; j++) 
        {
            cin >> x;
            if (x == 'B')  k.first = i , k.second = j ;
            if (x == 'C') fi.first = i , fi.second = j ;
            if (x == '*') visited[i][j] = 1;
        }
    }
    //cout << fi.first << " " << fi.second << endl;
    bfs(k,fi);
}
