#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long maxn = 1e8+9;
long n,a[maxn]={0},t,x;
/*int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("iii.inp","r",stdin);
    freopen("iii.out","w",stdout);
    //cin >> n ;
    scanf("%ld",&n);
    for (long i = 1 ; i<= n ; i++){
        scanf("%ld",&t) ;
        if ( t >= 0 ) a[t] = 1;
        //cerr << t << " " << a[t] << endl;
    }
    for (long i= 1 ; i<= maxn ; i++)
        if (a[i] == 0 ) {
                printf("%ld",i);
                break;
        }
    return 0;
}*/

int main (){
    freopen("iii.inp","r",stdin);
    freopen("iii.out","w",stdout);
    scanf("%ld",&n);
    for (int i = 1 ; i <= n; i++ ) scanf("%ld",& a[i]);
    sort(a + 1 , a + n+ 1 );
    for (int i=1 ; i<= n ; i++) cerr << a[i] << " ";
    t = a[1];
    for (int i = 1 ; i <= n ; i++){
                if(a[i] == lt ) ++t;
                else if (a[i] - t >= 1 ) {
                        cout << t;
                        return 0;
                }
    }
}


