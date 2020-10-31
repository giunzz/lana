#include <iostream>
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define filename "MINSUM."
using namespace std;
int t,A,B;
void io()
{
    freopen(filename"INP","r",stdin);
    freopen(filename"OUT","w",stdout);
}
void solve(int a,int b)
{
    int aa=sqrt(a);
    int bb=sqrt(b);
    if(aa*aa==a&&bb*bb==b) {cout<<1<<" "<<1<<endl;return;}
    int sum=0;

    if(aa*aa==a&&bb*bb!=b)
    {
        int g=__gcd(a,b);
       int sum=min(1+b,(a+b)/g);
       if(sum==b+1) cout<<1<<" "<<b<<endl;
       else cout<<a/g<<" "<<b/g<<endl;
       return;
    }
    if(bb*bb==b&&aa*aa!=a)
    {
       int g=__gcd(a,b);
       int sum=min(1+a,(a+b)/g);
       if(sum==a+1) cout<<1<<" "<<b<<endl;
       else cout<<a/g<<" "<<b/g<<endl;
       return;
    }
    int g=__gcd(a,b);
    cout<<a/g<<" "<<b/g<<endl;
}
main()
{
    io();
    cin>>t;
    FOR(i,1,t)
    {
        cin>>A>>B;
        solve(A,B);
    }
}
