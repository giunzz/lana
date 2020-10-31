#include <bits/stdc++.h>
#define e r
using namespace std;
long n,m,k;
struct point
{
    long x,y,z,r;
};
point a[2001],b[16],s;
vector<long>v[16];
bool dd[2001];
void nhap()
{
    cin>>m>>n>>k;
    for(long i=1;i<=m;++i)
    {
        cin>>a[i].x>>a[i].y>>a[i].z>>a[i].r;
    }
    for(long i=1;i<=n;++i)
    {
        cin>>b[i].x>>b[i].y>>b[i].z>>b[i].e;
    }
    cin>>s.x>>s.y>>s.z;
}
long long bp(long x)
{
    return 1ll*x*x;
}
long long kc(point A,point B)
{
    return 1ll*(A.x-B.x)*(A.x-B.x)+1ll*(A.y-B.y)*(A.y-B.y);
}
bool kk(point A,point B)
{
    long long d1=kc(A,B);
    long long d2=kc(s,A);
    long long d3=kc(s,B);
    if(d1>d2+d3)return false;
    if(d3>d1+d2)return false;
    return true;
}
bool kt(long i,long j)
{
    bool ok1,ok2;
    ok1=(kc(s,a[j])<=1ll*a[j].r*a[j].r);
    ok2=(kc(b[i],a[j])<=1ll*a[j].r*a[j].r);
    if(ok1&&ok2)return false;
    if(ok1||ok2)return true;
    long long aa,bb,cc,d;
    aa=s.y-b[i].y;
    bb=b[i].x-s.x;
    cc=-aa*s.x-bb*s.y;
    d=bp(aa*a[j].x+bb*a[j].y+cc);
    if(d<=(aa*aa+bb*bb)*bp(a[j].r)&&kk(b[i],a[j]))
        return true;
    return false;
}
void khoitao()
{
    for(long i=1;i<=n;++i)
    {
        for(long j=1;j<=m;++j)
        {
            if(kt(i,j))
                v[i].push_back(j);
        }
    }
}
long lb(long x,long i)
{
    return (x>>i)&1;
}
void lam()
{
    long l=(1<<n)-1;
    long dem;
    long long res,ans=0;
    for(long i=0;i<=l;++i)
    {
        res=0;
        dem=0;
        for(long j=1;j<=n;++j)
        {
            if(lb(i,j-1)==0)continue;
            for(long k=0;k<v[j].size();++k)
            {
                if(dd[v[j][k]])continue;
                dem++;
                dd[v[j][k]]=true;
            }
            res+=b[j].e;
        }
        if(dem<=k)
            ans=max(ans,res);
        for(long j=1;j<=n;++j)
        {
            if(lb(i,j-1)==0)continue;
            for(long k=0;k<v[j].size();++k)
                dd[v[j][k]]=false;
        }
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    nhap();
    khoitao();
    lam();
    return 0;
}
