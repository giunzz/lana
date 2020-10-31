#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define LL long long
using namespace std;
int A,B ,n;
LL k;
int main()
{
     ios::sync_with_stdio(0) ;
     cin.tie(0) ; cout.tie(0) ;
     freopen("MODULO.INP","r",stdin);
     freopen("MODULO.OUT","w",stdout);
     cin >> A >> B;
     cin >> n >> k;
     LL mod =1;
     FOR(i,1,n) mod= mod*2ll;
     LL sl = (1<<n)-1;
     if(n<=20){
         FOR(mask,0,sl) {
             LL kq = 0;
             FOR(i,0,n-1){
                 if( (mask>>i)&1 ) kq = (kq*10ll+A) %mod;
                 else kq = (kq*10ll+B) % mod;
             }
            if(kq==k) {
                    FOR(i,0,n-1) if( (mask>>i)&1 ) cout <<A;
                    else cout << B;
                    return 0;
            }
         }
         cout << -1;
         return 0;
     }
     FOR(mask,0,sl) {
             LL kq = 0;
             LL kq1= 0;
             FOR(i,0,n-1){
                 if( (mask>>i)&1 ) kq = (kq*10ll+A) %mod , kq1 = (kq1*10ll+B)%mod;
                 else kq = (kq*10ll+B) % mod , kq1 = (kq1*10ll+A)%mod;
             }
             if(kq==k) {
                    FOR(i,0,n-1) if( (mask>>i)&1 ) cout <<A;
                    else cout << B;
                    return 0;
             }
             if(kq1==k){
                    FOR(i,0,n-1) if( (mask>>i)&1 ) cout <<B;
                    else cout << A;
                    return 0;
             }
         }
         cout << -1;
         return 0;
}
