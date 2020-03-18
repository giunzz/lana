#include<bits/stdc++.h>

using namespace std;

int  n , a[1009] , ans;

int  UCLN(int  x , int  y){
        int  t = 0 ;
        while ( y  != 0 ){
            t = x % y ;
            x = y;
            y = t;
        }
        return x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TUCLN.inp","r",stdin);
    freopen("TUCLN.out","w",stdout);
    cin >> n ;

    for (int  i = 1 ; i <= n ; i++ ) cin >> a[i];
    ans = a[1];
    for (int  i = 2 ; i <= n ; i++ ) ans = UCLN(ans , a[i]);

    cout << ans ;
    return 0;
}

