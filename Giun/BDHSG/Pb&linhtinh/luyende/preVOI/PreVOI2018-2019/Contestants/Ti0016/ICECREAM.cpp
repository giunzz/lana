#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 9;

int n, m, x ,y ,z, f[51][4][50][50][50], res;
int main() {
    #define file "ICECREAM"
    freopen(file".INP", "r", stdin);  freopen(file".OUT", "w", stdout);
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    cin >> x >> y >> z;
    for(int i = 1; i <= 1; ++i) f[0][i][x][y][z] = 1;

    for(int i = 1; i <= n; ++i)
        for(int h = 0; h <= m; ++h)
            for(int k = 0; k <= m; ++k)
                for(int l = 0; l <= m; ++l) {
                    if (h - 1 >= 0) {
                        f[i][1][h][k][l] = (f[i][1][h][k][l] + f[i - 1][1][h - 1][k][l]) % mod;
                        f[i][1][h][k][l] = (f[i][1][h][k][l] + f[i - 1][2][h - 1][k][l]) % mod;
                        f[i][1][h][k][l] = (f[i][1][h][k][l] + f[i - 1][3][h - 1][k][l]) % mod;
                    }
                    if (h + 1 <= m && k - 1 >= 0) {
                        f[i][2][h][k][l] = (f[i][2][h][k][l] + f[i - 1][1][h + 1][k - 1][l]) % mod;
                        f[i][2][h][k][l] = (f[i][2][h][k][l] + f[i - 1][2][h + 1][k - 1][l]) % mod;
                        f[i][2][h][k][l] = (f[i][2][h][k][l] + f[i - 1][3][h + 1][k - 1][l]) % mod;
                    }
                    if (h + 3 <= m && l - 1 >= 0) {
                        f[i][3][h][k][l] = (f[i][3][h][k][l] + f[i - 1][1][h + 3][k][l - 1]) % mod;
                        f[i][3][h][k][l] = (f[i][3][h][k][l] + f[i - 1][2][h + 3][k][l - 1]) % mod;
                        f[i][3][h][k][l] = (f[i][3][h][k][l] + f[i - 1][3][h + 3][k][l - 1]) % mod;
                    }
                    if (h + 1 <= m && k + 1 <= m && l - 1 >= 0) {
                        f[i][3][h][k][l] = (f[i][3][h][k][l] + f[i - 1][1][h + 1][k + 1][l - 1]) % mod;
                        f[i][3][h][k][l] = (f[i][3][h][k][l] + f[i - 1][2][h + 1][k + 1][l - 1]) % mod;
                        f[i][3][h][k][l] = (f[i][3][h][k][l] + f[i - 1][3][h + 1][k + 1][l - 1]) % mod;
                    }
                }
    for(int h = 0; h <= m; ++h)
        for(int k = 0; k <= m; ++k)
            for(int l = 0; l <= m; ++l) {
                res = (res + f[n][1][h][k][l]) % mod;
                res = (res + f[n][2][h][k][l]) % mod;
                res = (res + f[n][3][h][k][l]) % mod;
            }
    cout << res;
    return 0;
}
