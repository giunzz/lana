#include <bits/stdc++.h>
#define FILE "GIFTS"
const int N = 1e6+7;
const long long oo = 1e12+7;
using namespace std;
int n,k;
long long s[N],MAX1[N],MAXN[N],a[N],ans=oo;

long long get(int i,int j)
{
    return (s[j]-s[i-1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n >> k;
    for (int i=1;i<=n;++i)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    for (int i=1;i<=n-k+1;++i) a[i] = get(i,i+k-1);
    n = n-k+1;
    MAX1[0] = MAXN[n+1] = -oo;
    for (int i=1;i<=n;++i) MAX1[i] = max(MAX1[i-1],a[i]);
    for (int i=n;i>=1;--i) MAXN[i] = max(MAXN[i+1],a[i]);
    MAX1[0] = MAXN[n+1] = oo;
    for (int i=1;i<=n;++i)
    {
        long long tmp1=-oo,tmp2=-oo;
        if (i-k>=0) tmp1 = MAX1[i-k];
        if (i+k<=n) tmp2 = MAXN[i+k];
        ans = min(ans,max(tmp1,tmp2));
    }
    cout << ans;
    return 0;
}
