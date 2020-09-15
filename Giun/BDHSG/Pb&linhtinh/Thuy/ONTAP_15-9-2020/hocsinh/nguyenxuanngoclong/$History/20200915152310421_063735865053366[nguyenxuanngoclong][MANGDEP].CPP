#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

long long n,b;
long long a[1000006];
long long kt[50];

int main()
{
    freopen("MANGDEP.INP","r",stdin);
    freopen("MANGDEP.OUT","w",stdout);
    cin>>n;
    //4,8,15,16,23,42;
    b=200005;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        kt[a[i]]+=1;
    }
    kt[1]=kt[4];
    kt[2]=kt[8];
    kt[3]=kt[15];
    kt[4]=kt[16];
    kt[5]=kt[23];
    kt[6]=kt[42];
    for(int i=1;i<=6;i++)
    {
        b=min(b,kt[i]);
    }
    cout<<n-(b*6);


return 0;
}
