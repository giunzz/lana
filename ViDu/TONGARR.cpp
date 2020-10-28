#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#define ballolo freopen("tongarr.inp","r",stdin),freopen("tongarr.out","w",stdout);
#pragma GCC optimize("Ofast")
ll n, x , sum = 0 ;
int main()
{
    giuncute;
    //ballolo;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++) cin >> x , sum += x;
    cout << sum ;
}
