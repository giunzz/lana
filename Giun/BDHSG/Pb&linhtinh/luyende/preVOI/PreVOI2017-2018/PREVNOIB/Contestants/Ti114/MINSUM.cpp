#include <bits/stdc++.h>
using namespace std;


map <int,int> exist;
int k=0,t=0, prime[100007], prime1[100007], f[100007], a, b;
void geta(int u)
{
  for (int i=2; i*i<=u; ++i)
  if (u%i==0)
  {

    if (exist[i]==0)
    {
      k++;
      prime[k]=i;
    }
    while (u%i==0)
    {
      u=u/i;
      exist[i]++;
    }
  }
  if (u!=1)
  {
    if (exist[u]==0)
    {
      k++;
      prime[k]=u;
      exist[u]++;
    }
  }
}
void getb(int u)
{
    for (int i=2; i*i<=u; ++i)
  if (u%i==0)
  {
    if (exist[i]==0)
    {
      k++;
      prime[k]=i;
    }
    while (u%i==0)
    {
      u=u/i;
      exist[i]++;
    }
  }
  if (u!=1)
  {
    if (exist[u]==0)
    {
      k++;
      prime[k]=u;
    }
    exist[u]++;
  }
}
int findd(int i,int half)
{
  int l=1;
  int r=i-1;
  int x=prime1[i];
  while (l<r-1)
  {
    int m=(l+r)/2;
    if (f[m]*x<=half) l=m;
    else r=m;
  }
  if (f[r]*x<=half) return r;
  if (f[l]*x<=half) return l;
  return 0;
}
void process(int a, int b)
{
  geta(a);
  getb(b);
  int k1=0;
//  printf("k=%d\n",k);
  bool ch=false;
  int x=0;
  if (((a==1) || (b==1)) && (k==1))
  {
    ch=true;
    x=prime[1];
  }
  for (int i=1; i<=k; ++i)
  {
//    printf("%d %d\n",prime[i],exist[prime[i]]);
    exist[prime[i]]=exist[prime[i]]%2;
    if (exist[prime[i]]==1)
    {
      k1++;
      prime1[k1]=prime[i];
    }
    exist[prime[i]]=0;
    prime[i]=0;
  }
  k=0;
  if (ch)
  {
    printf("1 %d\n",x);
    return;
  }
  if (k1==0)
  {
    printf("1 1\n");
    return;
  }
  if (k1==1)
  {
    printf("%d 1\n",prime1[k1]);
    return;
  }
  if (k1==2)
  {
    printf("%d %d\n",prime1[1], prime1[2]);
    return;
  }
  int mult=1,res=0;
  for (int i=1; i<=k1; ++i)
    mult=mult*prime1[i];
  int half=int(sqrt(mult));
  for (int i=1; i<=k1; ++i)
    f[i]=1;
  f[1]=prime1[1];
  f[0]=1;
//  printf("half=%d\n",half);
  for (int i=2; i<=k1; ++i)
  {
    f[i]=f[findd(i,half)]*prime1[i];
//    printf("%d\n",findd(i,half));
  }
  for (int i=1; i<=k1; ++i)
  {
//    printf("%d ", f[i]);
    res=max(res,f[i]);
  }
//  printf("\n%d\n",res);
  printf("%d %d\n",res,(mult/res));
}
int main()
{
  freopen("MINSUM.inp","r",stdin);
  freopen("MINSUM.out","w",stdout);
  scanf("%d",&t);
  for (int i=1; i<=t; ++i)
  {
    scanf("%d%d",&a,&b);
    process(a,b);
  }
}
