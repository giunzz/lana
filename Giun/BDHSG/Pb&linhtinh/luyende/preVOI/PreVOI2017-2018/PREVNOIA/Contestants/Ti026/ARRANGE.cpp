#include <bits/stdc++.h>
const int maxn=1e5+5;
using namespace std;
int n,a[maxn];
int s=0,d=0;
void khoitao()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("ARRANGE.INP","r",stdin);
    freopen("ARRANGE.OUT","w",stdout);
    khoitao();
    if(s%n==0)
    {
        int h=s/n;
        for(int i=1;i<=n;++i)
            if(a[i]!=h) d+=abs(h-a[i]);
        cout<<d;
    }
}
