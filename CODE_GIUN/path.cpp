#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pi pair<int,int>
const int MAXN = 1e3+7;
const ll oo = 1e9 + 7;
ll N,M, S , T;
ll d[MAXN][MAXN]={0} , p[MAXN][MAXN]={0}  , dt[MAXN][MAXN]={0};
void trace (int i , int j )
{
    if ( p[i][j] == 0 ) return;
    else 
    {
        trace(i , p[i][j]) ;
        cout << p[i][j] << " ";
        trace(p[i][j],j);
    }
}
void floy()
{
    for (int k = 1 ; k <= N ; k++)
    {
        for (int i = 1 ; i <= N ; i++)
        {
            for (int j = 1 ; j <= N ; j++)
            {
                if (d[i][j] > (d[i][k] + d[j][k]))
                {
                    d[i][j] = d[i][k] + d[j][k];
                    p[i][j] = k;
                }
            }
        }
    }
}
int main()
{
    giuncute;
    freopen("path.inp","r",stdin);
    freopen("path.out","w",stdout);
    cin >> N >> M >> S >> T;
    ll x, y, l;
    for(int i = 1; i<=N; ++i) 
        for(int j = 1; j<=N; ++j) d[i][j] = 1e17;
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> x >> y >> l;
        d[x][y] = l; 
        d[y][x] = l;
    }   
    floy();
    for (int i = 1 ; i <= N ; i++)
    {
        for (int j = 1 ; j <= N ; j++) cerr << p[i][j] << " ";
        cerr << endl;
    }
    cout << d[S][T] << endl;
    cout << S << " ";
    trace(S,T);
    cout << T ;
}