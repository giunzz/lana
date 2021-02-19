#include <stdio.h>
#include <ctime>
const int maxn = 1e6 + 7;
long long w[maxn], h[maxn], tw = 0, mh1 = 0, mh2 = 0, n, ans, ans1;

int main(){
    freopen("photo.inp","r",stdin);
    //freopen("photo\\test1\\photo.inp", "r", stdin);
    freopen("photo.out", "w", stdout);
    scanf("%ld", &n);
    for (int i = 1; i <= n; i++){
        scanf("%ld%ld", &w[i], &h[i]);
        tw += w[i];
        if (h[i] > mh1)mh2 = mh1, mh1 = h[i];
        else if (h[i] > mh2) mh2 = h[i];
    }
    for (int i = 1; i <= n; i++){
        ans1 = (tw - w[i])*(mh2), ans = (tw - w[i])*(mh1);
        if (h[i] != mh1) printf("%lld ", ans);
        else printf("%lld ", ans1);
    }
  //  fprintf(stderr, "%d ms\n", clock());
  //  fprintf(stdout, "%d", clock());
}