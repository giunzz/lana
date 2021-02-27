#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#define ballolo freopen("tbcarr.inp","r",stdin),freopen("tbcarr.out","w",stdout);
#pragma GCC optimize("Ofast")
ll n;
double tb , sum = 0.0,a[(int) 1e5+7];

int main()
{
    giuncute;
    //ballolo;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i],sum += a[i];
    tb = sum / (double) n;
    cout << setprecision(2) << fixed << tb;

}

