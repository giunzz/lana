#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e5 + 100;
int n;
LL a[N],sum;

void load() {
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
}

void process() {

    scanf("%d",&n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%lld",&a[i]);
        sum = sum + a[i];
    }

    if (sum % n == 0) {
            LL ans = 0;
            for (int i = 1 ; i <= n ; ++ i) {
            ans += abs(sum / n - a[i]);
            a[i+1] = a[i+1] + (a[i] - sum/n);}

        printf("%lld",ans);
        return ;
    }

    LL tmp = sum / n;
    LL k = tmp * n + n - sum;
    LL ans = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] < tmp) {
            if (a[i-1] > tmp) {++ans; ++a[i];}
            ans += (tmp - a[i]);
            a[i +1] = a[i + 1] + a[i] - tmp;
        } else
        if (a[i] - tmp > 1) {
            ans += (a[i] - tmp - 1);
            a[i +1] = a[i+1] + a[i] - tmp - 1;
        }
    }

    printf("%lld",ans);
}

int main() {
    load();
    process();
    return 0;
}
