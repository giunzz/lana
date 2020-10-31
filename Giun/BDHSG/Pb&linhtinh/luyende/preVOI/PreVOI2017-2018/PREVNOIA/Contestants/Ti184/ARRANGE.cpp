#include<bits/stdc++.h>
const long long N = 1e5 + 5;
const long long inf = 1e18;
using namespace std;

ifstream fi ("ARRANGE.inp");
ofstream fo ("ARRANGE.out");

typedef vector <long long> vi;
vector <vi> dp;

long long n, a[N], cnt[2], val, cur = 1;
long long sum, x, y;

int main (){
    fi >> n;
    for (long long i = 1; i <= n; i++) {fi >> a[i]; sum += a[i];}
    cnt[1] = sum % n; cnt[0] = n - cnt[1]; val = sum / n;
    if (cnt[1] > cnt[0]) swap(cnt[0], cnt[1]), cur = -1, val++;
    dp.assign(n+1, vi(cnt[1]+1, inf)); dp[0][0] = 0;
    for (long long i = 1; i <= n; i++) {
        x += a[i]; y += val;
        for (long long j = 0; j <= cnt[1]; j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j] + abs(x-y-j*cur));
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(x-y-j*cur));
        }
    }
    fo << dp[n][cnt[1]];
}
