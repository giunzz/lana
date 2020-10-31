#include <bits/stdc++.h>
using namespace std;
int a[301][301];
struct data
{
    int big , mmax;
    int x , y;
};
data make_data(int big , int mmax , int x ,int y)
{
    data a;
    a.big = big;
    a.mmax = mmax;
    a.x = x;
    a.y = y;
    return a;
}
data f[301][301];
int m,n,k,x,y,u,v;
bool kiemtra(int x,int y ,int u,int v)
{
    if (f[x][y].big == f[u][v].big) return f[x][y].mmax > f[u][v].mmax;
    return f[x][y].big > f[u][v].big;
}
int tinh(int x,int y,int u,int v)
{
    for (int i=y;i<=v;i++) f[x-1][i]=make_data(0,0,0,0);
    for (int i=x;i<=u;i++) f[i][y-1]=make_data(0,0,0,0);
    for (int i=x;i<=u;i++)
        for (int j=y;j<=v;j++)
        {
            f[i][j].big = 0;
            f[i][j].mmax = 0;
            if (kiemtra(i-1 ,j ,i ,j-1)==true)
            {
                f[i][j].big = f[i-1][j].big + a[i][j];
                if (f[i][j].mmax < a[i][j])
                {
                    if ((i!=u || j !=v) && (i!= x || j!= y))
                    {
                    f[i][j].x = i;
                    f[i][j].y = j;
                    f[i][j].mmax = a[i][j];
                    }
                    else
                    {
                    f[i][j].x = f[i-1][j].x;
                    f[i][j].y = f[i-1][j].y;
                    f[i][j].mmax = f[i-1][j].mmax;
                    }
                }
                else
                {
                    f[i][j].x = f[i-1][j].x;
                    f[i][j].y = f[i-1][j].y;
                    f[i][j].mmax = f[i-1][j].mmax;
                }
            }
            else
            {
                f[i][j].big = f[i][j-1].big + a[i][j];
                if (f[i][j].mmax < a[i][j])
                {
                    if ((i!=u || j !=v) && (i!= x || j!= y))
                    {
                    f[i][j].x = i;
                    f[i][j].y = j;
                    f[i][j].mmax = a[i][j];
                    }
                    else
                    {
                    f[i][j].x = f[i][j-1].x;
                    f[i][j].y = f[i][j-1].y;
                    f[i][j].mmax = f[i][j-1].mmax;
                    }
                }
                else
                {
                    f[i][j].x = f[i][j-1].x;
                    f[i][j].y = f[i][j-1].y;
                    f[i][j].mmax = f[i][j-1].mmax;
                }
            }
        }
        int z = f[u][v].x;
        int t = f[u][v].y;
        int tt = a[z][t];
        a[z][t]=0;
        for (int i=z;i<=u;i++)
            for (int j=t;j<=v;j++)
                f[i][j].big = max( f[i-1][j].big , f[i][j-1].big ) + a[i][j];
        a[z][t]=tt;
        return f[u][v].big;
}

int tinh_2(int x ,int y ,int u , int v)
{
    for (int i=y;i<=v;i++) f[x-1][i]=make_data(0,0,0,0);
    for (int i=x;i<=u;i++) f[i][y-1]=make_data(0,0,0,0);
    for (int i=x;i<=u;i++)
            for (int j=y;j<=v;j++)
                f[i][j].big = max( f[i-1][j].big , f[i][j-1].big ) + a[i][j];
                int ans = 1e18;
                int tt;
    for (int z = u;z>=x;z--)
    for (int t = v;t>=y;t--)
    if ((z!=u || t!=v) && (z!= x || t!= y))
    {
        tt = a[z][t];
        a[z][t]=0;
        for (int i=z;i<=u;i++)
            for (int j=t;j<=v;j++)
                f[i][j].big = max( f[i-1][j].big , f[i][j-1].big ) + a[i][j];
        a[z][t]=tt;
        ans = min(ans , f[u][v].big);
    }
    return ans;
}
int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    scanf("%ld%ld%ld",&m,&n,&k);
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) scanf("%ld",&a[i][j]);
    if (n<= 100 && m <= 100 && k<=100)
    for (int i=1;i<=k;i++)
    {
        cin>>x>>y>>u>>v;
        cout<<tinh_2(x,y,u,v)<<"\n";
    }
    else
        for (int i=1;i<=k;i++)
    {
        cin>>x>>y>>u>>v;
        cout<<tinh(x,y,u,v)<<"\n";
    }
    return 0;
}
