#include <bits/stdc++.h>
using namespace std;
int a[303][303];
int f[303][303];
pair<int,int> f1[303][303];
int a1[303][303];
int ok[303][303];
int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    int n,m,k;
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    int u,v,p,q;
    while(k--)
    {
    int res=LONG_MAX;
    memset(f,0,sizeof(f));
    memset(ok,0,sizeof(ok));
    scanf("%d%d%d%d",&u,&v,&p,&q);
    for(int i=u;i<=p;i++)
        {
        for(int j=v;j<=q;j++)
        {
            if(f[i][j-1]<f[i-1][j])
            {
                f[i][j]=f[i-1][j]+a[i][j];
                f1[i][j]={i-1,j};

            }
            else
            {
                f[i][j]=f[i][j-1]+a[i][j];
                f1[i][j]={i,j-1};
            }
        }

        }
        int x=p;
        int y=q;

        while(f1[x][y].first!=u&&f1[x][y].second!=v)
        {
            memset(f,0,sizeof(f));
                x=f1[x][y].first;
                y=f1[x][y].second;
                ok[x][y]=1;
                for(int i=u;i<=p;i++)
                        for(int j=v;j<=q;j++)
                            {
                            if(ok[i][j]==0)
                                        {
                                                    if(f[i][j-1]<f[i-1][j])
                                                        {

                                                        f[i][j]=f[i-1][j]+a[i][j];

                                                        }
                                        else
                                        {
                                            f[i][j]=f[i][j-1]+a[i][j];
                                        }

                                        }
                                    }

            res=min(res,f[p][q]);
            ok[x][y]=0;
        }

        printf("%d\n",res);
    }
  }
