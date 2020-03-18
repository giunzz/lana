// de thi 19-120 lqd

#include <iostream>
#include<stdio.h>

using namespace std;
const long maxn = 2e7 +8;
int  n , d = 0 ;   
char ch[maxn],c;
    int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);  
    freopen("xeptao.inp","r",stdin);
    freopen("xeptao.out","w",stdout);   
    cin >> n ;
    for (int i = 1 ; i <= n*2 ; i++) cin >> ch[i] ;
     c = ( ch[1] == '0' )? '1':'0';
    for (int i = 2 ; i <= n*2 ; i++){
        if (  ch[i-1] == c && ch[i] == c) d++;
    }
    cout << d;
    //cerr << clock() << " ms";
    return 0;
}
