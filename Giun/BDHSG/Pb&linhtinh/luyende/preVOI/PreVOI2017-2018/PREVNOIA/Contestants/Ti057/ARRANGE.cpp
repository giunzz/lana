//*******GIANG*******//
#include <bits/stdc++.h>
#define N 100000
#define MOD 1000000007
#define MAXX 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "ARRANGE"

using namespace std;

int n, a[N+7];
long long sum = 0, res=0;

void readData()
{
  scanf("%d",&n);
  for(int i=1 ; i<=n ; ++i)
    scanf("%d",&a[i]), sum += 1ll*a[i];
}

void produce()
{
  if(sum % n == 0)
  {
    int tmp = sum / n;
    for(int i=1 ; i<=n ; ++i)
    {
      if(a[i] > tmp)
      {
        int d = a[i] - tmp, j = 1;
        while(d > 0 && j <= max(i-1,n-i))
        {
          if(a[i-j] + d > tmp && i-j > 0)
          {
            res += (tmp - a[i-j]) * j;
            a[i] -= (tmp - a[i-j]);
            d -= (tmp - a[i-j]);
            a[i-j] = tmp;
          }
          else
          {
            if(a[i-j] + d <= tmp && i-j > 0)
            {
              res += d * j;
              a[i] -= d;
              a[i-j] += d;
              d = 0;
            }
          }
          if(a[i+j] + d > tmp && i+j <= n)
          {
            res += (tmp - a[i+j]) * j;
            a[i] -= (tmp - a[i+j]);
            d -= (tmp - a[i+j]);
            a[i+j] = tmp;
          }
          else
          {
            if(a[i+j] + d <= tmp && i+j <= n)
            {
              res += d * j;
              a[i] -= d;
              a[i+j] += d;
              d = 0;
            }
          }
          j++;
        }
      }
    }
    printf("%d",res);
  }
  else printf("1");
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
