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
#define task "BUBBLETEA"
typedef long long ll ;
typedef pair<int,int> II ;
typedef pair <int, pair <int, int> > III;
const int N = 1e5 + 5 ;
const ll base = 1e9 + 7 ;
int n , k;
int a[N] , u[N] , v[N] , c[N] , r[N] ;
ll kc[333][333] ;
ll ans ;

void tr(int x , int k1) {
    if(x > k) {
        ll an = -base ;
        For(i , 1 , k) if(i%2 == 0) an = max(an , kc[ r[i] ][ r[i-1] ]);
        ans = min(ans , an);
    }
    for(int i = k1; i<= n; i++) {
        r[x] = i;
        tr(x+1 , i+1);
    }
}

int main() {
    freopen(task".inp" , "r" , stdin ) ; freopen(task".out" , "w" , stdout ) ;
    //ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
    scanf("%d%d" , &n , &k);
    for(int i = 1; i <= k; i++) scanf("%d" , &a[i]);
    //int u , v , c;
    for(int i = 1; i < n; i++)
        scanf("%d%d%d" , &u[i] , &v[i] , &c[i]) ;//, cerr << u[i] << " " << v[i] << " " << c[i] << endl ;;
    if( k <= 10) {
        ans = base;
        memset(kc , 0x3f , sizeof(kc));
        for(int i = 1; i < n; i++) kc[ u[i] ][ v[i] ] = kc[ v[i] ][ u[i] ] = c[i];
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        for(int z = 1; z <= n; z++)
            kc[i][j] = min(kc[i][j] , kc[i][z] + kc[z][j]);
        //for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++) cerr << i << " " << j << " " << kc[i][j] << endl ;

        tr(1 , 1);

        printf("%lld" , ans);
        return 0;
    }

    return 0 ;
}
