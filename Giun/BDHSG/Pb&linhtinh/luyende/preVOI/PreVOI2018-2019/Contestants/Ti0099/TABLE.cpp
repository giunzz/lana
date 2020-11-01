#include <bits/stdc++.h>

using namespace std;
   int u,v,p,q,a[350][350],m,n,k;
   long long sum,ma,mi=1e18;;
   bool f[350][350];


void loang(int i,int j)
{
   if ((i<u)||(i>p)||(j<v)||(j>q))
       return;
   if (f[i][j]==false)
       return;
   f[i][j]=false;
   sum=sum+a[i][j];
   if ((i==p)&&(j==q))
     ma=max(ma,sum);
   loang(i+1, j);
   loang(i, j+1);
   f[i][j]=true;
   sum-=a[i][j];
}
int main()
{
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n>>k;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
          cin>>a[i][j];
    memset(f,true,sizeof(f));
    for (int x=1; x<=k; x++)
    {
        cin>>u>>v>>p>>q;
        mi=1e18;
        for (int i=u; i<=p; i++)
            for (int j=v; j<=q; j++)
            {
                ma=-1e18;
                if ((i==u&&j==v) || (i==p&&j==q))
                    continue;
                f[i][j]=false;
                sum=0;
                loang(u,v);
                f[i][j]=true;
                mi=min(ma,mi);
            }
        cout<<mi<<'\n';
    }
}
