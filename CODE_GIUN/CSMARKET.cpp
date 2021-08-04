#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pi pair<int,int>
const int MAXN = 1e3+7;
const ll oo = 1e9 + 7;
ll N,M;
ll d[MAXN][MAXN]= {{0}};

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
    ll x, y , l;
    for (int i = 1 ; i <= N ; i++)
        for (int j = 1 ; j <= N ; j++) d[i][j] = 1e18;
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> x >> y >> l;
        d[x][y] = l; 
        d[y][x] = l;
    }   
    floy();
    ll ans = INT_MAX;
    for (int i = 1 ; i <= N ; i++)
    {
        ll tmp = INT_MIN;
        for (int j = 1 ; j <= N ; j++) tmp = max (tmp , d[i][j]);
        ans = min(ans , tmp); 
    }
    cout << ans/2;
    if (ans % 2 == 0 ) cout << ".00" ;
    else cout << ".50";
}