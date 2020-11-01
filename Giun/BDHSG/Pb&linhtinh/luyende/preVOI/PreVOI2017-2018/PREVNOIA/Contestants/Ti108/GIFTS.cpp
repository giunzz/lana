#include <bits/stdc++.h>
#define maxn 1000000
using namespace std;
int n,k;
long long sum1=-1e9, sum2=-1e9;
int a[maxn];
long long s[maxn];
int main()
{
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    cin>>n>>k;
    s[0]=0LL;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i]*1LL;
    }
    for(int i=k;i<=n;i++){
        if(s[i]-s[i-k]> sum1){
            sum2=sum1;
            sum1=s[i]-s[i-k];
        }
        else if(s[i]-s[i-k]>sum2){
            sum2=s[i]-s[i-k];
        }
    }
    cout<<sum2;
    return 0;
}
