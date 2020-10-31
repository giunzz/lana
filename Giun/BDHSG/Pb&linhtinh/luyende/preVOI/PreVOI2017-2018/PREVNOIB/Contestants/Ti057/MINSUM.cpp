//*******GIANG*******//
#include <bits/stdc++.h>
#define N 200000
#define MOD 1000000007
#define MAXX 1000000
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "MINSUM"

using namespace std;

int T, x, y, check[MAXX+7], prime[N+7], p=0, p1[N+7], p2[N+7];

void readData()
{
  scanf("%d%d",&x,&y);
}

bool Prime(int a)
{
  if(a < 2) return 0;
  if(a < 4) return 1;
  for(int i=2 ; i<=sqrt(a) ; ++i)
    if(a % i == 0) return 0;
  return 1;
}

void makePrime()
{
  for(int i=2 ; i<=MAXX ; ++i) check[i] = 1;
  for(int i=2 ; i<=sqrt(MAXX) ; ++i)
    if(check[i])
    {
      int j = 2;
      while(i*j <= MAXX)
      {
        check[i*j] = 0;
        j++;
      }
    }
  for(int i=1 ; i<=MAXX ; ++i)
    if(check[i]) prime[++p] = i;
}

void convert(int a, int b)
{
  if(Prime(a) && Prime(b))
  {
    printf("%d %d\n",a,b);
    return;
  }
  if(a % b == 0)
  {
    a /= b;
    b = 1;
  }
  if(b % a == 0)
  {
    b /= a;
    a = 1;
  }
  memset(p1,0,sizeof(p1));
  memset(p2,0,sizeof(p2));
  int tmp1 = a, tmp2 = b;
  for(int i=1 ; i<=p ; ++i)
  {
    while(a % prime[i] == 0)
    {
      p1[i]++;
      a /= prime[i];
    }
    while(b % prime[i] == 0)
    {
      p2[i]++;
      b /= prime[i];
    }
  }
  for(int i=1 ; i<=p ; ++i)
  {
    int tmp = abs(p1[i] - p2[i]);
    if(tmp % 2 == 0) p1[i] = p2[i] = 0;
    else
    {
      if(p1[i] > p2[i]) p1[i] = 1, p2[i] = 0;
      if(p1[i] < p2[i]) p1[i] = 0, p2[i] = 1;
    }
  }
  if(!Prime(tmp1) && !Prime(tmp2))
  {
    tmp1 = 1, tmp2 = 1;
    for(int i=1 ; i<=p ; ++i)
    {
      if(p1[i] != 0) tmp1 *= prime[i];
      if(p2[i] != 0) tmp2 *= prime[i];
    }
  }
  else
  {
    if(Prime(tmp1))
    {
      tmp2 = 1;
      for(int i=1 ; i<=p ; ++i)
        if(p2[i] != 0) tmp2 *= prime[i];
    }
    if(Prime(tmp2))
    {
      tmp1 = 1;
      for(int i=1 ; i<=p ; ++i)
        if(p1[i] != 0) tmp1 *= prime[i];
    }
  }
  printf("%d %d\n",tmp1,tmp2);
}

int main()
{
  ios_base::sync_with_stdio(false);
  freopen(Task".inp","r",stdin);
  freopen(Task".out","w",stdout);
  scanf("%d",&T);
  makePrime();
  while(T--)
  {
    readData();
    convert(x,y);
  }
  return 0;
}
