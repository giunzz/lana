#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+3,oo=1e15+3;
int n,k,a[N],s[N],max1[N],max2[N],res=oo;
int prepare()
{
    for(int i=1;i<=n;i++)
        if(i>=k)
            max1[i]=max(max1[i-1],s[i]-s[i-k]);
    for(int i=n;i>=1;i--)
        if(n-i+1>=k)
            max2[i]=max(max2[i+1],s[i+k-1]-s[i-1]);
}
int process()
{
    for(int i=1;i<=n-k+1;i++)
        res=min(res,max(max1[i-1],max2[i+k]));
    cout<<res;
}
main()
{
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    prepare();
    process();
}
