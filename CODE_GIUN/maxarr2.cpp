#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#define ballolo freopen("maxarr2.inp","r",stdin),freopen("maxarr2.out","w",stdout);
#pragma GCC optimize("Ofast")
ll n , a[(int) 1e5+7], sum = 0;

int main()
{
    giuncute;
    //ballolo;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sum = a[1]+a[2];
    for (int i = 2 ; i <= n ; i++) sum = max(sum,a[i]+a[i+1]);
    cout << sum ;

}
