#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+3;
int  n , d = 0;
long a[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("tamgiac.inp","r",stdin);
    freopen("tamgiac.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a+1,n+a+1);
    for (int i = n ; i >= 3 ; i--) {
        if ( a[i-2] + a[i-1] >= a[i] ) {
            cout << a[i] <<" " <<  a[i-1] << " " << a[i-2];
            d++;
            break;
        }
    }
    if ( d == 0 ) cout << -1;
    return 0;
} 