#include <bits/stdc++.h>
#define NMAX 5000
using namespace std;
struct point
{
  int node,val;
};
int f[NMAX+7][NMAX+7];
point make_point(int x, int y)
{
  point a;
  a.node=x;
  a.val=y;
  return a;
}
vector <int> tree[NMAX+7];
int n,l=0,k=0;
int a[NMAX+7],leaves[NMAX+7],cha[NMAX+7],h[NMAX+7],c[NMAX+7],b[NMAX+7], topo[NMAX+7];
bool leaf[NMAX+7];
void dfs(int u)
{
  ++k;
  topo[k]=u;
  for (int i=0; i<tree[u].size(); ++i)
  {
    int v=tree[u][i];
    h[v]=h[u]+1;
    cha[v]=u;
    dfs(v);
  }
}
void update(int u, int x)
{
  if (x==0) return;
  if (u==0) return;
  c[u]+=x;
  update(cha[u],x);
}
int get(int yy)
{
  int res=0;
  for (int i=1; i<=n; ++i)
    c[i]=0;
  for (int i=1; i<=l; ++i)
  {
    c[leaves[i]]=b[i];
    update(cha[leaves[i]],b[i]);
  }
  for (int i=1; i<=n; ++i)
    res+=abs(a[i]-c[i]);
  return res;
}
int main()
{
  freopen("TREE.inp","r",stdin);
  freopen("TREE.out","w",stdout);
  scanf("%d",&n);
  for (int i=1; i<=n; ++i)
    scanf("%d",&a[i]);
  for (int i=1; i<n; ++i)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    tree[x].push_back(y);
  }
  for (int i=1; i<=n; ++i)
    if (tree[i].size()==0)
    {
      leaf[i]=true;
      ++l;
      leaves[l]=i;
//      printf("%d ",i);
    }
//  printf("\n");
  cha[1]=0;
  h[1]=0;
  dfs(1);
//  sinh(1);
  for (int i=n; i>=1; --i)
   {
     int u=topo[i];
     if (leaf[u])
     {
       f[u][0]=a[u];
       f[u][1]=abs(a[u]-1);
     }
     else
     {
       for (int j=0; j<=n; ++j)
       {
         for (int i1=0; i1<=j; ++i1)
          f[u][j]=max(f[u][j],f[tree[u][0]][i1]+f[tree[u][1]][j-i1]+abs(a[u]-j));
       }
     }
   }
   int res=25000000;
  for (int i=0; i<=n; ++i)
    res=min(res,f[1][i]);
  printf("%d",res);
}
