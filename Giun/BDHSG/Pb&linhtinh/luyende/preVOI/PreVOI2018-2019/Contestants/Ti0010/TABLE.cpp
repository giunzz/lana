#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
const int N=310;
int m,n,k,a[N][N],t[N][N],x,y,u,v;
long long f[N][N];
void QHD(int x,int y,int u,int v,int o)
{
    f[x][y]=a[x][y];
    forinc(i,x,u) forinc(j,y,v)
    {
        if(f[i+1][j]<f[i][j]+a[i+1][j])
        {
            f[i+1][j]=f[i][j]+a[i+1][j];
            if(o) t[i+1][j]=1;
        }
        if(f[i][j+1]<f[i][j]+a[i][j+1])
        {
            f[i][j+1]=f[i][j]+a[i][j+1];
            if(o) t[i][j+1]=2;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    cin>>m>>n>>k;
    forinc(i,1,m) forinc(j,1,n) cin>>a[i][j];
    while(k--)
    {
        reset(f,-127);reset(t,0);
        long long kq=1e17;
        cin>>x>>y>>u>>v;
        int U=u,V=v;
        QHD(x,y,u,v,1);
        if(t[u][v]==1) u--;
        else v--;
        while(u!=x||v!=y)
        {
            int i=u,j=v;
            int pre=a[i][j];
            a[i][j]=0;
            reset(f,-127);
            QHD(x,y,U,V,0);
            kq=min(kq,f[U][V]);
            a[i][j]=pre;
            if(t[u][v]==1) u--;
            else v--;
        }
        cout<<kq<<"\n";
    }
}
