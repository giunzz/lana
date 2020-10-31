#include <bits/stdc++.h>
using namespace std;
vector <int> f[1001][1001],f2[1001][1001],x,va,vb,kq;
int a[3001],b[3001],n,m,i,j,k,kk;
vector <int> Min(vector <int> a,vector <int> b)
{
    if(a.size()==0) return b;
    if(b.size()==0) return a;
    for(int i=0;i<min(a.size(),b.size());i++)
    {
        if(a[i]<b[i]) return a;
        if(a[i]>b[i]) return b;
    }
    if(a.size()>b.size()) return b; else return a;
}
int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    scanf("%d%d%d",&n,&m,&kk);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=m;i++) scanf("%d",&b[i]);
    for(k=1;k<=min(kk,n);k++)
        for(i=n-k+1;i>=1;i--)
        {
            vector <int> ma; ma.push_back(a[i]);
            x=f[i+1][k-1];
            for(j=0;j<x.size();j++) ma.push_back(x[j]);
            f[i][k]=Min(ma,f[i+1][k]);
        }
    for(k=1;k<=min(kk,m);k++)
        for(i=m-k+1;i>=1;i--)
        {
            vector <int> ma; ma.push_back(b[i]);
            x=f2[i+1][k-1];
            for(j=0;j<x.size();j++) ma.push_back(x[j]);
            f2[i][k]=Min(ma,f2[i+1][k]);
        }
    for(i=0;i<=kk;i++)
    {
        int ka=i,kb=kk-i;
        vector <int> ma;
        if(ka>n || kb>m) continue;
        va=f[1][ka]; vb=f2[1][kb];
        if(va.size()<ka || vb.size()<kb) continue;
        while(va.size()>0 && vb.size()>0)
        {
            if(Min(va,vb)==va || va.size()==0) { ma.push_back(va[0]); va.erase(va.begin()); }
            else if(Min(va,vb)==vb || vb.size()==0) { ma.push_back(vb[0]); vb.erase(vb.begin()); }
        }
        if(va.size()>0)
            for(j=0;j<va.size();j++) ma.push_back(va[j]);
        if(vb.size()>0)
            for(j=0;j<vb.size();j++) ma.push_back(vb[j]);
        kq=Min(kq,ma);
    }
    for(i=0;i<kq.size();i++) printf("%d ",kq[i]);
}
