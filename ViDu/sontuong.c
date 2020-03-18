#include <cmath>
#include<cstido>
#include<iostream>
#include <algorithm>
using mamespace;
int a,b,c,d;
 int main(){
     cin>>a,b;
     cin>>c,d;
     if (b<d){
        swap(b,d);
        swap(a,c);
     }
     cout<<a,b,c,d;
     if(b>d) cout<<d-a;
     else cout<<b-a;
     if(c<d<a<b) cout<<(d-a)+(b-a);
     return 0;
 }

