#include<bits/stdc++.h>
 using namespace std;
 #define ll long long
 #define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
 #pragma GCC optimize("Ofast")

  ll n , p , q , r ;0

  inline ll gett(ll x, ll &n)
 {
     ll dau = x;
     ll cuoi = n/dau*dau;
     return (cuoi - dau)/dau+1;
 }

  int main()
 {
     giuncute;
     freopen("DEMUOC.inp","r",stdin);
     freopen("DEMUOC.out","w",stdout);
     while (scanf("%lld%lld%lld%lld",&n,&p,&q,&r) == 4)
     {

     ll a = p*q/__gcd(p,q) , b =  p*r/__gcd(p,r) , c =  q*r/__gcd(q,r) , d = a*r /__gcd(a,r);
 /*   cerr << a << " " << b << " " << c << " " << d  << endl;
     ll a1 = a , b1 = b , c1 = c , d11 = d;
     for (int i = 1 ; i <= n ; i++)
     {

         if (a1  <= n ) d1 ++ , a1 +=a;
         if (b1  <= n ) d2 ++ , b1 +=b;
         if (c1  <= n ) d3 ++ , c1 +=c;
         if (d11  <= n ) d4 ++ , d11 +=d;
     }
     cerr << d1 << " " << d2 << " " << " " << d3 << " " << d4 << endl;
     cout << d1+d2+d3-3*d4;*/
     cout << gett(a,n) +  gett(b,n) + gett(c,n) - 3*gett(d,n) << endl;
     }
 }
