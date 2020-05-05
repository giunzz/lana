//#include<bits/stdc++.h>
#include<cstdio>
#include<ctime>
#include<iostream>
using namespace std;

long n , a = 0 , b = 0 , mi = 100000008, j , i = 1;

int main(){
    freopen("PTSO.txt","r", stdin);
    freopen("PTSOt.txt","w",stdout);
    scanf("%ld", & n);

    if (n % 2 == 0 ) j = n - 1;
    else j = n ;
    while ( j >= i  ){
        if (i + j == n && j - i < mi) {
            mi = j - i;
            a = j ;
            b = i;
        }
        i += 2 , j -= 2;
    }
    if ( a == 0 && b == 0 ) printf("%d",-1) ;
    else printf("%ld %ld", a, b);
    cerr << clock() << " ms";
}