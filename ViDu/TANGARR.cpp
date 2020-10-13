#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#pragma GCC optimize("Ofast")
ll n, a[(ll) 1e7+7] ;

int main()
{
    giuncute;
    //ballolo;
    cin >> n ;
    for (ll i = 1 ; i <= n ; i++) cin >> a[i];
   sort(a+1,a+1+n);
    for (ll i = 1 ; i <= n ; i++) cout<< a[i] << " ";
}
