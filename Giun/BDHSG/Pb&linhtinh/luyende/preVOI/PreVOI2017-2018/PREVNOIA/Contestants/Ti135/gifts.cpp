#include <bits/stdc++.h>
#define maxn 3000001
using namespace std;
int n,k,a[maxn];
long long s[maxn],sdau[maxn],scuoi[maxn];
void xuli(){
    long long ds=1e18;
    for(int i=1;i<=n-k+1;i++){
        long long x=s[i+k-1]-s[i-1];
        long long y=max(sdau[i-1],scuoi[i+k]);
        if(x>=y) ds=min(ds,x);
    }
    printf("%I64d",ds);
}
int main(){
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=k;i<=n;i++) sdau[i]=max(sdau[i-1],s[i]-s[i-k]);
    for(int i=n-k+1;i>=1;i--) scuoi[i]=max(scuoi[i+1],s[i+k-1]-s[i-1]);
    xuli();
}
