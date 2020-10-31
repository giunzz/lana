//*******GIANG*******//
#include <bits/stdc++.h>
#define N 1000000
#define MOD 1000000007
#define MAXX 1ll*(1e18+7)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "GIFTS"

using namespace std;

int n, k, a[N+7];
long long sum[N+7], d[N+7], c[N+7], res = MAXX;

void readData()
{
  scanf("%d%d",&n,&k);
  for(int i=1 ; i<=n ; ++i)
    scanf("%d",&a[i]);
}

void makeSUM()
{
  for(int i=1 ; i<=k ; ++i)
    sum[k] += 1ll*a[i];
  for(int i=k+1 ; i<=n ; ++i)
    sum[i] = sum[i-1] - 1ll*a[i-k] + 1ll*a[i];
}

void produce()
{
  makeSUM();
  for(int i=k ; i<=n ; ++i)
    d[i] = max(d[i-1],sum[i-k]);
  for(int i=n-k ; i>=k ; --i)
    c[i] = max(c[i+1],sum[i+k]);
//  for(int i=1 ; i<=n ; ++i)
//    printf("%lli %lli %lli\n",sum[i],d[i],c[i]);
  for(int i=k ; i<=n ; ++i)
  {
    if(max(d[i],c[i]) > sum[i]) continue;
    res = min(res,sum[i]);
  }
  printf("%lli",res);
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
