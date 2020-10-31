#include<bits/stdc++.h>
#define maxn 5005
#define oo 2000000000
using namespace std ;
int n,a[maxn],x[maxn],slx,deg[maxn],cl[maxn];
int f[maxn][5];
vector<int>g[maxn];
void DFS(int u){
   cl[u]=1;
   for(int i=0;i<deg[u];i++){
       int v=g[u][i];
       if(cl[v]==0){
          DFS(v);
       }
   }
   x[--slx]=u;
}
int main(){
   freopen("TREE.inp","r",stdin);
   freopen("TREE.out","w",stdout);
   scanf("%d",&n);
   for(int i=1;i<=n;i++)scanf("%d",&a[i]);
   for(int i=1;i<=n-1;i++){
       int u,v;
       scanf("%d %d",&u,&v);
       g[u].push_back(v);deg[u]++;
   }
   slx=n+1;
   DFS(1);
   for(int u=1;u<=n;u++)if(deg[u]==0){
       f[u][0]=abs(0-a[u]);
       f[u][1]=abs(1-a[u]);
   }
   for(int i=n;i>=2;i--)if(f[x[i]][0]==0&&f[x[i]][1]==0){
       int u=x[i];
       f[u][0]=abs(0-a[u]);
       f[u][1]=abs(1-a[u]);
       if(deg[u]==2){
          int v1=g[u][0];
          int v2=g[u][1];
          f[u][0]+=f[v1][0]+f[v2][0];
          f[u][1]+=min(f[v1][0]+f[v2][1],f[v1][1]+f[v2][0]);
       }
       else if(deg[u]==1){
           int v=g[u][0];
           f[u][0]+=f[v][0];
           f[u][1]+=f[v][1];
       }
   }
   int ds=oo;
   int u=1;
   if(deg[1]==2){
      int v1=g[u][0];
      int v2=g[u][1];
      ds=min(ds,f[v1][1]+f[v2][1]+abs(2-a[1]));
      ds=min(ds,f[v1][0]+f[v2][0]+abs(0-a[1]));
      ds=min(ds,f[v1][1]+f[v2][0]+abs(1-a[1]));
      ds=min(ds,f[v1][0]+f[v2][1]+abs(1-a[1]));
   }
   printf("%d",ds);
}
