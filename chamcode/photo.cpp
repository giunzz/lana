#include <stdio.h>
const int maxn = 1e6 + 7;
long long w[maxn], h[maxn], tw = 0, mh1 = 1, mh2 = -1, n, ans, ans1, c = 0;

int main(){
    freopen("photo.inp", "r", stdin);
    freopen("photo.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld", &w[i], &h[i]);
        tw += w[i];
        if (h[i] > mh1) mh1 = h[i], c = 1;
        else if (h[i] == mh1) c = 2;
    }
    if (c != 1) mh2 = mh1;
    else for (int i = 1; i <= n; i++){
        if (mh1 != h[i] && h[i] > mh2) mh2 = h[i];
    }
    for (int i = 1; i <= n; i++){
        ans1 = (tw - w[i])*(mh2), ans = (tw - w[i])*(mh1);
        if (h[i] != mh1) printf("%lld ", ans);
        else printf("%lld ", ans1);
    }
}   