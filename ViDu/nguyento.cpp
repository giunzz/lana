#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long b,a[100000009];
bool sang[10000000+7];

void  ss(){
    long i , j;
     for ( i=2; i<=10000000; i++) {
         sang[i]=true;
     }
    sang[0]=false;
    sang[1]=false;
     for (i=2; i*i<=10000000; i++){
         if  (sang[i]==true) {
             for(  j=i*i; j<= 10000000; j+=i);{
                 sang[j]=false;
             }
         }
     }
}
int main(){
    cin>>b;
    ss();
    for (int i=1; i<=b ; i++) {
        cin>>a[i];
        if (sang[a[i]]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
    return 0;
}

