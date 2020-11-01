#include<bits/stdc++.h>
#define maxn 100001

using namespace std;

int n,a[maxn],ds;
long long t;

int main(){
    freopen("ARRANGE.inp","r",stdin);
    freopen("ARRANGE.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<=n;++i) t+=a[i];
    for(int i=1;i<=n;++i){
        a[i+1]+=a[i]-t/n;
        ds+=abs(a[i]-t/n);
    }
    printf("%d",ds);
}
