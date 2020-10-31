#include <bits/stdc++.h>
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++)
#define fordec(i,a,b) for (int i = a ; i >= b ; i --)
#define forv(j,u) for (int j = 0 ; j < u.size() ; j++)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>
#define ooll (long long) 1e15
#define ooit (int) 2e9

template <class _T> bool maximize(_T &a , _T b) {return a < b ? a = b , 1 : 0 ; }
template <class _T> bool minimize(_T &a , _T b) {return a > b ? a = b , 1 : 0 ; }

using namespace std ;

#define maxN 1000005

int n , k , a[maxN] ;

int fastRead() {
    int res = 0 ; char c ;
    for (c = getchar() ; c < '0' || c > '9' ; c = getchar()) ;
    for ( ; c >= '0' && c <= '9' ; c = getchar()) res *= 10 , res += (int) c - (int) '0' ;
    return res ;
}

void enter () {
    n = fastRead() ; k = fastRead() ;
    forinc(i,1,n) a[i] = fastRead() ;
}

long long f[maxN] , cleft[maxN] , cright[maxN] ;

void prepare () {
    forinc(i,1,n) f[i] = f[i-1] + a[i] ;
    forinc(i,k,n) cleft[i] = max(cleft[i-1],f[i] - f[i-k]) ;
    fordec(i,n-k+1,1) cright[i] = max(cright[i+1],f[i+k-1] - f[i-1]) ;
}

void process () {
    prepare () ;
    long long res = ooll ;
    forinc(i,k,n) minimize(res,max(cleft[max(0,i-k)] , cright[i+1])) ;
    cout << res << endl ;
}

int main () {
    freopen("GIFTS.inp" , "r" , stdin) ;
    freopen("GIFTS.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0 ;
}
