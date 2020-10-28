#include<bits/stdc++.h>
 using namespace std;
 #define ll long long
 #define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
 #pragma GCC optimize("Ofast")

  ll n , a[(int) 1e5 + 7 ]  , ans = 1 , d;

  int main()
 {
     giuncute;
     freopen("ucdn.inp","r",stdin);
     freopen("ucdn.out","w",stdout);
     cin >> n ;
     for (ll i = 1 ; i <= n ; i++) cin >> a[i];
     for (ll i = 1 ; i <= n ; i++)
     {
         d = a[i];
         for (ll j = i+1 ; j <= n ; j++)
         {
             d = __gcd(d,a[j]);
             if (d > 1 ) ans = max(ans,j-i+1);
             else
             {break;}
         }
     }
     cout << ans;
 }
