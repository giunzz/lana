#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e5 + 5 ;
int n ;
ll a[N] ;
ll ans , sum ;
void update(int i , ll dm) {
    if(a[i] > dm) {
        ans += a[i] - dm;
        a[i+1] += a[i] - dm;
        a[i] = dm;
    }
    if(a[i] < dm) {
        ans += dm - a[i];
        a[i+1] -= dm - a[i];
        a[i] = dm;
    }
}
int main() {
    freopen("ARRANGE.inp" , "r" , stdin ) ; freopen("ARRANGE.out" , "w" , stdout ) ;
    //freopen("xx.inp" , "r" , stdin ) ; freopen("xx.out" , "w" , stdout ) ;
    //ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
    scanf("%d" , &n) ;
    for(int i = 1; i <= n; i++) scanf("%lld" , &a[i]);
    for(int i = 1; i <= n; i++) sum += a[i];
    ll dinh_muc = sum/n;
    ll dinh_muc1 = sum/n + 1;
    if(sum % n == 0) {
        for(int i = 1; i <= n; i++)  update(i , dinh_muc);
        printf("%lld" , ans);
        return 0;
    }

    ll k = sum - dinh_muc*n;
    int sl = 0 , sl1 = 0;
    for(int i = 1; i <= n; i++) {
        if(sl == n-k) {                 /// phai la dinh_muc1
            update(i , dinh_muc1);
            continue;
        }
        if(sl1 == k) {                  /// phai la dinh_muc
            update(i , dinh_muc);
            continue;
        }

        if(a[i] > dinh_muc1)  {
            update(i , dinh_muc1);
        }
        if(a[i] == dinh_muc1 && a[i+1] == dinh_muc-1 ) {
            ans ++ ;
            a[i]--;
            a[i+1]++;
        }

        if(a[i] < dinh_muc)  update(i , dinh_muc);

        if(a[i] == dinh_muc1) sl1++;
        else sl++;
    }
    printf("%lld" , ans);
    return 0 ;
}
