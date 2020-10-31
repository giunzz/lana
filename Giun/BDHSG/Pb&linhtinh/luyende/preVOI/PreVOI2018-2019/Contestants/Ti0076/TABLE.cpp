#include <bits/stdc++.h>

using namespace std;
int n,m,k,u,v,p,q;
typedef pair<int,int> II;
int a[305][305],t[305][305],dd[305][305];
II ma[305][305];
int tinh(int i,int j)
{
    if (i>=u && i<<p && j>=v && j<=q)
        if (dd[i][j]==0) return 1;
    return 2;
}
int main()
{
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    a[0][0]=-1e9;
    scanf("%d%d%d",&m,&n,&k);
    for (int i=1;i<=m;++i)
        for (int j=1;j<=n;++j) scanf("%I64d",&a[i][j]);
    for (int i=1;i<=k;++i)
    {
        scanf("%d%d%d%d",&u,&v,&p,&q);
        t[u][v]=a[u][v];
        ma[u][v].first=ma[u][v].second=0;
        for (int j=v+1;j<=q;++j)
        {
            t[u][j]=t[u][j-1]+a[u][j];
            if (a[u][j]>a[ma[u][j-1].first][ma[u][j-1].second])
            {
                ma[u][j].first=u; ma[u][j].second=j;
            }
            else
            {
                ma[u][j].first=ma[u][j-1].first;
                ma[u][j].second=ma[u][j-1].second;
            }
        }
        for (int j=u+1;j<=p;++j)
        {
            t[j][v]=t[j-1][v]+a[j][v];
            if (a[j][v]>a[ma[j-1][v].first][ma[j-1][v].second])
            {
                ma[j][v].first=j; ma[j][v].second=v;
            }
            else
            {
                ma[j][v].first=ma[j-1][v].first;
                ma[j][v].second=ma[j-1][v].second;
            }
        }
        for (int j1=u+1;j1<=p;++j1)
            for (int j2=v+1;j2<=q;++j2)
            {
                if (t[j1-1][j2]>t[j1][j2-1])
                {
                    t[j1][j2]=a[j1][j2]+t[j1-1][j2];
                    if (a[j1][j2]>a[ma[j1-1][j2].first][ma[j1-1][j2].second])
                    {
                        ma[j1][j2].first=j1; ma[j1][j2].second=j2;
                    }
                    else
                    {
                        ma[j1][j2].first=ma[j1-1][j2].first;
                        ma[j1][j2].second=ma[j1-1][j2].second;
                    }
                }
                if (t[j1-1][j2]<t[j1][j2-1])
                {
                    t[j1][j2]=a[j1][j2]+t[j1][j2-1];
                    if (a[j1][j2]>a[ma[j1][j2-1].first][ma[j1][j2-1].second])
                    {
                        ma[j1][j2].first=j1; ma[j1][j2].second=j2;
                    }
                    else
                    {
                        ma[j1][j2].first=ma[j1][j2-1].first;
                        ma[j1][j2].second=ma[j1][j2-1].second;
                    }
                }
                if (t[j1-1][j2]==t[j1][j2-1])
                {
                    int u1,v1;
                    if (a[ma[j1-1][j2].first][ma[j1-1][j2].second]>a[ma[j1][j2-1].first][ma[j1][j2-1].second])
                        { u1=ma[j1-1][j2].first; v1=ma[j1-1][j2].second;}
                    else { u1=ma[j1][j2-1].first; v1=ma[j1][j2-1].second; }
                    if (a[j1][j2]>a[u1][v1])
                    {
                        ma[j1][j2].first=j1; ma[j1][j2].second=j2;
                    }
                    else
                    {
                        ma[j1][j2].first=u1;
                        ma[j1][j2].second=v1;
                    }
                }
            }
        int j1=p,j2=q;
        if (t[j1-1][j2]>t[j1][j2-1])
                {
                    ma[j1][j2].first=ma[j1-1][j2].first;
                    ma[j1][j2].second=ma[j1-1][j2].second;
                }
        if (t[j1-1][j2]<t[j1][j2-1])
                {
                        ma[j1][j2].first=ma[j1][j2-1].first;
                        ma[j1][j2].second=ma[j1][j2-1].second;
                }
        if (t[j1-1][j2]==t[j1][j2-1])
        {
            int x1=a[ma[j1-1][j2].first][ma[j1-1][j2].second];
            int x2=a[ma[j1][j2-1].first][ma[j1][j2-1].second];
            if (x1>x2)
                {
                    ma[j1][j2].first=ma[j1-1][j2].first;
                    ma[j1][j2].second=ma[j1-1][j2].second;
                }
            else
                 {
                        ma[j1][j2].first=ma[j1][j2-1].first;
                        ma[j1][j2].second=ma[j1][j2-1].second;
                }
        }
        dd[ma[j1][j2].first][ma[j1][j2].second]=1;
        for (int j=u;j<=p;++j)
            for (int j2=v;j2<=q;++j2)
            {
                t[j][j2]=0; int x1,x2;
                x1=tinh(j-1,j2);
                x2=tinh(j,j2-1);
                if (x1==2 && x2==2)
                    {if (j==u && j2==v) t[j][j2]=a[j][j2];
                    else t[j][j2]=0;}
                if (x1==1 && x2==2) t[j][j2]=t[j-1][j2]+a[j][j2];
                if (x1==2 && x2==1) t[j][j2]=t[j][j2-1]+a[j][j2];
                if (x1==1 && x2==1) t[j][j2]=max(t[j][j2-1],t[j-1][j2])+a[j][j2];
            }
        printf("%d\n",t[p][q]);
        dd[ma[j1][j2].first][ma[j1][j2].second]=0;
    }
}
