#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
int m,n,k,xs,ys,zs,dd[100005];
long long kq=0;
struct T
{
    int x,y,z,v;
};
T b[2005],a[20];
vector <int> v[20];
void Enter()
{
    cin >> m >> n >> k;
    for (int i=1;i<=m;i++) cin >> b[i].x >> b[i].y >> b[i].z >> b[i].v;
    for (int i=1;i<=n;i++) cin >> a[i].x >> a[i].y >> a[i].z >> a[i].v;
    cin >> xs >> ys >> zs;
}
long long Len(int j,int i)
{
    if (i==0) return (b[j].x-xs)*(b[j].x-xs)+(b[j].y-ys)*(b[j].y-ys);
    return (b[j].x-a[i].x)*(b[j].x-a[i].x)+(b[j].y-a[i].y)*(b[j].y-a[i].y);
}
bool check(int i,int j)
{
    long long va=a[i].x-xs;
    long long vb=a[i].y-ys;
    long long c=va*ys-vb*xs;
    long long res=(vb*b[j].x-va*b[j].y+c);
    long long r=b[j].v;
    if (!(b[j].x+r>=min(xs,a[i].x)&&b[j].x-r<=max(xs,a[i].x)&&b[j].y+r>=min(ys,a[i].y)&&b[j].y-r<=max(ys,a[i].y))) return false;
    if (res*res>=((va*va+vb*vb)*r*r)) return false;
    if (Len(j,0)<=r*r&&Len(j,i)<=r*r) return false;
    return true;
}
void Updatekq(int x)
{
    for (int i=1;i<=m;i++) dd[i]=0;
    int cnt=0;
    long long res=0;
    for (int i=0;i<n;i++)
    {
        if (((x>>i)&1)==1)
        {
            int u=i+1;
            for (int j=0;j<v[u].size();j++)
            {
                if (dd[v[u][j]]==0)
                {
                    dd[v[u][j]]=1;
                    cnt++;
                }
            }
            res+=a[u].v;
        }
    }
    if (cnt<=k) kq=max(kq,res);
}
void Solve()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (check(i,j)) v[i].push_back(j);
        }
    }
    for (int i=1;i<(1<<n);i++) Updatekq(i);
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("TEAWORLD.INP","r",stdin);
    freopen("TEAWORLD.OUT","w",stdout);
    Enter();
    Solve();
}
