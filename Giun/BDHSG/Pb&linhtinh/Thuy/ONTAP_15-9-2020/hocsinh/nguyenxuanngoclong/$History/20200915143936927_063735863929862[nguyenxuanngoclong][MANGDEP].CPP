#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

long long n,b;
long long a[1000006];
long long sosanh[10];
void mang()
{
    sosanh[1]=4;
    sosanh[2]=8;
    sosanh[3]=15;
    sosanh[4]=16;
    sosanh[5]=23;
    sosanh[6]=42;
}

int main()
{
    freopen("MANGDEP.INP","r",stdin);
    freopen("MANGDEP.OUT","w",stdout);
    cin>>n;
    mang();
    b=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(sosanh[b]==a[i])b++;
    }

    if (b==7)
    {
        if (n%6 == 0)cout<<0;
        else cout<<n%6;
    }
    else
    {
        cout<<n;
    }

return 0;
}
