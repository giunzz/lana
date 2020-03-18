#include<stdio.h>

using namespace std;

long s = 0 , n , vt ;

int main(){
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    freopen("danhso.inp","r",stdin);
    freopen("danhso.out","w",stdout);
    
    scanf("%ld",&n);
    long i = 0 ;
    while (s <= n ){
        i = i + 1;
        s += i ;
    }
    printf("%ld",i);
  //fprintf(stderr, "%d ms", clock());
    return 0;
}