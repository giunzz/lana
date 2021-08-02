#include <bits/stdc++.h>
#define ll int
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e5 +  7;
const double esp = 1e-9;
using namespace std;
ll n , x[maxn] , y[maxn] , ans = 0 ;

ll dis (ll a , ll b , ll a1 , ll b1)
{
    return (a - a1) * (a - a1) + (b - b1)* (b-b1);
}
int main()
{
    giuncute;
    freopen("giun.inp" ,"r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> n ;
    for (int i = 0 ; i < n ; i++) scanf( %ld, &x[i]) , scanf(%ld , &y[i]);
    ll j = 0 , tmp;
    for (int i = 0 ; i < n ; i++)
    {
        tmp = (j + 1) % n ;
        //ll t = dis (x[i] , y[i] , x[(j + 1) % n ] , y[(j + 1) % n ]);
        //ll t1 = dis (x[i] , y[i] , x[j] , y[j] );
        while (dis (x[i] , y[i] , x[tmp] , y[tmp]) >= dis (x[i] , y[i] , x[j] , y[j] ) )
        {

            //t = dis (x[i] , y[i] , x[(j + 1) % n ] , y[(j + 1) % n ]);
            //t1 = dis (x[i] , y[i] , x[j] , y[j] );
            j = tmp;
            tmp = (j + 1) % n;
        } 
        ans = max (ans , dis (x[i] , y[i] , x[j] , y[j]) );
    }
    cout << fixed << setprecision(4) << ans;
}