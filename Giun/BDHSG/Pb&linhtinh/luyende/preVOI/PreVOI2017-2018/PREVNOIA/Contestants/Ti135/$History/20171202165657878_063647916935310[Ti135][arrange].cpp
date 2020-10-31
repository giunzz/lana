#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;
int n;
long long s[maxn],f[maxn],a[maxn],b[maxn];
long long xuli(int u,int v){
    long long ds=0;
    long long k=(s[v]-s[u-1])/(v-u+1);
    for(int i=u;i<=v;i++) b[i]=a[i];
    for(int i=v;i>=u;i--) ds+=abs(a[i]-k),a[i-1]+=(a[i]-k);
    for(int i=u;i<=v;i++) a[i]=b[i];
    return ds;
}
void sub1(){
    long long k=s[n]/n;
    for(int i=1;i<=n;i++) f[i]=1e18;
    for(int i=1;i<=n;i++)
        for(int j=i;j>=1;j--){
            long long u=s[i]-s[j-1],v=i-j+1;
            if(u%v==0&&u/v>=k&&u/v<=k+1) f[i]=min(f[i],f[j-1]+xuli(j,i));
        }
    printf("%I64d",f[n]);
}
int main(){
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]),s[i]=s[i-1]+a[i];
    if(s[n]%n==0) printf("%I64d",xuli(1,n));
    else sub1();
}
