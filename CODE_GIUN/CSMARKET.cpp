#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pi pair<int,int>
const int MAXN = 1e3+7;
const ll oo = 1e9 + 7;
ll N,M;
double d[MAXN][MAXN]={0} ;
ll p[MAXN][MAXN]={0}  ;
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
    freopen("CSMARKET.inp","r",stdin);
    freopen("CSMARKET.out","w",stdout);
    cin >> N >> M;
    ll x, y;
    double l ,ans = -oo ;
    for(int i = 1; i<=N; ++i) 
        for(int j = 1; j<=N; ++j) d[i][j] = 1e17;
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> x >> y >> l;
        d[x][y] = l; 
        d[y][x] = l;
    }   
    floy();
    ans = min (d[1][N] , d[N][1]);
    cout << fixed << setprecision(2) << ans;
}