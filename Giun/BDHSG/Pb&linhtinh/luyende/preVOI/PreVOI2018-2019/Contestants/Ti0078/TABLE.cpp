#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int m,n,k,u,v,p,q;
long long a[500][500],f[500][500],rf[500][500],up[500][500],le[500][500];
vector<pii> ve;

void Solve()
{
    if(u==p && v==q)
    {
        cout<<a[u][v]<<'\n';
        return;
    }

    memset(f,0,sizeof(f));
    memset(rf,0,sizeof(rf));
    memset(le,0,sizeof(le));
    memset(up,0,sizeof(up));

    for(int i=u;i<=p;++i)
    {
        for(int j=v;j<=q;++j)
        {
            if(i==u && j==v)f[i][j]=a[i][j];

            else
            {
                if(i==u)f[i][j]=f[i][j-1]+a[i][j];
                else
                {
                    if(j==v)f[i][j]=f[i-1][j]+a[i][j];
                    else f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
                }
            }
        }
    }

    /*for(int i=u;i<=p;++i)
    {
        for(int j=v;j<=q;++j)cout<<f[i][j]<<" ";
        cout<<'\n';
    }
    cout<<'\n';*/

    for(int i=p;i>=u;--i)
    {
        for(int j=q;j>=v;--j)
        {
            if(i==p && j==q)rf[i][j]=a[i][j];

            else
            {
                if(i==p)rf[i][j]=rf[i][j+1]+a[i][j];
                else
                {
                    if(j==q)rf[i][j]=rf[i+1][j]+a[i][j];
                    else rf[i][j]=max(rf[i+1][j],rf[i][j+1])+a[i][j];
                }
            }
        }
    }

    /*for(int i=u;i<=p;++i)
    {
        for(int j=v;j<=q;++j)cout<<rf[i][j]<<" ";
        cout<<'\n';
    }
    cout<<'\n';*/

    for(int i=u+1;i<=p;++i)
    {
        long long Max=0;

        for(int j=q;j>=v;--j)
        {
            Max=max(Max,rf[i][j]+f[i-1][j]);
            up[i][j]=Max;
        }
    }

    /*for(int i=u;i<=p;++i)
    {
        for(int j=v;j<=q;++j)cout<<up[i][j]<<" ";
        cout<<'\n';
    }*/

    for(int j=v+1;j<=q;++j)
    {
        long long Max=0;

        for(int i=p;i>=u;--i)
        {
            Max=max(Max,rf[i][j]+f[i][j-1]);
            le[i][j]=Max;
        }
    }

    /*for(int i=u;i<=p;++i)
    {
        for(int j=v;j<=q;++j)cout<<le[i][j]<<" ";
        cout<<'\n';
    }*/

    long long Min=(long long)1e16;

    /*for(int i=u;i<=p;++i)
    {
        up[i][q+1]=0;
        le[i][q+1]=0;
    }

    for(int j=v;j<=q;++j)
    {
        up[p+1][j]=0;
        le[p+1][j]=0;
    }*/

    for(int i=u;i<=p;++i)
    {
        for(int j=v;j<=q;++j)
        {
            if(i==u && j==v)continue;
            if(i==p && j==q)continue;

            if(i==u)Min=min(Min,le[i+1][j]);

            else
            {
                if(j==v)Min=min(Min,up[i][j+1]);
                else Min=min(Min,max(up[i][j+1],le[i+1][j]));
            }
        }
    }

    if(Min==(long long)1e16)cout<<0<<'\n';
    else cout<<Min<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);

    cin>>m>>n>>k;

    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)cin>>a[i][j];

    for(int i=1;i<=k;++i)
    {
        cin>>u>>v>>p>>q;

        Solve();
    }
}
