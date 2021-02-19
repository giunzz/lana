#include<stdio.h>

using namespace std;

long x = 0 , y = 0 , a , b;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    freopen("tim2so.inp","r",stdin);
    freopen("tim2so.out","w",stdout);
    scanf("%ld%ld",&a,&b);
    x = ( a + b ) / 2;
    y = ( a - b ) / 2;
    if ( x + y != a) printf("%d",-1);
    else printf("%ld %ld",x,y);
    return 0;
}