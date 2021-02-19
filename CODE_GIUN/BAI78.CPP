#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int m,n;
int dd(int a){
    int  t;
    int a1 = 0;
    while(a > 0){
        t = a % 10;
        a1 = a1 * 10 + t;
        a = a / 10;
    }
    return a1;
}
 int main (){
    freopen("BAI78.INP","r",stdin);
    freopen("BAI78.OUT", "w", stdout);
    cin>>m>>n;
    cout<<dd(m)-dd(n);
    return 0;
 }

