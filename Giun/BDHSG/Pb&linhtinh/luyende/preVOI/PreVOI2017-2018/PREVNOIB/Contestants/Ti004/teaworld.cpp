#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
int dem,tong,gg,kq,m,n,h,k,x,y,p,a,b,c,d,s,t,g,td[160001],gt[160001];
pii cau[2001],tras[16],bb[16],cc[16];
void nhap()
{
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    cin>>m>>n>>k;
    g=80000;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>c>>d;
        cau[i].fi=a;
        cau[i].se=d;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c>>d;
        tras[i].fi=a;
        tras[i].se=d;
        gt[a+g]=d;
    }
    cin>>s>>t>>h;
}
void vi_xu_li()
{
    for(int i=1;i<=m;i++)
    {
        p=cau[i].fi;
        cau[i].fi=p-cau[i].se;
        cau[i].se=p+cau[i].se;
        td[cau[i].fi+g]=-1;
        td[cau[i].se+g]=1;
    }
}
void xu_li()
{
    for(int i=s+g;i>=0;i--)
    {
        gg+=td[i];
        if(gg<0)
            break;
        kq+=gt[i];
    }
    for(int i=s+g;i<=160000;i++)
    {
        gg+=td[i];
        if(gg>0)
            break;
        kq+=gt[i];
    }
    dem=0;
    x=0;
    for(int i=s+g;i>=0;i--)
    {
        if(td[i]<0)
        {
            dem++;
        }
        tong+=gt[i];
        if(gt[i]!=0)
        {
            x++;
            bb[x].fi=dem;
            bb[x].se=tong;
        }
    }
    tong=0;
    dem=0;
    y=0;
    for(int i=s+g;i>=0;i--)
    {
        if(td[i]>0)
        {
            dem++;
        }
        tong+=gt[i];
        if(gt[i]!=0)
        {
            y++;
            cc[y].fi=dem;
            cc[y].se=tong;
        }
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            if(bb[i].fi+cc[i].fi==k)
            {
                kq=max(kq,bb[i].se+cc[j].se);
            }
        }
    }
    cout<<kq;
}
int main()
{
    nhap();
    vi_xu_li();
    xu_li();
}
