#include<bits/stdc++.h>
using namespace std;

long long s1 , s2 ,  i = 1 , n , MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    while ( (i % MOD *i % MOD) % MOD  <= n ){
        s1 = (i % MOD*i % MOD) % MOD;
        i++;
    }
    s2 = (i % MOD *i % MOD) % MOD;
    if ( n - s1 <= s2 - n ) cout << s1 ;
    else cout << s2;
    return 0;
}   