#include <bits/stdc++.h>
using namespace std;
struct str
{
  int x,y,z,id,val;
};
bool compare(str a, str b)
{
  return a.x<b.x;
}
str a[100007];
int m,n,k;
int negtong[100007],postong[100007],res=0,tam,pos,neg;
int main()
{
  freopen("TEAWORLD.inp","r",stdin);
  freopen("TEAWORLD.out","w",stdout);
  scanf("%d%d%d",&m,&n,&k);
  for (int i=1; i<=m; ++i)
  {
    int x;
    scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].z,&x);
    a[i].id=3;
  }
  for (int i=1; i<=n; ++i)
  {
    scanf("%d%d%d%d",&a[i+m].x,&a[i+m].y,&a[i+m].z,&a[i+m].val);
    a[i].id=2;
  }
  a[m+n+1].id=1;
  scanf("%d%d%d",&a[m+n+1].x,&a[m+n+1].y,&a[m+n+1].z);
  sort(a+1,a+m+n+1+1,compare);
  for (int i=1; i<=m+n+1; ++i)
    if (a[i].id==1) tam=i;
//  printf("tam=%d\n",tam);
  for (int i=tam+1; i<=m+n+1; ++i)
  {
    if (a[i].id==3) pos++;
    postong[i]=postong[i-1]+a[i].val;
  }
  for (int i=tam-1; i>=1; --i)
  {
    if (a[i].id==3) neg++;
    negtong[i]=negtong[i+1]+a[i].val;
  }
  for (int i=0; i<=pos; ++i)
  {
    int u=i;
    int v=k-i;
    int j=0;
    int res1=0, res2=0;
    int position=tam;
    while (j<min(u,k))
    {
      position++;
      res1=postong[position];
      if (a[position].id==3) j++;
    }
    if (j<k)
    {
      v=k-j;
      j=0;
      position=tam;
      while (j<v)
      {
        position--;
        res2=negtong[position];
        if (a[position].id==3) j++;
      }
    }
    res=max(res,res1+res2);
  }
  printf("%d\n",res);
}
