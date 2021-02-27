#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#define ballolo freopen("bai2.inp","r",stdin),freopen("bai2.out","w",stdout);
#pragma GCC optimize("Ofast")
ll n, x , sum = 0 ;

int main()
{
    giuncute;
    ballolo;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++) cin >> x , sum += x;
    cout << sum ;
} 