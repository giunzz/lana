#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)

using namespace std;
const int mxn=1000005;

int n,k,a[mxn];
long long sum[mxn],res,F1i[mxn],Fin[mxn];

void sol2()
{
   F1i[k]=sum[k];
   For(i,k+1,n)
      F1i[i]=max(F1i[i-1],sum[i]-sum[i-k]);
   Fin[n-k+1]=sum[n]-sum[n-k];
   for(int i=n-k;i>=1;--i)
      Fin[i]=max(Fin[i+1],sum[i+k-1]-sum[i-1]);
   res=1e15;
   For(i,1,n-k+1)res=min(res,max(F1i[i-1],Fin[i+k]));
   printf("%lld",res);
}

void doc()
{
   freopen("gifts.inp","r",stdin);
   freopen("gifts.out","w",stdout);
   scanf("%d%d",&n,&k);
   For(i,1,n)scanf("%d",&a[i]);
   For(i,1,n)sum[i]=sum[i-1]+a[i];

}

int main()
{
   doc();
   sol2();
   return 0;

}

