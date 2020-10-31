#include<bits/stdc++.h>
#define mn 2005
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORE(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int m,n,k,xs,ys,zs,kt1=1,kt2=1,dd[mn];
long long kq=0;
struct dt
{
    int x,y,z,e,r;
};
dt a[mn],b[20];
void nhap()
{
    cin>>m>>n>>k;
    FOR(i,1,m)
    cin>>a[i].x>>a[i].y>>a[i].z>>a[i].r;
    FOR(i,1,n)
    {
        cin>>b[i].x>>b[i].y>>b[i].z>>b[i].e;
        kq+=b[i].e;
    }
    cin>>xs>>ys>>zs;
    cout<<kq;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TEAWORLD.inp","r",stdin);
    freopen("TEAWORLD.out","w",stdout);
    nhap();
    return 0;
}

