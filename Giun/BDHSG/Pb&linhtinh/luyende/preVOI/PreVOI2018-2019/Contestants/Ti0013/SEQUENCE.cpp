#include<bits/stdc++.h>
using namespace std;
const int maxn=3010;
const int maxkq=6010;
int a[maxn],b[maxn];
int kq[maxkq];
int res=0;
int m,n,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    a[m+1]=1000000;
    b[n+1]=1000001;
    int dele=m+n-k;
    int ia=1,ib=1;
    for(int i=1;i<=k;i++)
    {
        //if(i==5) cout<<ia<<" "<<ib<<"\n";
        dele=max(dele,0);
        int mia=10000,posa,mib=10000,posb;
        for(int j=ia;j<=min(ia+dele,m);j++) if(mia>a[j]) {mia=a[j];posa=j;}
        for(int j=ib;j<=min(ib+dele,n);j++) if(mib>b[j]) {mib=b[j];posb=j;}
        //cout<<mia<<" "<<posa<<" "<<mib<<" "<<posb<<"\n";
        if(mia<mib)
        {
            res=res+1;
            dele=dele-(posa-ia);
            kq[res]=mia;
            ia=posa+1;
            continue;
        }
        if(mib<mia)
        {
            dele=dele-(posb-ib);
            ib=posb+1;
            res=res+1;
            kq[res]=mib;
            continue;
        }
        int goa=posa-ia;
        int gob=posb-ib;
        if(goa<gob)
        {
            res=res+1;
            kq[res]=mia;
            dele=dele-goa;
            ia=posa+1;
            continue;
        }
        if(gob<goa)
        {
            res=res+1;
            kq[res]=mib;
            dele=dele-gob;
            ib=posb+1;
            continue;
        }
        int side;
        for(int smt=1;;smt++)
        {
            if(a[posa+smt]==b[posb+smt]) continue;
            if(a[posa+smt]<b[posb+smt]) {side=1;break;}
            if(a[posa+smt]>b[posb+smt]) {side=2;break;}
        }
        if(side==1)
        {
            res=res+1;
            kq[res]=a[posa];
            dele=dele-(posa-ia);
            ia=posa+1;
        }else
        {
            res=res+1;
            kq[res]=b[posb];
            dele=dele-(posb-ib);
            ib=posb+1;
        }
    }
    for(int i=1;i<=res;i++) cout<<kq[i]<<" ";
    return 0;
}
