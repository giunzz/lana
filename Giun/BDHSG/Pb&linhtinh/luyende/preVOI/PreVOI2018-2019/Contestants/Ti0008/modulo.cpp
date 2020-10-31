#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int u,v,n;
ll k,po[70],f[70][12];
map<ll,int> g;
int main()
{
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
   cin>>u>>v>>n>>k;
   po[0]=1;
   ll mod=1;
   for(int i=1;i<=n;i++) mod=mod*2;
   for(int i=1;i<n;i++) po[i]=(po[i-1]*10)%mod;
   for(int i=0;i<n;i++)
   {
       for(int j=1;j<=9;j++)
        {
            f[i][j]=0;
            for(int k=1;k<=j;k++)
                f[i][j]=(f[i][j]+po[i])%mod;
        }
   }
   if(n<=20)
   {
    for(int i=0;i<(1<<n);i++)
   {
       ll res=0;
       for(int j=0;j<n;j++)
        {
            if(!(i & (1<<j)))
                res=(res+f[n-j-1][u])%mod;
                else res=(res+f[n-j-1][v])%mod;
                //if(i==0) cout<<res<<endl;
        }
        if(res%mod==k)
        {
            for(int j=0;j<n;j++)
                if(!(i&(1<<j))) cout<<u;
                        else cout<<v;
            return 0;
        }
   }
   cout<<-1;
   }
   else
   {
       int m=n/2;
       for(int i=0;i<(1<<m);i++)
      {
       ll res=0;
       for(int j=0;j<m;j++)
        {
            if(!(i & (1<<j)))
                res=(res+f[n-j-1][u])%mod;
                else res=(res+f[n-j-1][v])%mod;
                //if(i==0) cout<<res<<endl;
        }
        res=res%mod;
        g[res]=i+1;
      }
       for(int i=0;i<(1<<(n-m));i++)
      {
       ll res=0;
       for(int j=0;j<(n-m);j++)
        {
            if(!(i & (1<<j)))
                res=(res+f[n-j-1-m][u])%mod;
                else res=(res+f[n-j-1-m][v])%mod;
                //if(i==0) cout<<res<<endl;
        }
        res=res%mod;
        //cout<<res<<endl;
        if(g[(2*k-res)%mod]>0)
        {
            int ok=g[(2*k-res)%mod]-1;
            for(int j=0;j<m;j++)
                if(!(ok&(1<<j))) cout<<u; else cout<<v;
            for(int j=0;j<n-m;j++)
                if(!(i&(1<<j))) cout<<u; else cout<<v;
                return 0;
        }
      }
    cout<<-1;
   }
    return 0;
}
