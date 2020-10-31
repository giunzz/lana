#include <bits/stdc++.h>
#define ft first
#define sd second
#define maxn 2003
#define mod
#define PI 3.14159265
#define MP make_pair
#define PB push_back
#define heap priority_queue
#define Bjerg "TEAWORLD"
using namespace std;
struct point
{
    double x,y,z,r;
}chuong[maxn],tra[17],bs;
long n,m,k;
long long res=0;
bool av[maxn];
void nhap()
{
    cin >> m >> n >> k;
    for(long i=1;i<=m;++i)
    {
        cin >> chuong[i].x >> chuong[i].y >> chuong[i].z >> chuong[i].r;
    }
    for(long i=0;i<n;++i)
    {
        cin >> tra[i].x >> tra[i].y >> tra[i].z >> tra[i].r;
    }
    cin >> bs.x >> bs.y >>  bs.z;
}
double kc(double x1,double y1,double x2,double y2)
{
    return (x1-x2)*(x1-x2)+1ll*(y1-y2)*(y1-y2);
}
bool xet(point tr,point ch)
{
    double da=kc(tr.x,tr.y,ch.x,ch.y);
    double db=kc(bs.x,bs.y,ch.x,ch.y);
    if(da<=1ll*ch.r*ch.r && db<=1ll*ch.r*ch.r) return false;
    if(da<=1ll*ch.r*ch.r) return true;
    if(db<=1ll*ch.r*ch.r) return true;
    double a1,a2,b1,b2,c1,c2;
    double x1=tr.x,x2=bs.x,y1=tr.y,y2=bs.y,x3=ch.x,y3=ch.y;
    a1=y2-y1;
    b1=x1-x2;
    a2=-a1;
    b2=b1;
    c1=x2*y1-x1*y2;
    c2=-(x3*a2+y3*b2);
    double xx=-(c1*b2-b1*c2)/(a1*b2-b1*a2);
    double yy=-(xx*a1+c1)/b1;
    //cout << xx <<" "<<yy <<endl;
    if(xx>=x1 && xx <=x2 && yy>=y1 && yy <=y2)
    {
        da=kc(x3,y3,xx,yy);
        if(da<=1ll*ch.r*ch.r) return true;
    }
    return false;
}
long getbit(long x,long i)
{
    return (x>>i)&1;
}
void lam(long x)
{
    long long ans=0;
    for(long i=0;i<n;++i)
    {
        if(getbit(x,i)) ans+=tra[i].r;
    }
    if(ans<= res) return ;
    memset(av,false,sizeof(av));
    for(long i=0;i<n;++i)
    {
        if(getbit(x,i)==0) continue;
        for(long j=1;j<=m;++j)
        {
            if(av[j]==true) continue;
            if(xet(tra[i],chuong[j])) av[j]=true;
        }
    }
    long dem=0;
    for(long i=1;i<=m;++i) dem+=av[i];
    if(dem<=k) res=max(res,ans);
}
void sub1()
{
    long last=(1<<n);
    for(long x=1;x<last;++x)
    {
        lam(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Bjerg".inp","r",stdin);
    freopen(Bjerg".out","w",stdout);
    nhap();
    sub1();
    cout << res <<endl;
    return 0;
}
