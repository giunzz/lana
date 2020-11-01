#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int limit=301;
const long long oo=1e15;
struct coor 
{
    int x,y;
    coor(int a=0,int b=0)
    {
        x=a,y=b;
    }
} pre[limit][limit],path[limit*limit];
int n,m,k,counter;
bool stop[limit][limit];
long long dp[2][limit][limit],a[limit][limit];
long long resolve(int x1,int y1,int x2,int y2)
{
    memset(dp,0,sizeof(dp));
    for (int y=y1;y<=y2;y++)
    {
        for (int x=x1;x<=x2;x++) 
        {
            dp[0][x][y]=0;
            if (!stop[x][y])
            {
                dp[1][x][y]=max(dp[1][x-1][y],dp[1][x][y-1])+a[x][y];
            }
        }
    }
    return dp[1][x2][y2];
}
void cal(int x1,int y1,int x2,int y2)
{
    if (x1==x2 && y1==y2) 
    {
        printf("%lld\n",a[x1][y1]);
        return;
    }
    if (x1==x2 || y1==y2)
    {
        printf("0\n");
        return;
    }
    counter=0;
    for (int y=y1;y<=y2;y++)
    {
        for (int x=x1;x<=x2;x++) 
        {
            dp[1][x][y]=0;
            if (dp[0][x-1][y]>dp[0][x][y-1]) 
            {
                pre[x][y]=coor(x-1,y);
                dp[0][x][y]=dp[0][x-1][y]+a[x][y];
            }
            else 
            {
                pre[x][y]=coor(x,y-1);
                dp[0][x][y]=dp[0][x][y-1]+a[x][y];
            }
        }
    }
    coor save=coor(x2,y2);
    while (x2!=x1 || y2!=y1)
    {
        path[++counter]=coor(x2,y2);
        coor tmp=pre[x2][y2];
        x2=tmp.x;
        y2=tmp.y;
    }
    x2=save.x;
    y2=save.y;
    long long res=oo;
    for (int i=2;i<=counter;i++) 
    {
        stop[path[i].x][path[i].y]=true;
        res=min(res,resolve(x1,y1,x2,y2));
        stop[path[i].x][path[i].y]=false;
    }
    printf("%lld\n",res);
}
void cal1(int x1,int y1,int x2,int y2)
{
    if (x1==x2 && y1==y2) 
    {
        printf("%lld\n",a[x1][y1]);
        return;
    }
    if (x1==x2 || y1==y2)
    {
        printf("0\n");
        return;
    }
    memset(dp,0,sizeof(dp));
    for (int y=y1;y<=y2;y++)
    {
        for (int x=x1;x<=x2;x++) 
        {
            dp[0][x][y]=max(dp[0][x-1][y],dp[0][x][y-1])+a[x][y];
        }
    }
    for (int y=y2;y>=y1;y--)
    {
        for (int x=x2;x>=x1;x--) 
        {
            dp[1][x][y]=max(dp[1][x][y+1],dp[1][x+1][y])+a[x][y];
        }
    }
    long long res=oo;
    for (int y=y1;y<=y2;y++)
    {
        for (int x=x1;x<=x2;x++) if ((x!=x1 || y!=y1) && (x!=x2 || y!=y2))
        {
            long long tmp=dp[0][x+1][y-1]+dp[1][x+1][y-1]-a[x+1][y-1];
            long long tmp1=dp[0][x-1][y+1]+dp[1][x-1][y+1]-a[x-1][y+1];
            if (y-1<y1 || x+1>x2) tmp=oo;
            if (x-1<x1 || y+1>y2) tmp1=oo;
            if (tmp==oo && tmp1==oo) continue;
            else if (tmp==oo) res=min(res,tmp1);
            else if (tmp1==oo) res=min(res,tmp);
            else res=min(res,max(tmp,tmp1));
        }
    }
    printf("%lld\n",res);

}
int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    for (int y=1;y<=m;y++)
    {
        for (int x=1;x<=n;x++) scanf("%lld",&a[x][y]);
    }
    int x1,y1,x2,y2;
    if (n<=90 && m<=90) 
    {
        for (int i=1;i<=k;i++) 
        {
            scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
            cal(x1,y1,x2,y2);
        }
    }
    else 
    {
        for (int i=1;i<=k;i++) 
        {
            scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
            cal1(x1,y1,x2,y2);
        }
    }
    
}