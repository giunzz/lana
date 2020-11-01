#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define pb push_back

const int N = 305;
const int mod = 1e9 + 7;

int n, maxn, m1, m2, m3, las = 0, nex = 1;
int f[2][N][N][N], a[4];

void prepare()  {
    m1 = m2 = m3 = maxn;
    if(a[1] >= 150) m1 -=  (a[1] - 150), a[1] = 150;
    if(a[2] >= 150) m2 -= (a[2] - 150), a[2] = 150;
    if(a[3] >= 150) m3 -= (a[3] - 150), a[3] = 150;
    m1 = min(m1, a[1] + 150);
    m2 = min(m2, a[2] + 150);
    m3 = min(m3, a[3] + 150);
}
void upd(int &x, int y) {
    x = (x % mod + y % mod) % mod;
}
signed main()
{
    freopen("ICECREAM.inp", "r", stdin);
    freopen("ICECREAM.out", "w", stdout);
    scanf("%d%d", &n, &maxn);
    FOR(i, 1, 3) scanf("%d", &a[i]);
    if(n <= 150 * 1ll)    {
        prepare();
        f[las][ a[1] ][ a[2] ][ a[3] ] = 1;
        for(int i = 0; i < n; ++i) {
            FOR(val1, 0, m1) FOR(val2, 0, m2) FOR(val3, 0, m3){
                // take ong thing
                if(val1 < m1) upd(f[nex][val1 + 1][val2][val3], f[las][val1][val2][val3]);
                // give two
                if(val1 > 0 && val2 < m2) upd(f[nex][val1 - 1][val2 + 1][val3], f[las][val1][val2][val3]);
                // give three
                if(val1 && val2 && val3 < m3) upd(f[nex][val1 - 1][val2 - 1][val3 + 1], f[las][val1][val2][val3]);
                else if(val1 > 2) upd(f[nex][val1 - 3][val2][val3], f[las][val1][val2][val3]);
            }
            swap(las, nex); memset(f[nex], 0, sizeof f[nex]);
        }
        int ans = 0;
        FOR(i, 0, N - 1) FOR(j, 0, N - 1) FOR(t, 0, N - 1) upd(ans, f[las][i][j][t]);
        printf("%d", ans);
    } else printf("0");
    return 0;
}
/*
2 2
2 0 0
*/
