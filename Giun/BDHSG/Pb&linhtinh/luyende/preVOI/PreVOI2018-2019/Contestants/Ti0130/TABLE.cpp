#include <bits/stdc++.h>
#define ft first
#define sc second

using namespace std;
int64_t a[305][305];
typedef pair<int,int> II;
typedef pair<int64_t,II> III;
III s[305][305];
int m,n,k,x,y,u,v;
void xuli(int i,int j)
{
                if (s[i][j].ft<=s[i-1][j].ft+a[i][j])
                {
                    s[i][j].ft=s[i-1][j].ft+a[i][j];
                    int tx1=s[i][j].sc.ft;
                    int ty1=s[i][j].sc.sc;
                    int tx2=s[i-1][j].sc.ft;
                    int ty2=s[i-1][j].sc.sc;
                    if (a[tx1][ty1]<a[tx2][ty2])
                    {
                        s[i][j].sc.ft=tx2;
                        s[i][j].sc.sc=ty2;
                    }
                    else
                        {
                            if ((i!=x || j!=y) && (i!=u || j!=v))
                            {
                            s[i][j].sc.ft=tx1;
                            s[i][j].sc.sc=ty1;
                            }
                            else
                            {
                            s[i][j].sc.ft=tx2;
                            s[i][j].sc.sc=ty2;
                            }

                        }

                }
                if (s[i][j].ft<=s[i][j-1].ft+a[i][j])
                {
                    s[i][j].ft=s[i][j-1].ft+a[i][j];
                    int tx1=s[i][j].sc.ft;
                    int ty1=s[i][j].sc.sc;
                    int tx2=s[i][j-1].sc.ft;
                    int ty2=s[i][j-1].sc.sc;
                    if (a[tx1][ty1]<a[tx2][ty2])
                    {
                        s[i][j].sc.ft=tx2;
                        s[i][j].sc.sc=ty2;
                    }
                     else
                        {
                            if ((i!=x || j!=y) && (i!=u || j!=v))
                            {
                            s[i][j].sc.ft=tx1;
                            s[i][j].sc.sc=ty1;
                            }
                            else
                            {
                            s[i][j].sc.ft=tx2;
                            s[i][j].sc.sc=ty2;
                            }
                        }


                }

}

int main()
{
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            scanf("%I64d",&a[i][j]);
    for (int d=1;d<=k;d++)
    {
        scanf("%d%d%d%d",&x,&y,&u,&v);
        for (int i=0;i<=m;i++)
            for (int j=0;j<=n;j++) {s[i][j].ft=0;s[i][j].sc.ft=i;s[i][j].sc.sc=j;}
            s[x][y].sc.ft=x;
            s[x][y].sc.sc=y;
        for (int i=x;i<=u;i++)
            for (int j=y;j<=v;j++)
                xuli(i,j);
        int64_t tam=a[s[u][v].sc.ft][s[u][v].sc.sc];
        a[s[u][v].sc.ft][s[u][v].sc.sc]=0;
        int64_t tam1=s[u][v].sc.ft, tam2=s[u][v].sc.sc;

        for (int i=0;i<=m;i++)
            for (int j=0;j<=n;j++) {s[i][j].ft=0;s[i][j].sc.ft=0;s[i][j].sc.sc=0;}
        for (int i=x;i<=u;i++)
            for (int j=y;j<=v;j++)
                if(i!=tam1 || j!=tam2) xuli(i,j);
        cout<<s[u][v].ft<<endl;
        a[tam1][tam2]=tam;

    }


}
