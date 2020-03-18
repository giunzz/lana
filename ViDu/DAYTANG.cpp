#include<bits/stdc++.h>

using namespace std;

int  n, a [(int) 1e6+8] , vt = 0  ;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Daytang.inp","r",stdin);
    freopen("Daytang.out","w",stdout);
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i < n ; i++){
        if (a[i ] < a[i + 1]) vt = 0;
        else {
            vt = i +1 ; 
            break ;
        }
    }
    cout << vt;
    return 0;
}