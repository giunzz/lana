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

#define maxN 100005

int n , a[maxN];

void enter () {
    scanf("%d"  , &n) ;
    forinc(i,1,n) scanf("%d" , &a[i]) ;
}

long long sum = 0 , each = 0 , sh = 0  ;

void prepare () {
    forinc(i,1,n) sum += a[i] ;
    each = sum / n ; sh = sum % n ;
}

void process () {
    prepare () ;
    long long res = 0 ;
    forinc(i,1,n) if (a[i] < each) {
        int t1 = i - 1 , t2 = i + 1 ;
        while ((t1 > 0 || t2 <= n) && (a[i] < each)) {
            if (t1 > 0 && a[t1] > each && a[i] < each) {
                int w = min(a[t1] - each , each - a[i]) ;
                a[i]+= w ; a[t1] -= w ; res += (long long) w * abs(i - t1) ;
            }
            if (t2 <= n && a[t2] > each && a[i] < each) {
                int w = min(a[t2] - each , each - a[i]) ;
                a[i] += w ; a[t2] -= w ; res += (long long) w * abs(i - t2) ;
            }
            t1 -- ; t2 ++ ;
        }
    }
    if (sum % n != 0) {
        forinc(i,1,n) if (a[i] > each + 1) {
            int t1 = i - 1 , t2 = i + 1 ;
            while ((t1 > 0 && t2 <= n) && a[i] > each + 1) {
                if (t1 > 0 && a[t1] <= each && a[i] > each + 1) {
                    int w = min(each - a[t1] + 1 , a[i] - each - 1) ;
                    a[t1] += w ; a[i] -= w ; res += (long long) w * abs(i - t1) ;
                }
                if (t2 <= n && a[t2] <= each && a[i] > each + 1) {
                    int w = min(each + 1 - a[t2] , a[i] - each - 1) ;
                    a[t2] += w ; a[i] -= w ; res += (long long) w * abs(i - t2) ;
                }
                t1 -- ; t2 ++ ;
            }
        }
    }

    cout << res << endl ;
}

int main () {
    freopen("ARRANGE.inp" , "r" , stdin) ;
    freopen("ARRANGE.out" , "w" , stdout) ;
    enter () ;
    process () ;
    return 0  ;
}
