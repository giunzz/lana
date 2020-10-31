#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define f first
#define s second
const int N = 4e3 + 5;

int n, x, a[N], b[N], f[N][N], ans;
ii trace[N][N];

int main() {
    #define file "LIONDANCE"
    freopen(file".INP", "r", stdin);  freopen(file".OUT", "w", stdout);
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> x;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int j = 1; j <= n; ++j) cin >> b[j];
    for(int i = n; i >= 1; --i) {
        for(int j = n; j >= 1; --j) {
            if (a[i] != b[j]) continue;
            if (a[i] == b[j]) f[i][j] = 1, trace[i][j] = ii(i, j);
            for(int k = i + 1; k <= n; ++k)
            for(int h = j + 1; h <= n; ++h) {
                if (a[i] == b[j] && a[k] == b[h] && abs(a[i] - a[k]) <= x) {
                    if (f[i][j] < f[h][k] + 1) {
                        f[i][j] = f[h][k] + 1;
                        trace[i][j] = ii(h, k);
                    }
                    else {
                        if (f[i][j] == f[h][k] + 1) {
                            trace[i][j] = max(trace[i][j], ii(h, k));
                        }
                    }
                }
            }
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << "\n";
    for(int i = n; i >= 1; --i){
        for(int j = n; j >= 1; --j) if (f[i][j] == ans) {
            int x = i, y = j;
            while (f[x][y] != 1) {
                cout << a[x] << " ";
                ii tmp = trace[x][y];
                x = tmp.f;
                y = tmp.s;
            }
            cout << a[x] ;
            return 0;
        }
    }
    return 0;
}
