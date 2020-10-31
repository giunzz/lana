#include <iostream>
#include <bits/stdc++.h>
#define fi "icecream.inp"
#define fo "icecream.out"
#define pi 1000000009

using namespace std;
int n,Mmax,m50,m1,m2;
long long res;
int x[20];

void nhap()
{
    scanf("%d%d",&n,&Mmax);
    scanf("%d%d%d",&m50,&m1,&m2);
}
void xuli1()
{
    bool kt=true;
    int a=m50, b=m1, c=m2;
    for(int i=1; i<=n; ++i)
    {
        if(x[i]==1)
        {
            if(a >= Mmax) kt=false;
            else a+=1;
        }
        if(kt==false) return;
        else if(x[i]==2)
        {
            if((b>=Mmax) || (a<=0)) kt=false;
            else { b+=1; a-=1; }
        }
        if(kt==false) return;
        else if(x[i]==3)
        {
            if((c>=Mmax) || ((a<3)&&(b==0)) || (a<=0)) kt=false;
            else
            {
                if(b!=0) { ++c; --a; --b; }
                else { ++c; a=a-3; }
            }
        }
        if(kt==false) return;
    }
    if(kt==true) ++res;
        //{ for(int i=1; i<=n; ++i) cout<<x[i]<<" "; cout<<endl; ++res; }
}
void test()
{
    for(int i=1; i<=n; ++i) cout<<x[i]<<" "; cout<<endl;
}
void tryhard(int i)
{
    for(int k=1; k<=3; ++k)
    {
        x[i]=k;
        if(i==n) xuli1();
        else tryhard(i+1);
    }
}
void sub1()
{
    res=0;
    tryhard(1);
    cout<<(res % pi);
}
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    nhap();
    sub1();
}
