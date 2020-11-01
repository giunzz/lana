#include <bits/stdc++.h>
const int maxn=1e6+5;
using namespace std;
int n,k;
long long a[maxn];
int d=0;
long long s[maxn],b[maxn];
void khoitao()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    khoitao();
    for(int i=k;i<=n;++i)
        b[++d]=s[i]-s[i-k];
    int mn=INT_MAX;
    for(int i=1;i<=d;++i)
    {
        bool kt=1;
        for(int j=i-k;j>=1;--j)
            if(b[j]>b[i]) {kt=0; break;}
        if(!kt) break;
        for(int j=i+k;j<=d;++j)
            if(b[j]>b[i]) {kt=0; break;}
        if(kt && mn>b[i]) mn=b[i];
    }
    cout<<mn;
}

