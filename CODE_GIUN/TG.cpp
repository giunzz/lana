#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+3;
int n ;
long a[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("tamgiac.inp","r",stdin);
    freopen("tamgiac.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a+1,n+a+1);
   // for (int i = 1 ; i <= n ; i++) cerr << a[i] << " ";
    if ( a[n-2] + a[n-1] > a[n] ) cout << a[n] <<" " <<  a[n-1] << " " << a[n-2];
    else cout << -1;
    return 0;
} 