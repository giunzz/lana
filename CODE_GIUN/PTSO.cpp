#include<bits/stdc++.h>
using namespace std;

long n , a = 0 , b = 0 ;

int main(){
    freopen("giun.inp","r", stdin);
    freopen("giun.out","w",stdout);
    scanf("%ld", & n);
    n = n / 2;
    if (n % 2 != 0 ) a = n / 2 ,  b = n  / 2;
    else  a = n / 2 + 1 , b = n /2 -1;
    if ( a + b != n ) printf("%d",-1) ;
    else printf("%ld %ld", a, b);
    cerr << clock() << " ms";
}