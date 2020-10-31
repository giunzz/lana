#include <bits/stdc++.h>
#define NMAX 1000000
#define LLMAX 1111111111111
using namespace std;

int n,k;
long long a[NMAX+7],b[NMAX+7],c[NMAX+7],f1[NMAX+7],f2[NMAX+7],f[NMAX+7];
long long res=LLMAX;
int main()
{
  freopen("GIFTS.inp","r",stdin);
  freopen("GIFTS.out","w",stdout);
  scanf("%d%d",&n,&k);
  for (int i=1; i<=n; ++i)
    scanf("%d",&a[i]);
  for (int i=1; i<=n; ++i)
  {
    b[i]=b[i-1]+a[i];
    f1[i]=0;
    f2[i]=0;
    if (i>=k) c[i]=b[i]-b[i-k];
  }
//  for (int i=k; i<=n; ++i)
//    printf("%d ",c[i]);
//  printf("\n");
  for (int i=2*k; i<=n; ++i)
  {
    f1[i]=max(f1[i-1],c[i-k]);
//    printf("i=%d f1=%d\n",i, f1[i]);
  }
  for (int i=n-k; i>=k; --i)
  {
    f2[i]=max(f2[i+1],c[i+k]);
//    printf("i=%d f2=%d\n",i, f2[i]);
  }
  for (int i=k; i<=n; ++i)
  {
    f[i]=max(f1[i],f2[i]);
    res=min(res,f[i]);
  }
  printf("%d\n",res);
}
