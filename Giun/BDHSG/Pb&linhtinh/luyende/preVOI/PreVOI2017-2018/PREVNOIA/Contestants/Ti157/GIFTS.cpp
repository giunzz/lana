#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define ii pair<int, int>
#define HANH "GIFTS"
using namespace std;
const int mod=1e18;
const int N=1e6+5;
int n, k, a[N], f[N], d[N], c[N];
long long kq=mod;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(HANH".inp", "r", stdin);
    freopen(HANH".out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        a[i]+=a[i-1];
        if(i<k) continue;
        f[i]=a[i]-a[i-k];
        d[i]=max(f[i], d[i-1]);
    }
    for(int i=n; i>=k; --i)
    {
        c[i]=max(c[i+1], f[i]);
        long long hanh=0;
        if(i+k<=n) hanh=max(hanh, 1ll*c[i+k]);
        if(i-k>=k) hanh=max(hanh, 1ll*d[i-k]);
        kq=min(kq, hanh);
    }
    printf("%lld", kq);
}
