//*******GIANG*******//
#include <bits/stdc++.h>
#define N 50000
#define MOD 1000000007
#define MAXX 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "BUBBLETEA"

using namespace std;

int n, k, ent[N+7], sum=0;
vector < pair <int, int> > a[N+7];

void readData()
{
  scanf("%d%d",&n,&k);
  for(int i=1 ; i<=k ; ++i)
    scanf("%d",&ent[i]);
  for(int i=1 ; i<n ; ++i)
  {
    int u, v, w;
    scanf("%d%d%d",&u,&v,&w);
    a[u].pb(mp(v,w)), a[v].pb(mp(u,w));
    if(i == 1 || i == n-1) sum += w;
  }
}

void produce()
{
  if(k < n) printf("-1");
  if(k == n) printf("%d",sum);
}

int main()
{
  ios_base::sync_with_stdio(false);
  freopen(Task".inp","r",stdin);
  freopen(Task".out","w",stdout);
  readData();
  produce();
  return 0;
}
