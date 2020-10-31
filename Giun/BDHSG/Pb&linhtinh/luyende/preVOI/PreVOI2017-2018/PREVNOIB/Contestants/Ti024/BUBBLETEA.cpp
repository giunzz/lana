#include<bits/stdc++.h>
#define maxn 50005
#define oo int(2e9)
using namespace std ;
int n,k;
int a[maxn];
int main(){
   freopen("BUBBLETEA.inp","r",stdin);
   freopen("BUBBLETEA.out","w",stdout);
   scanf("%d %d",&n,&k);
   for(int i=1;i<=k;i++)scanf("%d",&a[i]);
   //for(int i=1;i<=n;i++)f[u][v]=a[u][v]=oo;
   for(int i=1;i<=n-1;i++){
       int u,v,l;
       scanf("%d %d",&u,&v);
       cin>>l;
       //g[u].push_back(II(v,l));
       //deg[u]++;
       //g[v].push_back(II(u,l));
       //deg[v]++;
       //a[u][v]=a[v][u]=l;
       //f[u][v]=l;
   }

   cout<<"-1";
}
