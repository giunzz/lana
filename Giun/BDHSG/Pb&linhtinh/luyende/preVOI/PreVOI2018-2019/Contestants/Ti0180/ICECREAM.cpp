#include <bits/stdc++.h>
#define du 1000000009

using namespace std;

int n,mmax,M50,M1,M2,kq,x[301],M50g,M1g,M2g;

void inkq()
{
    bool kt=true;
    for (int i=1; i<=n; i++)
    {
        if (x[i]==1) {
            if (M50<mmax) M50++; else {kt=false; break;} }
        if (x[i]==2) {
            if (M50>0 && M1<mmax) M50--, M1++; else {kt=false; break;} }
        if (x[i]==3)
        {
            int dd=0;
            if (M1>0 && M50>0 && M2<mmax) M1--, M50--, M2++, dd=1;
            if (dd==0) {
                if (M50>=3 && M2<mmax) M50-=3, M2++; else {kt=false; break;} }
        }
    }
    if (kt==true) kq++;
    M50=M50g; M1=M1g; M2=M2g;
}

void Try(int i)
{
    for (int j=1; j<=3; j++)
    {
        x[i]=j;
        if (i>=n) inkq(); else Try(i+1);
    }
}

void xuly1()
{
    kq=0; M50=M50g; M1=M1g; M2=M2g; Try(1);
    cout<<kq%du;
}

int main()
{
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
    scanf("%d %d",&n,&mmax);
    scanf("%d %d %d",&M50g,&M1g,&M2g);
    if (M50g==mmax && M1g==mmax && M2g==mmax) cout<<0;
    else xuly1();
}
