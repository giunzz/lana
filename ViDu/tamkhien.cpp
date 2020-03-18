#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
long a1,a2,b1,b2,c1,c2;
int main(){
    cin>>a1>>b1>>c1;
    cin>>a2>>b2>>c2;
    if(a1>b1) swap(a1,b1); if (a2>b2) swap(a2,b2);
    if(b1>c1) swap(b1,c1); if (b2>c2) swap(b2,c2);
    cout<<a1<<b1<<c1<<" "<<a2<<b2<<c2;
    cout<<endl;
    if (c2>c1) cout<<a1+a2+b1+b2+(c2-c1);
    else cout<<a2+a1+b1+b2+(c1-c2)<<endl;
    return 0;
    }
