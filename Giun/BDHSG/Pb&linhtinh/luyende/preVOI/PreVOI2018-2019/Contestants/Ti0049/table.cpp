#include <bits/stdc++.h>

using namespace std;
ifstream fi ("table.inp");
ofstream fo ("table.out");
int m,n,k;
int a[301][301];

void nhap()
{
    fi>>m>>n>>k;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            fi>>a[i][j];
}

void kqua(int u,int v,int p,int q,pair<int,int > x)
{
    int s[301][301]= {0};
    int b[301][301];
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if(i == x.first && j == x.second)
                b[i][j] = -300000001;
            else b[i][j] = a[i][j];
    s[u][v] = b[u][v];
    for (int i=u+1; i<=p; i++)
        s[i][v] = s[i-1][v] + b[i][v];
    for(int j=v+1; j<=q; j++)
        s[u][j] = s[u][j-1]+b[u][j];
    for (int i=u+1; i<=p; i++)
        for (int j=v+1; j<=q; j++)
            s[i][j] = max(s[i-1][j],s[i][j-1])+b[i][j];
            fo << s[p][q]<<endl;
}

void xuli(int u,int v,int p,int q)
{
    int l[301][301]= {0};
    pair<int,int> cha[301][301];
    l[u][v]=a[u][v];
    for (int i=u; i<=p; i++)
    {
        l[i][v]=l[i-1][v]+a[i][v];
        cha[i][v].first=i-1;
        cha[i][v].second=i;
    }
    for(int j=v+1; j<=q; j++)
    {
        l[u][j]= l[u][j-1]+a[u][j];
        cha[u][j].first=u;
        cha[u][j].second=j-1;
    }
    for (int i=u+1; i<=p; i++)
        for (int j=v+1; j<=q; j++)
            if(l[i-1][j]>l[i][j-1])
            {
                l[i][j]=l[i-1][j]+a[i][j];
                cha[i][j].first=i-1;
                cha[i][j].second=j;
            }
            else
            {
                l[i][j]=l[i][j-1]+a[i][j];
                cha[i][j].first=i;
                cha[i][j].second=j-1;
            }
    int maxn=-100000001;
    pair <int,int> kq;
    pair <int,int> x;
    x= cha[p][q];
    while(1)
    {
        if(x.first==u&&x.second==v) break;
        if(a[x.first][x.second]>maxn)
        {
            maxn=a[x.first][x.second];
            kq=x;
        }
        x=cha[x.first][x.second];
    }
    kqua(u,v,p,q,kq);
}
int main()
{
    nhap();
    for (int i=1;i<=k;i++)
    {
        int u,v,p,q;
        fi >> u >> v >> p >> q;
        xuli(u,v,p,q);
    }
    return 0;
}
