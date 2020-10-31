#include <bits/stdc++.h>
using namespace std;
struct pt { int x,y; };
pt q[4000001];
int d[2001][2001];
int f[2001][2001],m,gh,x,y,dau,cuoi,kq,i,j,dx,dy;
void push(int x1,int y1)
{
    if(x1>=0 && y1>=0 && x1<=2000 && y1<=2000 && d[x1][y1]==0)
    {
        d[x1][y1]=1;
        cuoi++; q[cuoi]={ x1,y1 };
        f[x1][y1]=f[x][y]+1;
    }
}
int main()
{
    freopen("robots.inp","r",stdin);
    freopen("robots.out","w",stdout);
    scanf("%d%d",&m,&gh);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y); x+=1000; y+=1000;
        cuoi++; q[cuoi]={ x,y }; d[x][y]=1;
    }
    scanf("%d%d",&dx,&dy); dx+=1000; dy+=1000;
    dau=1;
    while(dau<=cuoi)
    {
        x=q[dau].x; y=q[dau].y; dau++;
        push(x+1,y); push(x-1,y); push(x,y+1); push(x,y-1);
    }
    for(i=0;i<=2000;i++)
        for(j=0;j<=2000;j++)
            if(abs(i-dx)+abs(j-dy)<=gh) kq=max(kq,f[i][j]);
    cout<<kq;
}
