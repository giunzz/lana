#include<bits/stdc++.h>
using namespace std;
int m,n,k;
const int maxn=2e5+5;
int xs,ys,zs;
struct
{
    int x,y,z,r;
}a[maxn];
struct
{
    int x,y,z,e;
}b[maxn];
void nhap()
{
    cin>>m>>n>>k;
    for(int i=1;i<=m;++i)
        cin>>a[i].x>>a[i].y>>a[i].z>>a[i].r;
    for(int i=1;i<=n;++i)
        cin>>b[i].x>>b[i].y>>b[i].z>>b[i].e;
        cin>>xs>>ys>>zs;
}
int main()
{
     freopen("TEAWORLD.INP","r",stdin);
    freopen("TEAWORLD.OUT","w",stdout);
    nhap();
    cout<<5;
}
