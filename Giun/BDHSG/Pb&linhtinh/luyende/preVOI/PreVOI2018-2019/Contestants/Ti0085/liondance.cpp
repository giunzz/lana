#include <iostream>
#include <bits/stdc++.h>
#define fi "liondance.inp"
#define fo "liondance.out"
#define maxn 30
using namespace std;
int n,k,d,tg,minn,maxx;
int a[maxn], b[maxn], x[maxn], y[maxn], kq1[maxn], kq2[maxn], ans[maxn];
void nhap()
{
    cin>>n>>k;
    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=1; i<=n; ++i) cin>>b[i];
}
void xuli2()
{
    tg=0;
    for(int i=1; i<=n; ++i)
    {
        if(y[i]==1)
        {
            ++tg;
            kq2[tg]=b[i];
        }
    }
    bool kt=true;
    if(d==tg)
    {
        for(int i=1; i<=d; ++i)
        {
            if(kq1[i]!=kq2[i]) kt=false;
        }
        if(kt==true)
        {
            if(d > maxx)
            {
                maxx=d;
                for(int j=1; j<=d; ++j)
                {
                    ans[j]=kq1[j];
                }
            }
            else if(d==maxx)
            {
                int dem=0;
                for(int j=1; j<=d; ++j)
                {
                    if(kq1[j] >= ans[j]) ++dem;
                    else break;
                }
                if(dem >= minn)
                {
                    minn=dem;
                    for(int j=1; j<=d; ++j)
                    {
                    ans[j]=kq1[j];
                    }
                }
            }
        }
    }
}
void try2(int i)
{
    for(int t=0; t<=1; ++t)
    {
        y[i]=t;
        if(i==n) xuli2();
        else try2(i+1);
    }
}
void xuli1()
{
    d=0;
    for(int i=1; i<=n; ++i)
    {
        if(x[i]==1)
        {
            ++d;
            kq1[d]=a[i];
        }
    }
    try2(1);
}
void try1(int i)
{
    for(int t=0; t<=1; ++t)
    {
        x[i]=t;
        if(i==n) xuli1();
        else try1(i+1);
    }
}
void sub()
{
    nhap();
    maxx=0; minn=0;
    try1(1);
    cout<<maxx<<endl;
    for(int i=1; i<=maxx; ++i) cout<<ans[i]<<" ";
}
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    sub();
}
