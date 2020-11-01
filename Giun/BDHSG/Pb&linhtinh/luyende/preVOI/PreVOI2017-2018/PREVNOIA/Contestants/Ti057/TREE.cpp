//*******GIANG*******//
#include <bits/stdc++.h>
#define N 5000
#define MOD 1000000007
#define MAXX (1e9+7)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "TREE"

using namespace std;

int n, num[N+7], child[N+7], id=0, leave[N+7], cur[N+7], tp[N+7], cnt=0, par[N+7], res=MAXX, dp[N+7][N+7];
vector <int> a[N+7];

void readData()
{
  scanf("%d",&n);
  for(int i=1 ; i<=n ; ++i)
    scanf("%d",&num[i]), child[i] = 1;
  for(int i=1 ; i<n ; ++i)
  {
    int u, v;
    scanf("%d%d",&u,&v);
    a[u].pb(v), a[v].pb(u);
  }
}

void dfs(int u)
{
  tp[u] = ++cnt;
  for(int i=0 ; i<a[u].size() ; ++i)
  {
    int v = a[u][i];
    if(v == par[u]) continue;
    par[v] = u;
    dfs(v);
    child[u] += child[v];
  }
}

int getBIT(int x, int y)
{
  return (x >> y) & 1;
}

void produce1()
{
  for(int i=0 ; i<(1<<id) ; ++i)
  {
    memset(cur,0,sizeof(cur));
    int tmp = 0;
    for(int j=0 ; j<id ; ++j)
      if(getBIT(i,j)) cur[leave[j+1]] = 1;
    for(int j=n ; j>0 ; --j)
    {
      int u = tp[j];
      for(int k=0 ; k<a[u].size() ; ++k)
      {
        int v = a[u][k];
        if(v == par[u]) continue;
        cur[u] += cur[v];
      }
      tmp += abs(num[u] - cur[u]);
    }
    res = min(res,tmp);
  }
  printf("%d",res);
}

void produce2()
{
  memset(leave,0,sizeof(leave));
  memset(dp,60,sizeof(dp));
  for(int i=n ; i>0 ; --i)
  {
    int u = tp[i];
    for(int j=0 ; j<a[u].size() ; ++j)
    {
      int v = a[u][j];
      if(v == par[u]) continue;
      if(child[v] == 1) leave[u]++;
      else leave[u] += leave[v];
    }
  }
  for(int i=n ; i>0 ; --i)
  {
    int u = tp[i];
    if(child[i] == 1) dp[u][0] = num[u], dp[u][1] = abs(num[u]-1);
    else
    {
      int v1=0, v2=0;
      if(par[tp[i+1]] == u) v1 = tp[i+1];
      if(par[tp[i+2]] == u) v2 = tp[i+2];
      for(int j=0 ; j<=leave[u] ; ++j)
      {
        if(v1 == 0) dp[u][j] = min(dp[u][j],dp[v2][j] + abs(num[u]-j));
        if(v2 == 0) dp[u][j] = min(dp[u][j],dp[v1][j] + abs(num[u]-j));
        else
          for(int k=0 ; k<=j ; ++k)
            dp[u][j] = min(dp[u][j],dp[v1][k] + dp[v2][j-k] + abs(num[u]-j));
      }
    }
  }
  for(int i=0 ; i<=leave[1] ; ++i)
    res = min(res,dp[1][i]);
  printf("%d",res);
}

int main()
{
  ios_base::sync_with_stdio(false);
  freopen(Task".inp","r",stdin);
  freopen(Task".out","w",stdout);
  readData();
  dfs(1);
  for(int i=1 ; i<=n ; ++i)
    if(child[i] == 1) leave[++id] = i;
  if(id <= 25) produce1();
  else produce2();
  return 0;
}
