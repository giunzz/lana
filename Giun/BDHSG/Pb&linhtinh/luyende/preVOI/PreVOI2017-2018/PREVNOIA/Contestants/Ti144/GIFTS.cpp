#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e6 + 5 ;
const ll base = 1e15 + 7 ;
int n , k;
ll a[N] , r[N] , l[N] , t[N] ;
int main() {
    freopen("GIFTS.inp" , "r" , stdin ) ; freopen("GIFTS.out" , "w" , stdout ) ;
    //freopen("xx.inp" , "r" , stdin ) ; freopen("xx.out" , "w" , stdout ) ;
    //ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
    scanf("%d%d" , &n , &k);
    for(int i = 1; i <= n; i++) scanf("%lld" , &a[i]);
    for(int i = 1; i <= n; i++) t[i] = t[i-1] + a[i] ;//, cerr << t[i] << endl ;
    for(int i = 0; i <= n; i++) {
        l[i] = -base;
        if( i >= k)
            l[i] = max(l[i-1] , t[i] - t[i-k] );
            //cerr << i << " " << l[i] << endl ;
    }
    for(int i = n+1; i > 0; i--) {
        r[i] = -base;
        if(n-i+1 >= k)
            r[i] = max(r[i+1] , t[i+k-1] - t[i-1] );
    }
    ll ans = base;
    for(int i = 1; i <= n; i++) {
        if(n-i+1 <k) break;
        ans = min(ans , max(l[i-1] , r[i+k]));
    }
    printf("%lld" , ans);
    return 0 ;
}
