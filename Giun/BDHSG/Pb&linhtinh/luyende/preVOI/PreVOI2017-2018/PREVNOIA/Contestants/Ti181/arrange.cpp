#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int maxn = 100100;
const LL oo = 1e18;

int n;
int l[maxn];
LL a[maxn], sum[maxn];
LL f[2010][2010];
LL ans;

int findleft(int x, LL val){
    if (a[x] < val) return x;
    l[x] = findleft(l[x], val);
    return l[x];
}

void solve1(LL val){
    for (int i = 1; i <= n; i++) l[i] = i - 1;
    for (int i = 1; i <= n; i++)
    if (a[i] > val){
        LL cnt = a[i] - val;
        int lx = findleft(i, val);
        while (lx != 0 && cnt != 0){
            LL tmp = min(val - a[lx], cnt);
            a[lx] += tmp;
            cnt -= tmp;
            ans += tmp * (i - lx);
            lx = findleft(lx, val);
        }
        a[i] = val;
        a[i + 1] += cnt;
        ans += cnt;
    }
}

void solve2(LL val){
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= sum[n] % n; j++)
            f[i][j] = oo;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= sum[n] % n; j++)
            f[i][j] = min(f[i][j], abs(sum[i] - val * i - j) + ((j > 0) ? min(f[i - 1][j], f[i - 1][j - 1]) : f[i - 1][j]));
    ans = f[n][sum[n] % n];
}

void solve3(LL val){

}

int main(){
    freopen("arrange.inp", "r", stdin);
    freopen("arrange.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    if (sum[n] % n == 0) solve1(sum[n] / n); else
    if (n <= 2000) solve2(sum[n] / n); else
    solve3(sum[n] / n);

    printf("%lld", ans);

    return 0;
}
