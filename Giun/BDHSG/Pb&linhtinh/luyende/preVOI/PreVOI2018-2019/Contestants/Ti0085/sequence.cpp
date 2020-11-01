#include <iostream>
#include <bits/stdc++.h>
#define fi "sequence.inp"
#define fo "sequence.out"
#define maxn 20
using namespace std;
int m,n,k,d,tg,minn;
int a[maxn], b[maxn], c[maxn], x[maxn], y[maxn], kq[maxn], kq2[maxn];

void nhap()
{
    cin>>m>>n>>k;
    for(int i=1; i<=m; ++i)cin>>a[i];
    for(int i=1; i<=n; ++i)cin>>b[i];
}
void xuli2()
{
    tg=d;
    for(int i=1; i<=n; ++i)
    {
        if(y[i]==1) { ++tg; c[tg]=b[i]; }
    }
    if(tg==k){
    int kt=0;
    for(int i=1; i<=tg; ++i)
    {
        if(c[i] <= kq[i]) ++kt;
        else break;
    }
    if(kt >= minn)
    {
        minn=kt;
        //for(int i=1; i<=tg; ++i) cout<<kq[i]<<" "; cout<<endl;
        for(int i=1; i<=tg; ++i) kq[i]=c[i];
        //cout<<tg<<" "<<kt<<endl;
        //for(int i=1; i<=tg; ++i) cout<<c[i]<<" "; cout<<endl;
        //for(int i=1; i<=tg; ++i) cout<<kq[i]<<" "; cout<<endl;
    }
    }

}
void test()
{
    for(int i=1; i<=n; ++i) cout<<y[i]<<" "; cout<<endl;
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
    for(int i=1; i<=m; ++i)
    {
        if(x[i]==1)
        {
            ++d; c[d]=a[i];
        }
    }
    try2(1);
    //if(d!=k) return;
}

void try1(int hi)
{
    for(int t=0; t<=1; ++t)
    {
        x[hi]=t;
        if(hi==m) xuli1();
        else try1(hi+1);
    }
}

void xuli4()
{
    tg=d;
    for(int i=1; i<=m; ++i)
    {
        if(y[i]==1) { ++tg; c[tg]=a[i]; }
    }
    if(tg==k){
    int kt=0;
    for(int i=1; i<=tg; ++i)
    {
        if(c[i] <= kq2[i]) ++kt;
        else break;
    }
    if(kt >= minn)
    {
        minn=kt;
        for(int i=1; i<=tg; ++i) kq2[i]=c[i];
    }
    }

}

void try4(int i)
{
    for(int t=0; t<=1; ++t)
    {
        y[i]=t;
        if(i==m) xuli4();
        else try4(i+1);
    }
}
void xuli3()
{
    d=0;
    for(int i=1; i<=n; ++i)
    {
        if(x[i]==1)
        {
            ++d; c[d]=b[i];
        }
    }
    try4(1);
    //if(d!=k) return;
}

void try3(int hi)
{
    for(int t=0; t<=1; ++t)
    {
        x[hi]=t;
        if(hi==n) xuli3();
        else try3(hi+1);
    }
}
void xamlol()
{
    nhap();
    minn=0;
    for(int i=1; i<=k; ++i) kq[i]=1e9;
    try1(1);
    //for(int i=1; i<=k; ++i) cout<<kq[i]<<" ";
    minn=0;
    for(int i=1; i<=k; ++i) kq2[i]=1e9;
    try3(1);
    for(int i=1; i<=k; ++i)
    {
        if(kq[i] < kq2[i]) {for(int i=1; i<=k; ++i)cout<<kq[i]<<" "; return ; }
        else {for(int i=1; i<=k; ++i)cout<<kq[i]<<" "; return ; }
    }
    for(int i=1; i<=k; ++i)cout<<kq[i]<<" ";
}

int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    xamlol();
}
