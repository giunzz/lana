#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ha[50000],hb[50000];
vector <int> pa,pb;
int a,b;
void khoitao()
{
    freopen("MINSUM.INP","r",stdin);
    freopen("MINSUM.OUT","w",stdout);
}
void dong()
{
    fclose(stdin);
    fclose(stdout);
}
void sanga()
{
    int n=a;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
    {
        ha[i]=0;
        while(n%i==0) {ha[i]++;n/=i;}
        pa.push_back(i);
    }
}
void sangb()
{
    int m=b;
    for(int i=2;i*i<=m;i++)
        if(m%i==0)
    {
        hb[i]=0;
        while(m%i==0) {hb[i]++;m/=i;}
        pb.push_back(i);
    }
}
void nhap()
{
    cin>>a>>b;
    int g=__gcd(a,b);
    a/=g;
    b/=g;
    sanga();
    sangb();
}
void xuli()
{


    for(int i=0;i<pa.size();i++)
        if(ha[pa[i]]>=2)
    {
         int k=ha[pa[i]];
        while(k>=2) {k-=2;a/=(pa[i]*pa[i]);}
    }
    for(int i=0;i<pb.size();i++)
        if(hb[pb[i]]>=2)
    {
         int p=hb[pb[i]];
         while(p>=2) {p-=2;b/=(pb[i]*pb[i]);}
    }
    cout<<a<<" "<<b<<endl;
    pa.clear();
    pb.clear();

}
void xuli1()
{
    int t;
    cin>>t;
    while(t--)
    {
        nhap();
        xuli();
    }
}
int main()
{
    khoitao();
    xuli1();
    dong();
}
