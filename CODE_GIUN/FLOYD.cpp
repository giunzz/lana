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
                    p[j][i] = k;
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
    cin >> N >> M >> S >> T;
    ll x, y, l;
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> x >> y >> l;
        dt[x][y] = l; 
        dt[y][x] = l;
    }
    for (int u = 1 ; u <= N ; u++)
    {
        for (int v = 1 ; v <= N ; v++)
        {
            if (u == v) d[u][v] = 0;
            else d[u][v] = (dt[u][v]) ? dt[u][v] : oo;
            p[u][v] = (dt[u][v]) ? v : 0;
        }
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