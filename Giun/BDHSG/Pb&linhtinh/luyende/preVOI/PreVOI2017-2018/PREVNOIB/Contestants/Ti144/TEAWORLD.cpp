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
#define task "TEAWORLD"
typedef long long ll ;
typedef pair<float,ll> II ;
typedef pair <int, pair <int, int> > III;
const int N = 1e5 + 5 ;
const ll base = 1e15 + 7 ;
int n , m , k;
ll e[N] ;
float cx[N] , cy[N] , cz[N] , r[N] , teax[N] , teay[N] , teaz[N] ;
float xs , ys , zs;
bool kt1 , kt2 ;
II b[N] ;

void up_kt(float a , float b) {
    if(a != 0 || b != 0) kt1 = false;
    if(b != 0) kt2 = false;
}

int main() {
    freopen(task".inp" , "r" , stdin ) ; freopen(task".out" , "w" , stdout ) ;
    //ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
    scanf("%d%d%d" , &m , &n , &k);
    kt1 = true , kt2 = true;
    for(int i = 1; i <= m; i++) {
        scanf("%f%f%f%f" , &cx[i] , &cy[i] , &cz[i] , &r[i] );
        up_kt(cy[i] , cz[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%f%f%f%lld" , &teax[i] , &teay[i] , &teaz[i] , &e[i] );
        up_kt(teay[i] , teaz[i]);
    }
    scanf("%f%f%f" , &xs , &ys , &zs);
    up_kt(ys , zs);

    if(kt1) {
        int sl = 0;
        float left , right ;
        right = base;
        left = -base;
        bool kt = false;
        for(int i = 1; i <= m; i++) {
            if(cx[i] + r[i] >= xs && cx[i] - r[i] <= xs ) {
                left = max(left , cx[i] - r[i]);
                right = min(right , cx[i] + r[i]);
                kt = true;
            }
        }
        if(kt) {    // n trong
            //cerr << " n trong " << left << " " << right << endl ;
            ll ans = 0;
            for(int i = 1; i<= n; i++)
                if(teax[i] >= left && teax[i] <= right ) ans += e[i];
            printf("%lld" , ans);
            return 0;
        }
        // n ngoai
        for(int i = 1; i <= m; i++) if(r[i] > 0 ) b[++sl] = II(cx[i] , 1); // 1 cam
        for(int i = 1; i <= n; i++) b[++sl] = II(teax[i] , -e[i]);
        b[++sl] = II(xs , 2);
        sort(b+1 , b+sl+1);
        int i = 1;
        ll ans = 0;
        for( ; i <= sl; i++) {
            if(b[i].S == 2) break;
            if( b[i].F == 1) ans = 0;
            else ans += -b[i].S ;
        }
        i++;
        while(b[i].S != 1 && i <= sl) ans += -b[i].S , i++ ;
        printf("%lld" , ans);
        return 0;
    }
    return 0 ;
}
