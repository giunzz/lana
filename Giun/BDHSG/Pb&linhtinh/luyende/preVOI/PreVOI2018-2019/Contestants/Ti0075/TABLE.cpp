#include <bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
int m,n,k;
int dp[37][37];
int oo=2e9;
int a[307][307];
int f[107][107];
int slv(int i,int j,int p,int q,int up,int vq)
{
    if (i==p&&j==q) return a[p][q];
    if (i==up&&j==vq) return -oo;
    if (i>p||j>q) return -oo;
    if (dp[i][j]!=-1) return dp[i][j];
    int cur=0;
    cur=max(slv(i+1,j,p,q,up,vq)+a[i][j],slv(i,j+1,p,q,up,vq)+a[i][j]);
    return dp[i][j]=cur;
}
int slv1(int i,int j,int p,int q,int up,int vq)
{
    if (i==p&&j==q) return a[p][q];
    if (i==up&&j==vq) return -oo;
    if (i>p||j>q) return -oo;
    if (f[i][j]!=-1) return f[i][j];
    int cur=0;
    cur=max(slv1(i+1,j,p,q,up,vq)+a[i][j],slv1(i,j+1,p,q,up,vq)+a[i][j]);
    return f[i][j]=cur;
}
void sub1(int u,int v,int p,int q)
{
    memset(dp,-1,sizeof(dp));
    //int res=slv(u,v,p,q,0,0);
    int kq=slv(u,v,p,q,0,0);
    for (int i=u;i<=p;i++)
        for (int j=v;j<=q;j++)
    {
        if ((i==u&&j==v)||(i==p&&j==q)) continue;
        memset(dp,-1,sizeof(dp));
        kq=min(kq,slv(u,v,p,q,i,j));
    }
    cout<<kq<<"\n";
}
void sub2(int u,int v,int p,int q)
{
    static ii dp1[107][107];
    static ii dp2[107][107];
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    dp1[u][v].fi=a[u][v];
    dp1[u][v].se=1;
    dp1[u][v+1].fi=a[u][v]+a[u][v+1];
    dp1[u][v+1].se=1;
    dp1[u+1][v].fi=a[u][v]+a[u+1][v];
    dp1[u+1][v].se=1;
    dp2[p][q].fi=a[p][q];
    dp2[p-1][q].fi=a[p][q]+a[p-1][q];
    dp2[p][q-1].fi=a[p][q]+a[p][q-1];
    dp2[p][q].se=dp2[p][q-1].se=dp2[p-1][q].se=1;
    for (int i=u+1;i<=p;i++)
        for (int j=v+1;j<=q;j++)
        {
            if (dp1[i-1][j].fi==dp1[i][j-1].fi)
            {
                dp1[i][j].fi=dp1[i-1][j].fi+a[i][j];
                dp1[i][j].se=dp1[i-1][j].se+dp1[i][j-1].se;
            }
            else
            {
                if (dp1[i-1][j].fi>dp1[i][j-1].fi)
                {
                    dp1[i][j].fi=dp1[i-1][j].fi+a[i][j];
                    dp1[i][j].se=dp1[i-1][j].se;
                }
                else
                {
                    dp1[i][j].fi=dp1[i][j-1].fi+a[i][j];
                    dp1[i][j].se=dp1[i][j-1].se;
                }
            }
        }
    for (int i=p-1;i>=u;i--)
        for (int j=q-1;j>=v;j--)
        {
           if (dp2[i+1][j].fi==dp2[i][j+1].fi)
            {
                dp2[i][j].fi=dp2[i+1][j].fi+a[i][j];
                dp2[i][j].se=dp2[i+1][j].se+dp2[i][j+1].se;
            }
            else
            {
                if (dp2[i+1][j].fi>dp2[i][j+1].fi)
                {
                    dp2[i][j].fi=dp2[i+1][j].fi+a[i][j];
                    dp2[i][j].se=dp2[i+1][j].se;
                }
                else
                {
                    dp2[i][j].fi=dp2[i][j+1].fi+a[i][j];
                    dp2[i][j].se=dp2[i][j+1].se;
                }
            }
        }
    int kq=dp1[p][q].fi;
    //cout<<dp1[p][q].se<<"\n";
    if (dp1[p][q].se==1)
    {
        for (int i=u;i<=p;i++)
            for (int j=v;j<=q;j++)
        {
            if ((i==u&&j==v)||(i==p&&j==q)) continue;
            if (dp1[i][j].fi+max(dp2[i][j+1].fi,dp2[i+1][j].fi)==dp1[p][q].fi)
            {
                memset(f,-1,sizeof(f));
                kq=min(kq,slv1(u,v,p,q,i,j));
            }
        }
        cout<<kq<<"\n";
    }
    else
    {
        for (int i=u;i<=p;i++)
            for (int j=v;j<=p;j++)
        {
            if ((i==u&&j==v)||(i==p&&j==q)) continue;
            if (dp1[i][j].fi+max(dp2[i][j+1].fi,dp2[i+1][j].fi)==dp1[p][q].fi)
            {
                int man=dp1[i][j].se;
                if (dp2[i][j+1].fi>dp2[i+1][j].fi)
                {
                    man=man*dp2[i][j+1].se;
                }
                else
                {
                    if (dp2[i][j+1].fi<dp2[i+1][j].fi)
                    {
                        man=man*dp2[i+1][j].se;
                    }
                    else man=man*(dp2[i][j+1].se+dp2[i+1][j].se);
                }
                if (man==dp1[p][q].se)
                {
                    memset(f,-1,sizeof(f));
                    kq=min(kq,slv1(u,v,p,q,i,j));
                }
            }
        }
        cout<<kq<<"\n";
    }
}
int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) cin>>a[i][j];
    if (m<=30&&n<=30&&k<=30)
    {
        for (int i=1;i<=k;i++)
        {
            int u,v,p,q;
            cin>>u>>v>>p>>q;
            sub1(u,v,p,q);
        }
    }
    else
    {
        if (m<=100&&n<=100&&k<=100)
        {
            for (int i=1;i<=k;i++)
            {
                int u,v,p,q;
                cin>>u>>v>>p>>q;
                sub2(u,v,p,q);
            }
        }
    }
    return 0;
}
