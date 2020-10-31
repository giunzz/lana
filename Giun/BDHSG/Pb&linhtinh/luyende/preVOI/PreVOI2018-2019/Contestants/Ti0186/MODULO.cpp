#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define pb push_back
typedef pair<int, int> ii;
const int N = 1e5 + 10;
const int oo = 1e9;

int A, B, n, k;
bool f[2][2000005];
ii mask[21][2000001];

int pw(int x, int y)    {
    int res = 1;
    while(y > 0)    {
        if(y % 2 == 1) res = res * x;
        x = x * x; y >>= 1;
    }
    return res;
}

void solve()    {
    int x = pw(2, n);
    int las = 0, nex = 1;
    f[las][A % x] = f[las][B % x] = 1;
    mask[1][A % x] = ii(A, 0); mask[1][B % x] = ii(B, 0);
    FOR(i, 1, n - 1) {
        for(int j = 0; j < x; ++j)  if(f[las][j]) {
            f[nex][(j * 10 + A) % x] = f[nex][ (j * 10 + B) % x ] = 1;
            mask[i + 1][(j * 10 + A) % x] = ii(A, j);
            mask[i + 1][(j * 10 + B) % x] = ii(B, j);
        }
        swap(las, nex);
        memset(f[nex], 0, sizeof f[nex]);
    }

    if(f[las][k] == false) printf("-1");
    else {
        string res = "";
        int pos = n, val = k;
        while(pos > 0)  {
            res += char(mask[pos][val].fi + '0');
            val = mask[pos][val].se;
            pos -= 1;
        }
        reverse(res.begin(), res.end());
        for(char c: res) printf("%c", c);
    }
}
signed main()
{
    freopen("MODULO.inp", "r", stdin);
    freopen("MODULO.out", "w", stdout);
    scanf("%d%d", &A, &B);
    scanf("%d%d", &n, &k);
    if(n <= 20) solve();
    else printf("-1");
}
/*
7 2
3 5
*/
