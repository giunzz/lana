#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#define ballolo freopen("bai4.inp","r",stdin),freopen("bai4.out","w",stdout);
#pragma GCC optimize("Ofast")
ll n, x , ans ;

int main()
{
    giuncute;
    ballolo;
    cin >> n >> x;
    ans = x;
    for (ll i = 2 ; i <= n ; i++) 
    {
        cin >> x ;
        if (ans < x) ans = x;
    } 
    cout << ans;
} 