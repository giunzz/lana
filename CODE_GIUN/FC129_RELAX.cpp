#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll maxa = 6e6 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , x , xr[5][maxa] = {{0}};

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    xr[1][0] = 1;
    ll tmp = 0 , ans = 0 ;
    for (int i = 0 ; i < n ; i++) 
    {
        cin >> x;
        tmp = tmp ^ x;
        cerr << tmp << " ";
        if (i % 2 == 0 ) ans += xr[0][tmp] , ++xr[0][tmp];
        else ans += xr[1][tmp] , ++xr[1][tmp];
    }
    cout << ans;
}
