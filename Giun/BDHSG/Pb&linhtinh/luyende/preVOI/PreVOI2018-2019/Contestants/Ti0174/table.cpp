#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define endl "\n"
#define task "table"
#define int int64_t
using namespace std;
template <typename T> inline void R(T &x)
{
    bool neg=false;
    register int c;
    x=0;
    c=getchar();
    if (c=='-')
    {
        neg=true;
        c=getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        x=(x>>1)+(x>>3)+c-48;
    if (neg) x=-x;
}
const int N=305;
const int M=N;
const int oo=1e14;
int m,n,k,a[M][N],u,v,p,q,f[M][N],tmp;
void sub1()
{
    for (int t=1; t<=k; ++t)
    {
        cin>>u>>v>>p>>q;
        tmp=oo;
        for (int ii=u; ii<=p; ++ii)
        {
            for (int jj=v; jj<=q; ++jj)
            {
                if ( !(ii==u && jj==v) && !(ii==p && jj==q) ) {
                for (int i=1; i<=m; ++i)
                {
                    for (int j=1; j<=n; ++j)
                        f[i][j]=-oo;
                }
                f[u][v]=a[u][v];
                for (int i=u; i<=p; ++i)
                {
                    for (int j=v; j<=q; ++j)
                    {
                        if ( !(i==ii && j==jj) ) {
                        if (f[i-1][j]!=-oo)
                            f[i][j]=max(f[i][j],f[i-1][j]+a[i][j]);
                        if (f[i][j-1]!=-oo)
                            f[i][j]=max(f[i][j],f[i][j-1]+a[i][j]);
                        }
                    }
                }
                /*for (int i=u; i<=p; ++i)
                {
                    for (int j=v; j<=q; ++j)
                        cout<<f[i][j]<<" ";
                    cout<<endl;
                }*/
                    if (f[p][q]<tmp)
                    {
                        tmp=f[p][q];
                    //cout<<ii<<" "<<jj<<endl;
                    }
                }
            }
        }
        cout<<tmp<<"\n";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>m>>n>>k;
    for (int i=1; i<=m; ++i)
    {
        for (int j=1; j<=n; ++j)
            cin>>a[i][j];
    }
    for (int i=0; i<=m+1; ++i)
        f[i][0]=f[i][n+1]=-oo;
    for (int j=0; j<=n+1; ++j)
        f[0][j]=f[m+1][j]=-oo;
    sub1();
    return 0;
}
