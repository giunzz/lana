#include <bits/stdc++.h>

using namespace std;

void load() {
    #ifndef ONLINE_JUDGE
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    #endif // ONLINE_JUDGE
}

const int N = 4004;
int dp[N][N],a[N],b[N],n,k;

void sub_1() {
    int ans = 0;
    for (int i = n ; i > 0 ; -- i)
    for (int j = n ; j > 0 ; -- j) {
        if (a[i] == b[j]) {
            dp[i][j] = 1;
            for (int h = i + 1 ; h <= n ; ++ h)
            for (int c = j + 1 ; c <= n ; ++ c)
                if (a[h] == b[c] && abs(a[i]-a[h]) <= k)
                    dp[i][j] = max(dp[i][j], dp[h][c] + 1);
            ans = max(ans, dp[i][j]);
        }
    }
    int h = 0, c = 0;
    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= n ; ++ j)
        if (a[i] == b[j] && dp[i][j] == ans && a[i] > a[h])
            h = i, c = j;
    printf("%d\n",ans);
    printf("%d ",a[h]);
    --ans;
    while (ans > 0) {
        int l = 0, r = 0;
        for (int i = h + 1 ; i <= n ; ++ i)
        for (int j = c + 1 ; j <= n ; ++ j)
        if (dp[i][j] == ans && a[i] == b[j] && abs(a[i]-a[h]) <= k && a[i] > a[l])
            l = i, r = j;
        printf("%d ",a[l]);
        h = l, c = r;
        --ans;
    }
    return ;
}

void sub_2() {
    /*int flag = 0;
    set < int > ss[2][N];
    for (int i = 1 ; i <= n ; ++ i) {
        int old = flag;
        flag ^= 1;
        for (int j = 1 ; j <= n ; ++ j)
            ss[flag][j].clear();
        for (int )
    }*/
}
void trungtt() {

    scanf("%d%d",&n,&k);
    for (int i = 1 ; i <= n ; ++ i) scanf("%d",&a[i]);
    for (int j = 1 ; j <= n ; ++ j) scanf("%d",&b[j]);
    if (n <= 100) {
        sub_1();
        return ;
    }
    sub_2();
    return ;
}

int main() {
    load();
    trungtt();
    return 0;
}
