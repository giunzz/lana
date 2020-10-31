#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
#define filename "TEAWORLD"
void io()
{
    freopen(filename".INP","r",stdin);
    freopen(filename".OUT","w",stdout);
}
const int MAXN=2e3+3;
int m,n,k;
struct Pnt
{
    int x,y,z,r,e;
}c[MAXN],t[MAXN],s;
ii p[MAXN*3];
int s_id;
int c_k,last;
bool clr[MAXN];
int f[2][MAXN];
int ans;
bool dd[MAXN];
main()
{
    io();
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d%d",&c[i].x,&c[i].y,&c[i].z,&c[i].r);
        p[i]=ii(c[i].x-c[i].r,i);
        p[i+m]=ii(c[i].x+c[i].r,i);
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d%d",&t[i].x,&t[i].y,&t[i].z,&t[i].e);
        p[i+m*2]=ii(t[i].x,i+m*2);
    }
    scanf("%d%d%d",&s.x,&s.y,&s.z);
    p[m*2+n+1]=ii(s.x,-1);
    sort(p+1,p+n+1);
    s_id=lower_bound(p+1,p+n+1,ii(s.x,-1))-p;
    c_k=0;
    last=501;
    for(int i=s_id+1;i<=n;++i)
    {
        if(p[i].second>m*2 and p[i].first<=last)
        {
            f[1][c_k]+=t[p[i].second-m*2].e;
            if(c_k>0 and p[i].first==last)
                f[1][c_k-1]+=t[p[i].second-m*2].e;
        }
        else
        {
            if(dd[p[i].second])
                continue;
            dd[p[i].second]=1;
            c_k++;
            f[1][c_k]=f[1][c_k-1];
            last=p[i].first;
        }
    }
    for(int i=1;i<=k;++i)
    {
        f[1][i]=max(f[1][i],f[1][i-1]);
    }
    c_k=0;
    last=-501;
    for(int i=s_id-1;i>=1;--i)
    {
        if(p[i].second>m*2 and p[i].first>=last)
        {
            f[0][c_k]+=t[p[i].second-m*2].e;
            if(c_k>0 and p[i].first==last)
                f[0][c_k-1]+=t[p[i].second-m*2].e;
        }
        else
        {
            if(dd[p[i].second])
                continue;
            c_k++;
            dd[p[i].second]=1;
            f[0][c_k]=f[0][c_k-1];
            last=p[i].first;
        }
    }
    for(int i=1;i<=k;++i)
    {
        f[0][i]=max(f[0][i],f[0][i-1]);
    }
    for(int i=0;i<=k;++i)
    {
        //cout<<f[0][i]<<' '<<f[1][k-1]<<'\n';
        ans=max(ans,f[1][i]+f[0][k-i]);
    }
    cout<<ans;
}
