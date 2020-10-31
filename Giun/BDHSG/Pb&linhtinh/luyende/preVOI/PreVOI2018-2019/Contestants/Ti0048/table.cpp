#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mn=305;
const int oo=3000000009;
int m,n,k;
int a[mn][mn];
int b[mn][mn];
void sub1()
{
   while(k--)
   {

       int res=oo;
       int u,v,p,q;
       cin>>u>>v>>p>>q;
       for(int i=u;i<=p;i++)
        for(int j=v;j<=q;j++)
       {
           fill(&b[0][0],&b[n][m]+1,0);
           for(int h=u;h<=p;h++)
            for(int k=v;k<=q;k++)b[h][k]=a[h][k];
           if((i==u&&j==v)||(i==p&&j==q))b[i][j]=a[i][j];
           else b[i][j]=-oo;
           for(int h=u;h<=p;h++)
            for(int k=v;k<=q;k++)
                b[h][k]=max(b[h-1][k],b[h][k-1])+b[h][k];
                res=min(res,b[p][q]);
       }
       cout<<res<<'\n';
   }
   exit(0);
}
pair<int,int> tr[mn][mn];
vector<pair<int,int> > g;
void sub2()
{
        while(k--)
        {
           int  res=oo;
            fill(&b[0][0],&b[n][m]+1,0);
            int u,v,p,q;
            cin>>u>>v>>p>>q;
        for(int i=u;i<=p;i++)
        for(int j=v;j<=q;j++)
        {
            if(b[i-1][j]<=b[i][j-1]) tr[i][j]={i,j-1};else tr[i][j]={i-1,j};
            b[i][j]=max(b[i-1][j],b[i][j-1])+a[i][j];
        }
        g.clear();
            int l=p;int r=q;
            while(tr[l][r]!=make_pair(u,v)&&(l>=u&&r>=v))
                {
                    int h=l,k=r;
                    g.push_back(tr[l][r]);
                    l=tr[h][k].first;
                    r=tr[h][k].second;
                }
        for(auto hkh:g)
       {
           int i=hkh.first;
           int j=hkh.second;
           if(i<u||j<v)continue;
           fill(&b[0][0],&b[n][m]+1,0);
           for(int h=u;h<=p;h++)
            for(int k=v;k<=q;k++)
            b[h][k]=a[h][k];
            b[i][j]=-oo;
           for(int h=u;h<=p;h++)
             for(int k=v;k<=q;k++)
                b[h][k]=max(b[h-1][k],b[h][k-1])+b[h][k];
             res=min(res,b[p][q]);
       }
       if(res==oo)cout<<a[u][v]+a[p][q]<<'\n';
        else cout<<res<<'\n';
        }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        cin>>a[i][j];
    if(n<=30&&m<=30) sub1();
    sub2();
    return 0;
}

