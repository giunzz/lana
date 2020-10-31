#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;
ifstream fi("table.inp");
ofstream fo("table.out");
int m,n,k;
int a[301][301];
int u,v,p,q;
int64_t f[301][301];
pair <int,int> way[301][301];
void xuli(int u,int v,int p,int q)
{
    int64_t tg1,tg2;
    for (int i=u;i<=p;i++)
        for (int j=v;j<=q;j++)
    {
        if (i==u && j==v)
            f[i][j]=a[u][v],
            way[i][j]=make_pair(0,0);
        else
        {
            if (i>u) tg1=f[i-1][j];
            else tg1=0;
            if (j>v) tg2=f[i][j-1];
            else tg2=0;
            if (tg1>tg2)
            {
                f[i][j]=tg1+a[i][j];
                if (a[way[i-1][j].st][way[i-1][j].nd]>a[i][j] || (i==p && j==q))  way[i][j]=way[i-1][j];
                else way[i][j]=make_pair(i,j);
            }
            else
            {
                f[i][j]=tg2+a[i][j];
                if (a[way[i][j-1].st][way[i][j-1].nd]>a[i][j] || (i==p && j==q)) way[i][j]=way[i][j-1];
                else way[i][j]=make_pair(i,j);
            }
        }
    }
    //fo<<f[p][q]<<" "<<way[p][q].nd<<endl;
    //int64_t temp1=f[p][q]-max(a[u][v],a[p][q]);
    pair <int,int> ban=way[p][q];
    //if (ban==make_pair(u,v) || ban==make_pair(p,q)) {fo<<temp1;return;}
    for (int i=u;i<=p;i++)
        for (int j=v;j<=q;j++)
    {
        if (i==u && j==v)
            f[i][j]=a[u][v];
        else if (ban!=make_pair(i,j))
        {
            if (i>u && ban!=make_pair(i-1,j)) tg1=f[i-1][j];
            else tg1=0;
            if (j>v && ban!=make_pair(i,j-1)) tg2=f[i][j-1];
            else tg2=0;
            f[i][j]=max(tg1,tg2)+a[i][j];
        }
    }
    fo<<f[p][q];
    //fo<<min(temp1,f[p][q]);
}
int main()
{
    fi>>m>>n>>k;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        fi>>a[i][j];
    while (k--,k>=0)
    {
        fi>>u>>v>>p>>q;
        xuli(u,v,p,q);
        fo<<endl;
    }
    return 0;
}
