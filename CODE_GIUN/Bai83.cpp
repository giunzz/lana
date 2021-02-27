#include<bits/stdc++.h>

using namespace std;

const long long maxn = 5e4+9;
long long socso (long long n ){
    long long t = 0;
    while (n > 0){
    n = n/ 10;
    t++;
    }
    return t;
}

/*long dao (int n ){
    long s = socso(n);
    int dv = n % 10;
    n = n / 10;
    for (long i = 1 ; i < s ; i++) dv = dv*10;
    long m = dv + n;
    return m;
}

int main (){
    long n ,nmax , d;
    int c = 0, ans;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Bai83.inp","r", stdin);
    freopen("Bai83.out","w",stdout);

    cin >> n;
    nmax = n;
    d = socso(n);

    for (long i = 1 ; i < d ; i++){
        n = dao (n);
        //cerr << n << endl ;
        c++;
        if (n > nmax ){
            nmax = n ;
            ans = c;
        //cerr << c << endl;
        }
    }
    cout << ans;
    return 0;
}*/

int main(){
    long long a[maxn] , n , ans , d ,ma;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Bai83.inp","r", stdin);
    freopen("Bai83.out","w",stdout);

    cin >> n ;
    d = socso(n);
    a[0] = n ;
    for (long long i = 1 ; i < d ; i++){
        a[i] = (a[i-1] % 10) *((long long )pow(10,d-1)) + (a[i-1]/10) ;
    }
    ma = a[0];
    for (long long i = 1 ; i < d ; i++){
        //cerr << a[i] << endl ;
        if ( a[i] > ma ){
         ans = i;
         ma = a[i];
    }
    }
    cout << ans;
    return 0;
}


