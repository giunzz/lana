#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int maxn = 1000010;

int n, k;
LL a[maxn], sum[maxn], l[maxn], r[maxn];

int main(){
    freopen("gifts.inp", "r", stdin);
    freopen("gifts.out", "w", stdout);

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    for (int i = k; i <= n; i++) l[i] = max(l[i - 1], sum[i] - sum[i - k]);
    for (int i = n - k; i >= 0; i--) r[i] = max(r[i + 1], sum[i + k] - sum[i]);

    LL ans = 1e18;
    for (int i = 0; i <= n - k; i++) ans = min(ans, max(l[i], r[i + k]));

    printf("%lld", ans);

    return 0;
}
