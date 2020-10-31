#include <bits/stdc++.h>
#define maxn 305
#define maxc
#define PB push_back
#define MP make_pair
#define ft first
#define sd second
#define DH "table"
using namespace std;
typedef pair < long , long > ii;
long dx[]={0,1};
long dy[]={1,0};
long long n,m,fd[maxn][maxn],fv[maxn][maxn];
long long mt[maxn][maxn],md[maxn][maxn],k,a[maxn][maxn];
bool inside(ii a)
{
    if(a.ft >=1 && a.ft <=n && a.sd >=1 && a.sd <=m)
        return true;
    return false;
}
void nhap()
{
    cin >> n >> m >> k;
    for(long i=1;i<=n;++i)
    {
        for(long j=1;j<=m;++j)
        cin >> a[i][j];
    }
}
void bfsd(ii x)
{
    queue < ii > q;
    memset(fd,0,sizeof(fd));
    fd[x.ft][x.sd]=a[x.ft][x.sd];
    q.push(x);
    while(q.size())
    {
        ii u,v;
        u=q.front();
        q.pop();
        for(long i=0;i<=1;++i)
        {
            v.ft=u.ft+dx[i];
            v.sd=u.sd+dy[i];
            if(inside(v) && fd[v.ft][v.sd] <fd[u.ft][u.sd]+a[v.ft][v.sd])
            {
                 fd[v.ft][v.sd] = fd[u.ft][u.sd]+a[v.ft][v.sd];
                 q.push(v);
            }
        }
    }
}
void bfsv(ii x)
{
    queue < ii > q;
    memset(fv,0,sizeof(fv));
    fv[x.ft][x.sd]=a[x.ft][x.sd];
    q.push(x);
    while(q.size())
    {
        ii u,v;
        u=q.front();
        q.pop();
        for(long i=0;i<=1;++i)
        {
            v.ft=u.ft-dx[i];
            v.sd=u.sd-dy[i];
            if(inside(v) && fv[v.ft][v.sd] <fv[u.ft][u.sd]+a[v.ft][v.sd])
            {
                 fv[v.ft][v.sd] = fv[u.ft][u.sd]+a[v.ft][v.sd];
                 q.push(v);
            }
        }
    }
}
void lam()
{
    while(k--)
    {
        ii id1,id2;
    cin >> id1.ft >> id1.sd >>id2.ft >> id2.sd;
    bfsd(id1);
    bfsv(id2);
    memset(mt,0,sizeof(mt));
    memset(md,0,sizeof(md));
    for(long i=id1.ft;i<=id2.ft;++i)
    {
        for(long j=id2.sd;j>=id1.sd;--j)
        {
            mt[i][j]=max(mt[i-1][j],mt[i][j+1]);
            mt[i][j]=max(mt[i][j],fd[i][j]+fv[i][j]-a[i][j]);
        }
    }
    for(long i=id2.ft;i>=id1.ft;--i)
    {
        for(long j=id1.sd;j<=id2.sd;++j)
        {
            md[i][j]=max(md[i+1][j],md[i][j-1]);
            md[i][j]=max(md[i][j],fd[i][j]+fv[i][j]-a[i][j]);
        }
    }
    long long ans=1e18;
    for(long i=id1.ft;i<=id2.ft;++i)
    {
        for(long j=id1.sd;j<=id2.sd;++j)
        {
            if(MP(i,j)==id1 || MP(i,j)==id2) continue;
            ans=min(ans,max(mt[i-1][j+1],md[i+1][j-1]));
        }
    }
    cout << ans<<"\n";
}
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(DH".inp","r",stdin);
    freopen(DH".out","w",stdout);
    nhap();
    lam();
    return 0;
}
