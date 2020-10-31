#include<bits/stdc++.h>


using namespace std;
typedef long long ll;
int n,m,k;
ll a[305][305],f[305][305];
int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    ios_base::sync_with_stdio(false);
   cin>>m>>n>>k;
   for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
        cin>>a[i][j];
    while(k--)
    {
        int u,v,p,q;
        cin>>u>>v>>p>>q;
        ll ans=1e18;
        for(int i=u;i<=p;i++)
            for(int j=v;j<=q;j++)
                if((i*j)!=1 && (i*j)!=(p*q))
        {
            for(int l=0;l<=40;l++)
                for(int r=0;r<=40;r++)
                    f[l][r]=0;
            f[i][j]=-1e18;
            for(int l=u;l<=p;l++)
                for(int r=v;r<=q;r++)
                    if(f[l][r]==0)
                        {
                            f[l][r]=max(f[l-1][r],f[l][r-1])+a[l][r];
                            //if(i==3 && j==3) cout<<l<<" "<<r<<" "<<f[l][r]<<endl;
                        }
            ans=min(ans,f[p][q]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
