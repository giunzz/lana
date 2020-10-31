#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void khoitao()
{
    freopen("TEAWORLD.INP","r",stdin);
    freopen("TEAWORLD.OUT","w",stdout);
}
void dong()
{
    fclose(stdin);
    fclose(stdout);
}
struct ii
{
    int pos,r;
};
struct oo
{
    int pos,val;
};
ii t[1000001];
int gs;
int m,n,k;
oo h[1000001];
int d[1000001];
void nhap()
{
    cin>>m>>n>>k;
    int p1,p2,p3,p4;
    bool ok1=true;
    for(int i=1;i<=m;i++)
    {
        cin>>p1>>p2>>p3>>p4;
        if(p2!=0 || p3!=0 ) ok1=false;
        t[i].pos=p1;
        t[i].r=p4;

    }
    if(ok1==true&&k==0)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>p1>>p2>>p3>>p4;
            h[i].pos=p1;
            h[i].val=p4;
        }
        cin>>gs;
        int x=-1;
        for(int i=1;i<=m;i++)
        {
            int z=t[i].pos;
            int f=t[i].r;
            for(int j=z-f;j<=z+f;j++)
                if(j==gs)
            {
                x=i;

            }
            else {d[j+500]=1;}
        }
        if(x==-1)
        {
            for(int i=1;i<=n;i++)
             if(abs(h[i].pos-t[x].pos)<=t[x].r) ans+=h[i].val;
             cout<<ans;return;
        }
        bool kt;
     for(int i=1;kt=true,i<=n;i++)
     {
        for(int j=gs;j<=h[i].pos;i++)
        if(d[j+500]==1) kt=false;
        if(kt==true) ans+=h[i].val;

    }
    cout<<ans;return;
    }
    else cout<<0;

}
int main()
{
   khoitao();
   nhap();
   dong();
}
