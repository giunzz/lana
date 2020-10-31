#include <bits/stdc++.h>
#define LL long long
using namespace std;

void load() {
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
}
const LL Base = 1e9 + 7;
LL dp[3][10010][610];

LL Add(LL &a, LL b) {
    a += b;
    a %= Base;
    if (a < 0) a += Base;
}

LL res;
void trau(int i, int a, int b, int c, int mx) {
    if (i == 0) {
        ++res;
        return ;
    }
    if (a < mx)
        trau(i-1,a+1,b,c,mx);
    if (a && b < mx)
        trau(i-1,a-1,b+1,c,mx);
    if (c < mx) {
        if (b && a)
            trau(i-1,a-1,b-1,c+1,mx);
        else
            if (a > 2) trau(i-1,a-3,b,c+1,mx);
    }
}
void trungtt() {
    int n, MX;
    scanf("%d%d",&n,&MX);
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    /*res = 0;
    trau(n,a,b,c,MX);
    cout << res << endl;*/
    int tmp = max(0,b-n);
    int tmp_a = 0;
    if (a > n * 3 + 10) tmp_a = a - n*3-10, a = n * 3+ 10;
    if (b > n) b = n;
    int flag = 0;
    dp[0][a][b] = 1;
    int mx = MX;
    if (a + n + 10 < mx) mx = a + n + 10;
    int Sum = a + b*2 + c*4;
    for (int i = 0 ; i < n ; ++ i) {
        int old = flag;
        flag ^= 1;
        for (int j = 0 ; j <= mx ; ++ j)
        for (int k = 0 ; k <= 2*n ; ++ k)
            dp[flag][j][k] = 0;
        for (int j = 0 ; j <= mx ; ++ j)
        for (int k = 0 ; k <= 2*n ; ++ k) {
            if (dp[old][j][k] == 0) continue;

            if (j + 1 + tmp_a <= MX) Add(dp[flag][j+1][k],dp[old][j][k]);
            if (j && k + 1 + tmp <= MX)
                Add(dp[flag][j-1][k+1], dp[old][j][k]);
            int cur = i + Sum - j - k * 2;
            if (cur % 4) continue;
            cur /= 4;
            if (cur < c) continue;

            if (cur + 1 <= MX) {
                 if (j && k) {
                    Add(dp[flag][j-1][k-1], dp[old][j][k]);
                    continue;
                 }
                if (j > 2) {
                    Add(dp[flag][j-3][k], dp[old][j][k]);
                    continue;
                }

            }
        }
    }
    LL ans= 0;
    for (int i = 0 ; i <= mx ; ++ i)
    for (int j = 0 ; j <= 2*n ; ++ j)
    Add(ans, dp[flag][i][j]);
    printf("%lld",ans);

}

int main() {
    load();
    trungtt();
    return 0;
}
