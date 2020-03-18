#include<bits/stdc++.h>

using namespace std;

int a[109] , l[109] = {0} , lmax , n ,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    l[1] = 1;
    // quy hoach dong
    for (int i = 2 ; i <= n ; i++){
        lmax = 0;
        for (int j = 1 ; j < i ; j++){
            if ( a[i] > a[j] ) lmax = max(lmax,l[j]);
        }
        l[i] = lmax + 1;
    }
   /* for (int i = 1 ; i<= n ; i++) cerr << a[i] <<"  ";
    cerr << endl;
    for (int i = 1 ; i <= n ;i++) cerr << l[i] <<"  ";*/

    for (int i = 1 ; i <= n ; i++) ans = max (ans , l[i]);
    cout << ans ; 
    return 0;
}