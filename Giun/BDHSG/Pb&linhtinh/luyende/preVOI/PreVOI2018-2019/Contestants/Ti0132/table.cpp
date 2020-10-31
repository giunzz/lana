#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define LL long long
#define ii pair<LL,LL>
#define II pair<ii,ii>
using namespace std;

const int N=300+10;
int m,n,k;
int a[N][N];
LL f[N][N];
map<II,LL> kt;

int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>m>>n>>k;
    FOR(i,1,m)
        FOR(j,1,n)
            cin>>a[i][j];

    FOR(i,1,m)
        FOR(j,1,n)
        {
            memset(f,0,sizeof(f));
            FOR(u,i,m)
                FOR(v,j,n)
                {
                    f[u][v]=max(f[u-1][v],f[u][v-1])+a[u][v];
                    kt[II(ii(i,j),ii(u,v))]=f[u][v];
                }
        }

    while ((k--)>0)
    {
        int x,y,s,t;
        cin>>x>>y>>s>>t;
        LL res=kt[II(ii(x,y),ii(s,t))];
        FOR(i,x,s)
            FOR(j,y,t)
                if ((i!=x || j!=y) && (i!=s || j!=t))
                {
                    if (kt[II(ii(x,y),ii(i,j))]+kt[II(ii(i,j),ii(s,t))]<kt[II(ii(x,y),ii(s,t))]) continue;
                    else
                    {
                        memset(f,0,sizeof(f));
                        FOR(u,x,s)
                            FOR(v,y,t)
                                if (u!=i || v!=j)
                                    f[u][v]=max(f[u-1][v],f[u][v-1])+a[u][v];

                        res=min(res,f[s][t]);
                    }
                }
        cout<<res<<endl;
    }
}
