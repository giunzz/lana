#include<bits/stdc++.h>

using namespace std;

int m,n,k,a[1001][1001],kq;
int64_t f[1001][1001];
int d[2]={0,1};
int c[2]={1,0};
int u,v,q,p;

bool inside(int dong,int cot)
{
    return ((dong>=u) && (cot>=v) && (dong<=q) && (cot<=p));
}

void DFS(int u,int v)
{
    for (int i=0; i<=1; i++)
    {
        int x=u+d[i], y=v+c[i];
        if (inside(x,y))
        {
            f[x][y]=max(f[x-1][y],f[x][y-1])+a[x][y];
            if (x==q && y==p) return;
            DFS(x,y);
        }
    }
}

int main()
{
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    scanf("%d %d %d",&m,&n,&k);
    for (int i=1; i<=m; i++)
    {
        f[i][0]=0;
        for (int j=1; j<=n; j++) scanf("%d",&a[i][j]), f[i][j]=0;
    }
    for (int i=1; i<=n; i++) f[0][i]=0;
    for (int i=1; i<=k; i++)
    {
        scanf("%d %d %d %d",&u,&v,&q,&p);
        int gtmax=0,vth,vtc;
        for (int c=v+1; c<=p; c++)
            if (gtmax<a[u][c]) gtmax=a[u][c], vth=u, vtc=c;

        for (int c=v; c<=p-1; c++)
            if (gtmax<a[q][c]) gtmax=a[q][c], vth=q, vtc=c;

        for (int h=u+1; h<=q-1; h++)
            for (int c=v; c<=p; c++)
                if (gtmax<a[h][c]) gtmax=a[h][c], vth=h, vtc=c;

        a[vth][vtc]=0; f[u][v]=a[u][v]; f[q][p]=a[q][p];
        DFS(u,v);
        cout<<f[q][p]<<"\n"; a[vth][vtc]=gtmax;
        for (int h=u; h<=q; h++)
            for (int c=v; c<=p; c++) f[h][c]=0;
    }
}
