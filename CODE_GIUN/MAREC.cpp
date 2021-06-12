#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 1e3 + 7  ;

ll n , x , C[10][maxn] = {0} , ma = 0 , dd[maxn] = {0} , ans = 0 ;

int main()
{
    giuncute;
//    freopen("giun.inp","r",stdin);
//    freopen("giun.out","w",stdout);
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) cin >> x  , dd[x]++;
    for (int i = 1 ; i <= 1000 ; i++)
    {
        if (dd[i] % 4 == 0 && dd[i] >= 4) ans ++ ;
        else if (dd[i] >= 2 ) ma = max(ma , dd[i]);
    }
    if (ma != 0)
    {
        for (ll i = 1 ; i <= ma; i++)  C[0][i] = 1;
        C[1][1] = 1;
        for (int i = 1 ; i <= 2 ; i++)
        {
            for (int j = 1 ; j <= ma ; j++)
            {
                if ( i == j ) C[i][j] = 1 ;
                C[i][j] = C[i][j-1] + C[i-1][j-1];
            }
        }
        ans += C[2][ma];
    
    }
    cout << ans;
}