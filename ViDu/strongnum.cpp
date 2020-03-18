#include<stdio.h>
#include<iostream>
using namespace std;

long giaiThua(int k)
{   long s=1;
    for(int i = 1 ; i <= k ; i++ ) s=s*i;
    return s;
}
int n,Sum=0,i,x,d,p;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    freopen("STRONGNUM.INP","r",stdin);
    freopen("STRONGNUM.OUT","w",stdout);
    cin >> n;
    for( i=1; i<= n ; i++){
        p=i;
        while (p != 0) {
            x = p % 10;
            Sum = Sum + giaiThua(x);
            p = p / 10;
        }
            if (Sum == i ) d++;
            Sum = 0;
    }
    cout << d;
    return 0;
}