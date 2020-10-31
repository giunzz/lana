//*******GIANG*******//
#include <bits/stdc++.h>
#define N 15
#define M 2000
#define MOD 1000000007
#define MAXX 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "TEAWORLD"

using namespace std;

struct data
{
  int x, y, z, r, id;
};

int m, n, k, delLeft[M+7], delRight[M+7], ball1=0, ball2 = 0, pos=N+M+7, z=0, y=0, res=0, sum=0;
data a[N+M+7];

void readData()
{
  scanf("%d%d%d",&m,&n,&k);
  for(int i=1 ; i<=n+m+1 ; ++i)
  {
    if(i <= n+m) scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].z,&a[i].r);
    if(i == n+m+1) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    if(i <= m) a[i].id = -1;
    if(m < i && i <= n+m) a[i].id = 1, sum += a[i].r;
    if(i == n+m+1) a[i].id = 0;
    y += (a[i].y == 0), z += (a[i].z == 0);
  }
}

bool compare(data p, data q)
{
  return p.x < q.x;
}

void produce()
{
  sort(a+1,a+n+m+2,compare);
  for(int i=1 ; i<=n+m+1 ; ++i)
    if(a[i].id == 0) pos = i;
  for(int i=pos-1 ; i>0 ; --i)
  {
    if(a[i].id == -1) ball1++, delLeft[ball1] = delLeft[ball1-1];
    else delLeft[ball1] = delLeft[ball1-1] + a[i].r;
  }
  for(int i=pos+1 ; i<=n+m+1 ; ++i)
  {
    if(a[i].id == -1) ball2++, delRight[ball2] = delRight[ball2-1];
    else delRight[ball2] = delRight[ball2-1] + a[i].r;
  }
  for(int i=0 ; i<=ball1 ; ++i)
  {
    if(i > k) break;
    res = max(res,delLeft[i]+delRight[k-i]);
  }
  printf("%d",res);
}

int main()
{
  ios_base::sync_with_stdio(false);
  freopen(Task".inp","r",stdin);
  freopen(Task".out","w",stdout);
  readData();
  if(k == m) printf("%d",sum);
  else
    if(y == n+m+1 && z == n+m+1) produce();
    else
      printf("%d",sum-a[n+m].r);
  return 0;
}
