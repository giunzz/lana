#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

long long n,c,d;
long long a[1000006];
long long kt[50];
long long b[1000006];

void kt1()
{
    kt[1]=4;
    kt[2]=8;
    kt[3]=15;
    kt[4]=16;
    kt[5]=23;
    kt[6]=42;
}

int main()
{
    freopen("MANGDEP.INP","r",stdin);
    freopen("MANGDEP.OUT","w",stdout);
    cin>>n;
    //4,8,15,16,23,42;
    kt1();
    c=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==kt[1])b[1]++;
        else if(a[i]==kt[2]&&b[2]<b[1])b[2]++;
        else if(a[i]==kt[3]&&b[3]<b[2])b[3]++;
        else if(a[i]==kt[4]&&b[4]<b[3])b[4]++;
        else if(a[i]==kt[5]&&b[5]<b[4])b[5]++;
        else if(a[i]==kt[6]&&b[6]<b[5])b[6]++;
        else    c++;
    }
    d=min(b[1],min(b[2],min(b[3],min(b[4],min(b[5],b[6])))));
    cout<<n-(d*6);


return 0;
}
