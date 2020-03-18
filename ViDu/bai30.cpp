#include<bits/stdc++.h>

using namespace std;

long n , k   ;

long tach (long  n ){
    long x ,y  ;
    if (((k + n) % 2 != 0) || ( k >= n )  ) return 1;
    else
    {
        x = ( n + k ) / 2;
        y = ( n - k ) / 2;
        return tach(x) + tach(y);
    }
    }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI30.inp","r",stdin);
    freopen("BAI30.out","w",stdout);
    scanf("%ld%ld",&n,&k);

    cout << tach(n);
    cerr << clock() << " ms";
    return 0;
}
