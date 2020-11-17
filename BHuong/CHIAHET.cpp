#include<bits/stdc++.h>

using namespace std;

long long n , a[10009] , d[10009]={0} , ans = 0 , vt ;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("chiahet.inp","r",stdin);
    freopen("chiahet.out","w",stdout);

    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];

    for (int i = 1 ; i <= n  ; i++){
        for (int j =  1 ; j <= n ; j++)
            if ( a[j] % a[i] == 0 && j != i ) d[i]++;
    }
    for (int i = 1 ; i <= n ; i++)
        if ( ans < d[i] ) ans = d[i] , vt = a[i];

    if (ans == 0 ) cout <<-1 ;
    else cout << vt << " " << ans ;
    return 0;
}
