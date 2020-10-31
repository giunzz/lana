#include<bits/stdc++.h>
using namespace std ;
#define For(i,a,b) for(int i = (a) , _b = (b) ; i <= _b ; i++ )
#define Ford(i,a,b) for(int i = (a) , _b = (b) ; i >= _b ; i-- )
#define F first
#define S second
#define MK make_pair
#define PB push_back
#define PF push_front
//#define task "xx"
#define task "MINSUM"
typedef long long ll ;
typedef pair<int,int> II ;
typedef pair <int, pair <int, int> > III;
const int N = 1e5 + 5 ;
const int maxn = sqrtl(1e9) + 5;
const ll base = 1e19 + 7 ;
int t ;
ll a , b;
int d[maxn + 100] , d1[maxn + 100] , an[maxn + 100];
int main() {
    freopen(task".inp" , "r" , stdin ) ; freopen(task".out" , "w" , stdout ) ;
    //ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
    scanf("%d" , &t);
    //cerr << maxn * maxn << endl ;
    while(t--) {
        scanf("%lld%lld" , &a, &b);
        memset(d , 0 , sizeof(d)) ;
        memset(d1 , 0 , sizeof(d1)) ;
        for(int i = 2; i <= maxn; i++) {
            while(a%i == 0) d[i]++ , a/=i;
            while(b%i == 0) d1[i]++ , b/=i;
        }
        int sl = 0;
        for(int i = 2; i <= maxn; i++) if( (d[i] + d1[i]) % 2 ) sl++ , an[sl] = i;
        if( a != b) {
            sl++ , an[sl] = a;
            sl++ , an[sl] = b;
        }

        ll ans = base , vt_a , vt_b ;
        for(int mask = 0; mask < (1<<sl); mask++) {
            ll ansa = 1 ,  ansb = 1;
            for(int i = 0; i < sl; i++) {
                if( (mask>>i)&1 ) ansa *= an[i+1];
                else ansb *= an[i+1];
            }
            if(ans > ansa + ansb) {
                ans = ansa +ansb ;
                vt_a = ansa;
                vt_b = ansb;
            }
        }
        if(ans == base) ans = 2 , vt_a = vt_b = 1;
        printf("%lld %lld\n" , vt_a , vt_b);
    }
    return 0 ;
}
