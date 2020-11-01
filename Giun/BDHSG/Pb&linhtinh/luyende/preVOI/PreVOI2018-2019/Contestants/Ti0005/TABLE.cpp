#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second

using namespace std;
ifstream fi ("TABLE.INP");
ofstream fo ("TABLE.OUT");

int const maxmn=310;
int m,n,k;
int a[maxmn][maxmn];
int b[maxmn][maxmn];
int d[maxmn][maxmn];
pii truoc[maxmn][maxmn];
int u,v,p,q;
int h[2]= {0,1};
int c[2]= {1,0};
pii PHAGAME;
int phagame;

void NhapDL()
{
    fi>>m>>n>>k;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            fi>>a[i][j];
}

void Loang(int u, int v)
{
    b[u][v]=a[u][v];
    queue <pii> Q;
    Q.push(make_pair(u,v));
    int u1,v1;
    while (Q.size()>0)
    {
        pii k=Q.front();
        Q.pop();
        for (int i=0; i<=1; i++)
        {
            u1=k.x+h[i];
            v1=k.y+c[i];
            if (u1>=1 && u1<=p && v1>=1 && v1<=q && d[u1][v1]!=1)
            {
                Q.push(make_pair(u1,v1));
                if (b[k.x][k.y]+a[u1][v1]>b[u1][v1])
                {
                    b[u1][v1]=b[k.x][k.y]+a[u1][v1];
                    truoc[u1][v1].x=k.x;
                    truoc[u1][v1].y=k.y;
                }
                else
                    b[u1][v1]=b[u1][v1];
            }
        }
    }
}

void Xuli()
{
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
        {
            d[i][j]=0;
            b[i][j]=0;
            truoc[i][j]=make_pair(0,0);
        }
    Loang(u,v);
    int P,Q;
    P=p;
    Q=q;
    phagame=-1;
    while (truoc[P][Q].x!=u && truoc[P][Q].y!=v)
    {
        P=truoc[P][Q].x;
        Q=truoc[P][Q].y;
        if (a[P][Q]>phagame)
        {
            phagame=a[P][Q];
            PHAGAME.x=P;
            PHAGAME.y=Q;
        }
    }
    for (int i=m; i>=PHAGAME.x; i--)
        for (int j=1; j<=PHAGAME.y; j++)
            d[i][j]=1;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
        {
            b[i][j]=0;
        }
    Loang(u,v);
//    for (int i=1; i<=m; i++)
//    {
//        for (int j=1; j<=n; j++)
//            fo<<b[i][j]<<" ";
//        fo<<endl;
//    }
    fo<<b[p][q]<<endl;
}

int main()
{
    NhapDL();
    for (int i=1; i<=k; i++)
    {
        fi>>u>>v>>p>>q;
        Xuli();
    }
}
