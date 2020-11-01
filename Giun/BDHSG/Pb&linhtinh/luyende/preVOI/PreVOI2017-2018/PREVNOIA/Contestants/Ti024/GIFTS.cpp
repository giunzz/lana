#include<bits/stdc++.h>
#define oo1 2000000000
#define oo 2000000000000000ll
#define maxn 1000005
using namespace std ;
int n,k,a[maxn];
long long s[maxn];
long long dd[maxn];
long long t[maxn];
long long p[maxn];
void sub1(){
   long long tong=oo;
   for(int i=1;i<=n-k+1;i++){
       long long max1=0;
       if(i>=k+1){
          for(int j=1;j<=i-k;j++)max1=max(max1,s[j+k-1]-s[j-1]);
       }
       if(i+k-1<=n-k){
          for(int j=i+k;j<=n-k+1;j++)max1=max(max1,s[j+k-1]-s[j-1]);
       }
       tong=min(tong,max1);
   }
   printf("%I64d",tong);
}
void sub2(){
   t[0]=0;
   p[n-k+2]=0;
   for(int i=1;i<=n-k+1;i++)dd[i]=s[i+k-1]-s[i-1];
   for(int i=1;i<=n-k+1;i++)t[i]=max(t[i-1],dd[i]);
   for(int i=n-k+1;i>=1;i--)p[i]=max(p[i+1],dd[i]);
   long long tong=oo;
   for(int i=1;i<=n-k+1;i++){
       long long max1=0;
       if(i>=k+1)max1=max(max1,t[i-k]);
       if(i+k-1<=n-k)max1=max(max1,p[i+k]);
       tong=min(tong,max1);
   }
   printf("%I64d",tong);
}

int main(){
   freopen("GIFTS.inp","r",stdin);
   freopen("GIFTS.out","w",stdout);
   scanf("%d %d",&n,&k);
   for(int i=1;i<=n;i++)scanf("%d",&a[i]);
   for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
   if(n<=5000)sub1();
   else sub2();
}
