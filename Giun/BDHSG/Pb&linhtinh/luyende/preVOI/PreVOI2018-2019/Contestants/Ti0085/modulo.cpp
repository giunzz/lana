#include <iostream>
#include <bits/stdc++.h>
#define fi "modulo.inp"
#define fo "modulo.out"

using namespace std;
int a,b,n,k; int64_t pi;
int x[25], res[25]; bool kt;

void nhap()
{
    scanf("%d%d",&a,&b);
    scanf("%d%d",&n,&k);
    pi=1;
    for(int i=1; i<=n; ++i) pi=pi*2;
}
void xuli1()
{
    int64_t kq=0;
    for(int i=1; i<=n; ++i)
    {
        if(x[i]==0) kq=kq*10+a;
        else kq=kq*10+b;
    }
    if(kq % pi == k)
    {
        for(int i=1; i<=n; ++i) res[i]=x[i];
        kt=true;
    }
}
void tryhard(int i)
{
    for(int h=0; h<=1; ++h)
    {
        x[i]=h;
        if(i==n)
        { xuli1(); if(kt==true) return; }
        else tryhard(i+1);
    }
}
void sub1()
{
    kt=false;
    tryhard(1);
    if(kt==false) cout<<-1;
    else
    {
        for(int i=1; i<=n; ++i)
        {
            if(res[i]==0)printf("%d",a);
            else printf("%d",b);
        }
    }
}
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    nhap();
    sub1();
}
