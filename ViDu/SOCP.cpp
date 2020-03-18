#include<stdio.h>
#include<iostream>
#include<ctime>    
using namespace std;

long long s1 , s2 ,  i = 1;
long n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    freopen("socp.inp","r",stdin);
    freopen("socp.out","w",stdout);
    cin >> n;

    while ( i*i  <= n ){
        s1 = i*i;
        i++;
    }
    s2 = i*i;
    if ( n - s1 <= s2 - n ) cout << s1 ;
    else cout << s2;
    //cerr << clock() << " ms";
    return 0;
}