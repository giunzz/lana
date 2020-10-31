#include<bits/stdc++.h>
using namespace std;
ifstream fi("TEAWORLD.inp");
ofstream fo("TEAWORLD.out");
const double inf=7e5+19537;
struct edge{double x,y,z,r;}a[2007],b[20],s;
int f[2007],n,m,k,ans=0;
double dist(int per, edge x, edge y)
{
    return (inf*y.x-x.x*per)*(inf*y.x-x.x*per)+(inf*y.y-x.y*per)*(inf*y.y-x.y*per)+(inf*y.z-x.z*per)*(inf*y.z-x.z*per);
}
bool chk(edge x,edge y)
{
    edge z;
    double rr=y.r*y.r*inf*inf;
    z.x=0,z.y=0,z.z=0;
    int l=0,r=inf;
    if(dist(inf,x,y)<=rr&&dist(inf,z,y)<=rr)return false;
    else if(dist(inf,z,y)<=rr)return true;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(dist(mid,x,y)<=rr)return true;
        if(dist(mid,x,y)<dist(mid+1,x,y))r=mid;
        else l=mid+1;
    }
    if(dist(l,x,y)<=rr)return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    fi>>m>>n>>k;
    for(int i=1;i<=m;++i)fi>>a[i].x>>a[i].y>>a[i].z>>a[i].r;
    for(int i=1;i<=n;++i)fi>>b[i].x>>b[i].y>>b[i].z>>b[i].r;
    fi>>s.x>>s.y>>s.z;
    for(int i=1;i<=m;++i)a[i].x-=s.x,a[i].y-=s.y,a[i].z-=s.z;
    for(int i=1;i<=n;++i)b[i].x-=s.x,b[i].y-=s.y,b[i].z-=s.z;
    memset(f,0,sizeof(f));
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(chk(b[j],a[i]))f[i]+=(1<<(j-1));
    for(int i=0;i<(1<<n);++i)
    {
        int cnt=0;
        for(int j=1;j<=m;++j)
            if((i&f[j])!=0)cnt++;
        if(cnt>k)continue;
        int res=0;
        for(int j=1;j<=n;++j)
            if(((1<<(j-1))&i)!=0)res+=b[j].r;
        ans=max(ans,res);
    }
    fo<<ans;
}
