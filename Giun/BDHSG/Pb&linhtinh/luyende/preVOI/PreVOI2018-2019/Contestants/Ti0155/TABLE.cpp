#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)
#define maxN 301
#define ll long long
using namespace std;
const ll INF=1e12;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int m,n,k,i,j,u,v,x,y,cnt=0,h[maxN][maxN];
ll a[maxN][maxN],ans,cur_score,f[maxN][maxN];
void Io()
{
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
}
void Read()
{
    scanf("%d%d%d",&m,&n,&k);
    For(ii,1,m)
        For(jj,1,n)
            scanf("%lld",&a[ii][jj]);
}
void dfs(int cur_i,int cur_j,ll cur_d)
{
    if(cur_i==u&&cur_j==v)
    {
        cur_score=max(cur_score,cur_d);
        return;
    }
    For(t,0,1)
    {
        int cur_u=cur_i+dx[t],cur_v=cur_j+dy[t];
        if(cur_u<i||cur_u>u||cur_v<j||cur_v>v)continue;
        if(cur_u==x&&cur_v==y)continue;
        dfs(cur_u,cur_v,cur_d+a[cur_u][cur_v]);
    }
}
void Sub1()
{
    For(test,1,k)
    {
        scanf("%d%d%d%d",&i,&j,&u,&v);
        ans=INF;
        For(blockx,i,u)
            For(blocky,j,v)
            {
                cur_score=0;
                x=blockx;y=blocky;
                if(x==i&&y==j)continue;
                if(x==u&&y==v)continue;
                dfs(i,j,a[i][j]);
                ans=min(ans,cur_score);
            }
        printf("%lld\n",ans);
    }
}
void truyvet(int ii,int jj,ll cur)
{
    if(cur==0)return;
    For(t,2,3)
    {
        int uu=ii+dx[t],vv=jj+dy[k];
        if(uu<i||uu>u||vv<j||vv>v)continue;
        if(f[uu][vv]==cur-a[ii][jj])
        {
            h[uu][vv]=cnt;
            truyvet(uu,vv,cur-a[ii][jj]);
        }
    }
}
void dfs2(int cur_i,int cur_j,ll cur_d)
{
    if(cur_i==u&&cur_j==v)
    {
        if(cur_d>cur_score)
        {
            cur_score=cur_d;
            cnt++;
            truyvet(u,v,cur_score);
        }
        return;
    }
    f[cur_i][cur_j]=max(f[cur_i][cur_j],cur_d);
    For(t,0,1)
    {
        int cur_u=cur_i+dx[t],cur_v=cur_j+dy[t];
        if(cur_u<i||cur_u>u||cur_v<j||cur_v>v)continue;
        if(cur_u==x&&cur_v==y)continue;
        dfs2(cur_u,cur_v,cur_d+a[cur_u][cur_v]);
    }
}

void BCTLE()
{
    For(test,1,k)
    {
        memset(f,0,sizeof(f));
        memset(h,0,sizeof(h));
        scanf("%d%d%d%d",&i,&j,&u,&v);
        ans=INF;
        x=-1;y=-1;
        cur_score=0;
        dfs2(i,j,a[i][j]);
        For(blockx,i,u)
            For(blocky,j,v)
            {
                cur_score=0;
                x=blockx;y=blocky;
                if(x==i&&y==j)continue;
                if(x==u&&y==v)continue;
                if(abs(h[x][y]-cnt)<=5&&h[x][y]!=0)
                {
                    dfs(i,j,a[i][j]);
                    ans=min(ans,cur_score);
                }
            }
        printf("%lld\n",ans);
    }
}
int main()
{
    Io();
    Read();
    if(m<=30&&n<=30&&k<=30)Sub1();
    else
        BCTLE();
}
