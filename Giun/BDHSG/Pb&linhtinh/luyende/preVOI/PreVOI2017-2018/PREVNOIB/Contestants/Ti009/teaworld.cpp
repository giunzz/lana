#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=2e3+15,N=30;
int res=0,m,n,k,x,y,z,r,v[M],dd[M],pick[N],s_x,s_y;
pair<int,int> p[N];
struct circle
{
    int x,y,r;
};
circle cir[N];
circle make_circle(int x,int y,int r)
{
    circle concu;
    concu.x=x;
    concu.y=y;
    concu.r=r;
    return concu;
}
int distance(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int check(circle htr,int x1,int y1,int x2,int y2)
{
    int ox=htr.x;
    int oy=htr.y;
    int r=htr.r;
    if( distance(ox,oy,x1,y1)<=(r*r) || distance(ox,oy,x2,y2)<=r*r ) return 1;
    if(x1<=ox&&ox<=x2) return 1;
    if(x2<=ox&&ox<=x1) return 1;
    return 0;
}
int update()
{
    int sum=0,cnt=0;
    memset(dd,0,sizeof dd);
    for(int i=1;i<=n;i++)
        if(pick[i])
        {
            sum+=v[i];
            int u1=p[i].first;
            int v1=p[i].second;
            for(int j=1;j<=m;j++)
                if(check(cir[j],s_x,s_y,u1,v1)&&dd[j]==0) {dd[j]=1;cnt++;}
        }
    if(cnt<=k) res=max(res,sum);
}
int backtrack(int i)
{
    if(i>n) {update(); return 0;}
    for(int j=0;j<=1;j++)
    {
        pick[i]=j;
        backtrack(i+1);
    }
    return 0;
}
int process()
{
    backtrack(1);
    cout<<res;
}
main()
{
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z>>r;
        cir[i]=make_circle(x,y,r);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>z>>v[i];
        p[i]=make_pair(x,y);
    }
    cin>>s_x>>s_y;
    process();
}
