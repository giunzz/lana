#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 1e6+7;
//ll n , l[maxn] , dp_left[maxn] = {0} , x[maxn] , dp_right[maxn] = {0} , y[maxn];
ll n , x , sum[maxn];
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    // cin >> n ; 
    // for (int i = 1 ; i <= n ; i++) cin >> x[i] , y[i] = x[i] , x[i] += x[i-1] ; 
    // for (int i = n ; i >= 1 ; i--) y[i] += y[i-1];
    // for (int i = 1 ; i <= n ; i++) dp_left[i]  = dp_left[i-1] + x[i-1] ;
    // for (int i = n ; i >= 1 ; i-- ) dp_right[i] = dp_right[i+1] + y[i+1];
    // ll ans = dp_left[1] + dp_right[1] , vt = 1;
    // for (int i = 2 ; i <= n ; i++)
    //     if (ans >= dp_left[i] + dp_right[i]) ans = dp_left[i] + dp_right[i] , vt = i ;
    // cout << vt ;
    cin >> n ; 
    for (int i= 1 ; i <= n ; i++) cin >> sum[i] , sum[i] += sum[i-1];
    cout << (lower_bound(sum + 1 , sum + 1 + n , sum[n] / 2 + 1) - sum );
}
