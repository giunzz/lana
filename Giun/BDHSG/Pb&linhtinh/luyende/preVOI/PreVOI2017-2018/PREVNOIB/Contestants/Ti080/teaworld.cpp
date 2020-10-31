#include<bits/stdc++.h>
using namespace std;
const int maxm = 2005;
const int maxn = 20;
int m,n,k;
struct cau{int x,y,z,r;}u[maxn];
struct doanthang{int a,b,c;}t[maxn];

struct trasua{int x,y,z,e;}v[maxn];
int xs,ys,zs;
int x[maxn];
int d[maxm];
int dem=0;
int res;
bool ok1(int i,int h)
{
    int l=u[h].x-u[h].r;
    int r=u[h].x+u[h].r;
    if(l<=min(xs,v[i].x)&&r>=max(xs,v[i].x)) return 1;
    if(r<min(xs,v[i].x)||l>max(xs,v[i].x)) return 1;
    return 0;
}
void kq1()
{
    if(dem>k) return ;
    int s=0;
    for(int i=1;i<=n;i++)
        if(x[i]==1) s+=v[i].e;
    res=max(res,s);
}
void Try1(int i)
{
    if(dem>k) return;
    for(int j=1;j<=n;j++)
    {
        x[i]=j;
        if(j==1)
        {
            for(int h=1;h<=m;h++)
                if(d[h]==0)
            {
                if(ok1(i,h)==0) {
                    d[h]=i;
                    dem++;
                }
            }
        }
        if(i==n) kq1();
        else Try1(i+1);
        if(j==1)
        {
            for(int h=1;h<=m;h++)
                if(d[h]==i)
            {
                d[h]=0;
                dem--;
            }
        }
    }

}
void sub1()
{
    Try1(1);
    cout<<res;
}
void kt()
{
    if(dem>k) return;
    int s=0;
    for(int i=1;i<=n;i++)
        if(x[i]==1) s=s+v[i].e;
    res=max(res,s);

}
bool ok(int i,int h)
{

    if((xs-u[h].x)*(xs-u[h].x)+(ys-u[h].y)*(ys-u[h].y)<=u[h].r*u[h].r)
    {
        if((v[i].x-u[h].x)*(v[i].x-u[h].x)+(v[i].y-u[h].y)*(v[i].y-u[h].y)<=u[h].r*u[h].r) return 1;
        else return 0;
    }else
    {
        if((v[i].x-u[h].x)*(v[i].x-u[h].x)+(v[i].y-u[h].y)*(v[i].y-u[h].y)<=u[h].r*u[h].r) return 0;
        if(abs((long long)t[i].a*u[h].x+t[i].b*u[h].y+t[i].c)*abs((long long)t[i].a*u[h].x+t[i].b*u[h].y+t[i].c)<=((long long)t[i].a*t[i].a+t[i].b*t[i].b)*u[h].r*u[h].r) return 0;
        return 1;
    }

}
void Try(int i)
{
    if(dem>k) return ;
    for(int j=0;j<=1;j++)
    {
        x[i]=j;
        if(j==1)
        {
            for(int h=1;h<=m;h++)
                if(d[h]==0)
            {
                if(ok(i,h)==0)
                {d[h]=i;
                    dem++;
                }
            }
        }
        if(i==n) kt();
        else Try(i+1);
        if(j==1)
        {
            for(int h=1;h<=m;h++)
                if(d[h]==i)
            {

                {d[h]=0;
                    dem--;
                }
            }

    }
}
}
void sub2()
{
    for(int i=1;i<=n;i++)
    {
        t[i].a=v[i].y-ys;
        t[i].b=xs-v[i].x;
        t[i].c=-(t[i].a*xs+t[i].b*ys);
    }
    Try(1);
    cout<<res;
}
bool ktra()
{
    for(int i=1;i<=m;i++)
    if(u[i].y!=0||u[i].z!=0) return 0;
    return 1;

}
int main()
{
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++) cin>>u[i].x>>u[i].y>>u[i].z>>u[i].r;
    for(int i=1;i<=n;i++) cin>> v[i].x>>v[i].y>>v[i].z>>v[i].e;
    cin>>xs>>ys>>zs;
    if(ktra()) sub1();
    else sub2();


}

