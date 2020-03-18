#include<bits/stdc++.h>

using namespace std;

long n , a[109] , i = 1 , j = 2 , ans = 0, u;

long UCLN(long x , long y){
        long t = 0 ;
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
    freopen("Bai40.inp","r",stdin);
    freopen("Bai40.out","w",stdout);
    cin >> n ;

    for (int  i = 1 ; i <= n ; i++ ) cin >> a[i];
    i = 1;
    u = a[1];
    while (j  <= n  ){
         u = UCLN (u,a[j]);
              if ( u  == 1  ) {

                ans = max(ans , j - i);

                i = j;
                u = a[j];

                while( u != 1 && i > 0) {
                    u = UCLN(u , a[--i]);
                }
                ++i;

        }
        j++;
}

    if (j > n) ans = max (ans, j - i);
     cout << ans;
     return 0;
}


