#include <bits/stdc++.h>

using namespace std;

const int maxN=1e6+11;

int n, k, l;
long long a[maxN], sum, maxx;

int main()
{
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1; i<=n; i++) cin>>a[i];
    int be=0;
    for (int en=1; en<=n; en++)
    {
        sum+=a[en];
        if (en>=k)
        {
            sum-=a[be];
            be++;
            if (sum>maxx)
            {
                maxx=sum;
                l=be;
            }
        }
    }
    n-=k;
    for (int i=l; i<=n; i++) a[i]=a[i+k];
    be=0; sum=0; maxx=0;
    for (int en=1; en<=n; en++)
    {
        sum+=a[en];
        if (en>=k)
        {
            sum-=a[be];
            be++;
            maxx=max(maxx, sum);
        }
    }
    cout<<maxx;
    return 0;
}
