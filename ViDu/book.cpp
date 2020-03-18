#include<bits/stdc++.h>

using namespace std;

long t , ans = 0 ,S = 0, n ,a [(int) 1e5+8]   ;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("book.inp","r",stdin);
    freopen("book.out","w",stdout);

    cin >> n >> t ;
    for (int i = 1 ; i <= n ; i++ ) cin >> a[i];

    long i = 1, j = 1;

    while (j  <= n  ){
        S += a[j];
        while ( S > t  ) {
                S = S-a[i];
                ans = max(ans , j - i);
                ++i;
        }
        j++;
}

    if (j > n) ans = max (ans, j - i);
    cout << ans ;
    return 0;
}
