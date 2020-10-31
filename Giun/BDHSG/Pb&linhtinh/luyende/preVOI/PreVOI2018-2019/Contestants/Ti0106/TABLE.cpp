#include <bits/stdc++.h>
#define mn 305
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORE(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int m,n,k;
int u,v,x,y,tx,ty;
const long long base=1e9+7;
long long a[mn][mn],f1[mn][mn],f2[mn][mn],cnt1[mn][mn],cnt2[mn][mn],kq,s;
void nhap()
{
    cin>>m>>n>>k;
    FOR(i,1,m)
    FOR(j,1,n) cin>>a[i][j];
    while(k--)
    {
        cin>>u>>v>>x>>y;
        s=-1e15;
        tx=0,ty=0;
        FOR(i,0,m+1)
        FOR(j,0,n+1)
        {
            f1[i][j]=-1e15;
            f2[i][j]=-1e15;
            cnt1[i][j]=0;
            cnt2[i][j]=0;
        }
        f1[u-1][v]=0;
        f1[u][v-1]=0;
        f2[x][y+1]=0;
        f2[x+1][y]=0;
        cnt1[u][v]=1;
        cnt2[x][y]=1;
        FOR(i,u,x)
        FOR(j,v,y)
        {
            f1[i][j]=max(f1[i-1][j],f1[i][j-1])+a[i][j];
            if(f1[i][j]==f1[i-1][j]+a[i][j]) cnt1[i][j]=(cnt1[i][j]+cnt1[i-1][j])%base;
            if(f1[i][j]==f1[i][j-1]+a[i][j]) cnt1[i][j]=(cnt1[i][j]+cnt1[i][j-1])%base;
        }
        FORE(i,x,u)
        FORE(j,y,v)
        {
            f2[i][j]=max(f2[i+1][j],f2[i][j+1])+a[i][j];
            if(f2[i][j]==f2[i+1][j]+a[i][j]) cnt2[i][j]=(cnt2[i][j]+cnt2[i+1][j])%base;
            if(f2[i][j]==f2[i][j+1]+a[i][j]) cnt2[i][j]=(cnt2[i][j]+cnt2[i][j+1])%base;
        }
        FOR(i,u,x)
        FOR(j,v,y)
        if((i!=u||j!=v)&&(i!=x||j!=y)&&f1[i][j]+f2[i][j]==f1[x][y]+a[i][j]&&(cnt1[i][j]*cnt2[i][j])%base==cnt1[x][y]&&a[i][j]>s)
        {
            s=a[i][j];
            tx=i;
            ty=j;
        }
        kq=f1[x][y];
        if(tx&&ty&&s>0)
        {
            FOR(i,u,x)
            FOR(j,v,y)
            if(i!=tx||j!=ty) f1[i][j]=max(f1[i-1][j],f1[i][j-1])+a[i][j];
            else f1[i][j]=-1e15;
            kq=min(kq,f1[x][y]);
        }
        cout<<kq<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    nhap();
    return 0;
}
