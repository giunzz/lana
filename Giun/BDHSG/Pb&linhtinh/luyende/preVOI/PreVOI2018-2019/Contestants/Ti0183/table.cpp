// KHAz
#include<bits/stdc++.h>
#define maxn 303
#define F first
#define S second
#define PB push_back
#define mp make_pair
#define reset(x) memset(x,0,sizeof(x))
#define Task "table"
#define pii pair < int , int >
#define ll long long
using namespace std;
int a[maxn][maxn],n,m,k,f[maxn][maxn],g[maxn][maxn];
pii tr[maxn][maxn];
int dd[maxn][maxn];
void sub1()
{

    for(int ss=1; ss<=k; ss++)
    {
        int u,v,p,q;
        cin>>u>>v>>p>>q;
         reset(f);
        f[u-1][v]=f[u][v-1]=0;
        reset(dd);
        for(int i=0;i<=p;i++) dd[i][v-1]=1;
        for(int i=0;i<q;i++) dd[u-1][i]=1;
        dd[u-1][v]=dd[u][v-1]=0;
        int ans=2e9;
        for(int i=u; i<=p; i++)
            for(int j=v; j<=q; j++)
            {
                if((i==u&&j==v)||(i==p&&j==q)) continue;
                dd[i][j]=1;
                for(int l=u; l<=p; l++)
                {
                    for(int h=v; h<=q; h++)
                    {
//                        if(l==u)
//                        {
//                            if(f[l-1][h]==-1e9) f[l][h]=f[l-1][h];
//                        }
                        if(l==i&&h==j) {f[l][h]=-1e9;continue;}
                        if(dd[l-1][h]==0&&dd[l][h-1]==0) f[l][h]=max(f[l-1][h],f[l][h-1])+a[l][h];
                        else
                        {
                            if(dd[l-1][h]==1)
                            {
                                if(f[l][h-1]!=1e9) f[l][h]=f[l][h-1]+a[l][h];
                                else f[l][h]=-1e9;
                            }
                            else
                            {
                                if(f[l-1][h]!=1e9) f[l][h]=f[l-1][h]+a[l][h];
                                else f[l][h]=-1e9;
                            }
                        }
                    }
                }
                ans=min(ans,f[p][q]);
                dd[i][j]=0;
            }
        cout<<ans<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Task".inp","r",stdin);
     freopen(Task".out","w",stdout);
    cin>>m>>n>>k;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++) cin>>a[i][j];
    sub1();
}
