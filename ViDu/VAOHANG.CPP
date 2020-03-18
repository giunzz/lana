#include<bits/stdc++.h>
using namespace std;
long n, a[(long)1e5+9], y[(long)1e5+9], d=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("VAOHANG.INP","r",stdin);
    freopen("VAOHANG.OUT","w",stdout);
    scanf("%ld",&n);
    for (long i=1 ; i<= n ; i++) scanf("%ld",&a[i]);
    for (long i=1 ; i<= n ; i++) scanf("%ld",&y[i]);
        sort(a+1,a+n+1);
        sort(y+1,y+n+1);
    for (long i=1 ; i<= n ; i++){
         d=max(d,abs(a[i]-y[i]));
    }
    printf("%ld",d);
    return 0;
}
