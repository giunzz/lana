#include <bits/stdc++.h>
using namespace std;

ifstream fi("GIFTS.INP");
ofstream fo("GIFTS.OUT");

int64_t n,k,res=1e18,a[1000005],max1[1000005],max2[1000005];

int main()
{
    fi>>n>>k;
    for(int64_t i=1;i<=n;i++)
    {
        fi>>a[i];
        a[i]+=a[i-1];
    }
    for(int64_t i=k;i<=n;i++)
        max1[i]=max(max1[i-1],a[i]-a[i-k]);
    for(int64_t i=n-k+1;i>=1;i--)
        max2[i]=max(max2[i+1],a[i+k-1]-a[i-1]);
    for(int64_t i=k;i<=n;i++)
        res=min(res,max(max1[i-k],max2[i+1]));
    fo<<res;
}
