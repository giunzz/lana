#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pi pair<int,int>
const int MAXN = 1e3+7;
const ll oo = 1e17 + 7;
ll N,M, S , T;
ll d[MAXN][MAXN]={0} , p[MAXN][MAXN]={0}  , dt[MAXN][MAXN]={0};
void floy()
{
    for (int k = 1 ; k <= N ; k++)
    {
        for (int i = 1 ; i <= N ; i++)
        {
            for (int j = 1 ; j <= N ; j++)
            {
                if (d[i][j] > (d[i][k] + d[k][j]))
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> N >> M >> S;
    ll x, y, l , ans = 0 ;
    for(int i = 1; i<=N; ++i) 
        for(int j = 1; j<=N; ++j) d[i][j] = oo;
    for (int i = 1 ; i <= N ; i++) d[i][i] = 0 ;
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> x >> y >> l;
        d[x][y] = l; 
        d[y][x] = l;
    }   
    floy();
    for (int i = 1 ; i <= N ; i++)
    {
        for (int j = 1 ; j <= N ; j++)
            if (d[i][j] == S) ans++;
    }
    cout << ans ;
}