#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

long long n,c;
long long a[1000006];
long long kt[10];
bool b[1000006];

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
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=true;
    }
    c=1;
    int j=1;
    while (j<=100)
    {
        for(int i=1;i<=n;i++)
        {
            if ( kt[c]==a[i] )
            {
                if(b[c]==true)
                {
                    b[c]=false;
                    c++;
                    if(c==7)c=1;
                }
            }
        }
        j++;
    }
    c=0;
    for(int i=1;i<=n;i++)
    {
        if(b[c]==true)c++;
    }
    cout<<c;
return 0;
}
