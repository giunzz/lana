#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
#pragma GCC optimize("Ofast")
#define ballolo freopen("ducln.inp","r",stdin),freopen("ducln.out","w",stdout)
using namespace std;
ll n , a[(int) 1e5 + 7] , u = 0,i ;
 int main()
 {
     giuncute;
     ballolo;
     cin >> n;
     for (int i = 1 ; i <= n ; i++)
     {
         cin >> a[i];
     }

     u=__gcd(a[1],a[2]);
     for (i=3;i<=n;i++) u=__gcd(u,a[i]);


     cout << u ;
 }



