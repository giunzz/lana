#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
cll maxn = 2007;
using namespace std;
ll n , t , m , u , v , b[maxn][maxn] , sum = 0;
ll check(ll i)
{
    int dem = 0 ;
    for (int j = 1; j <= n ; j++)
        if(b[i][j] == 1) dem++;
    return dem;
}
int main()
{
    giuncute;
    freopen("chuyen03.inp","r",stdin);
    freopen("chuyen03.out","w",stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v ;
        b[u][v] = 1  , b[v][u] = 1;
    }
    cout << 0 <<" ";
    for (int i = 1 ; i <= n ; i++) sum += check(i) , cout << sum << " ";
    cout<<endl;
    for(int i = 1; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
            if (b[i][j] == 1) cout << j << " ";
    }
}