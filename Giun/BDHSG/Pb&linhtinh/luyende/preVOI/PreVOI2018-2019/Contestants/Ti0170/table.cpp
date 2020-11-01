#include <bits/stdc++.h>
#define LL long long
#define mp make_pair
#define F first
#define S second

using namespace std;

const int N = 303;
const LL Base = 1e9 + 13;
const LL inf = 1e18;
typedef pair < int , int > II;
II mem[N*N];
LL dp[N][N], way[N][N], f[N][N],Num[N][N],a[N][N];
int n,m,k;

void load() {
    #ifndef ONLINE_JUDGE
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    #endif // ONLINE_JUDGE
}

bool cmp(II x, II y) {
    return (a[x.F][x.S] > a[y.F][y.S]);
}

void solve(int x, int y, int s, int t) {
    if (x > s || y > t) {
        printf("0\n");
        return ;
    }

    for (int i = 0 ; i <= n ; ++ i)
    for (int j = 0 ; j <= m ; ++ j)
        dp[i][j] = -inf,way[i][j] = 0;

    dp[x][y] = a[x][y],way[x][y] = 1;
    for (int i = x ; i <= s ; ++ i)
    for (int j = y ; j <= t ; ++ j) {
        if (dp[i][j] < dp[i-1][j] + a[i][j]) dp[i][j] = dp[i-1][j] + a[i][j],way[i][j] = way[i-1][j];
        if (dp[i][j] < dp[i][j-1] + a[i][j]) dp[i][j] = dp[i][j-1] + a[i][j], way[i][j] = way[i][j-1];
        else if (dp[i][j] == dp[i][j-1] + a[i][j]) way[i][j] = (way[i][j] + way[i][j-1]) % Base;
    }

    for (int i = 0 ; i <= n + 1; ++ i)
    for (int j = 0 ; j <= m + 1; ++ j)
        f[i][j] = -inf,Num[i][j] = 0;
    f[s][t] = a[s][t], Num[s][t] = 1;
    for (int i = s ; i >= x ; -- i)
    for (int j = t ; j >= y ; -- j) {
        if (f[i][j] < f[i+1][j] + a[i][j]) f[i][j] = f[i+1][j] + a[i][j], Num[i][j] = Num[i+1][j];
        if (f[i][j] < f[i][j+1] + a[i][j]) f[i][j] = f[i][j+1] + a[i][j], Num[i][j] = Num[i][j+1];
        else if (f[i][j] == f[i][j+1] + a[i][j]) Num[i][j] = (Num[i][j] + Num[i][j+1]) % Base;
    }

    int h = 0, c = 0, cnt = 0;
    for (int i = x ; i <= s ; ++ i)
    for (int j = y ; j <= t ; ++ j) {
        if (i == x && j == y) continue;
        if (i == s && j == t) continue;
        if (dp[i][j] + f[i][j] - a[i][j] == dp[s][t] && ((way[i][j] * Num[i][j]) % Base) == way[s][t])
            mem[++cnt] = mp(i,j);
    }
    LL ans = dp[s][t];


    if (1LL*m * n * k  * cnt <= 100000000LL) {
    for (int p = 1 ; p <= cnt ; ++ p) {
        int h = mem[p].F , c = mem[p].S;
        LL tmp = a[h][c];
        a[h][c] = -inf;
        for (int i = 0 ; i <= n ; ++ i)
        for (int j = 0 ; j <= m ; ++ j)
            dp[i][j] = -inf;
        dp[x][y] = a[x][y];
        for (int i = x ; i <= s ; ++ i)
        for (int j = y ; j <= t ; ++ j) {

            if (dp[i][j] < dp[i-1][j] + a[i][j]) dp[i][j] = dp[i-1][j] + a[i][j];
            if (dp[i][j] < dp[i][j-1] + a[i][j]) dp[i][j] = dp[i][j-1] + a[i][j];
        }
        a[h][c] = tmp;
        ans = min(ans, dp[s][t]);
        }
    } else {
        sort(mem+1,mem+1+cnt,cmp);
        for (int p = 1 ; p <= min(10,cnt) ; ++ p) {
        int h = mem[p].F , c = mem[p].S;
        LL tmp = a[h][c];
        a[h][c] = -inf;
        for (int i = 0 ; i <= n ; ++ i)
        for (int j = 0 ; j <= m ; ++ j)
            dp[i][j] = -inf;
        dp[x][y] = a[x][y];
        for (int i = x ; i <= s ; ++ i)
        for (int j = y ; j <= t ; ++ j) {

            if (dp[i][j] < dp[i-1][j] + a[i][j]) dp[i][j] = dp[i-1][j] + a[i][j];
            if (dp[i][j] < dp[i][j-1] + a[i][j]) dp[i][j] = dp[i][j-1] + a[i][j];
        }
        a[h][c] = tmp;
        ans = min(ans, dp[s][t]);
        }
        for (int p = cnt ; p >= max(1,cnt-10) ; -- p) {
        int h = mem[p].F , c = mem[p].S;
        LL tmp = a[h][c];
        a[h][c] = -inf;
        for (int i = 0 ; i <= n ; ++ i)
        for (int j = 0 ; j <= m ; ++ j)
            dp[i][j] = -inf;
        dp[x][y] = a[x][y];
        for (int i = x ; i <= s ; ++ i)
        for (int j = y ; j <= t ; ++ j) {

            if (dp[i][j] < dp[i-1][j] + a[i][j]) dp[i][j] = dp[i-1][j] + a[i][j];
            if (dp[i][j] < dp[i][j-1] + a[i][j]) dp[i][j] = dp[i][j-1] + a[i][j];
        }
        a[h][c] = tmp;
        ans = min(ans, dp[s][t]);
        }
    }
    printf("%lld\n",ans);
    return;
}
void trungtt() {
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j)
            scanf("%lld",&a[i][j]);
    for (int i = 1 ; i <= k ; ++ i) {
        int x,y,s,t;
        scanf("%d%d%d%d",&x,&y,&s,&t);
        solve(x,y,s,t);
    }
}
int main() {
    load();
    trungtt();
    return 0;
}
