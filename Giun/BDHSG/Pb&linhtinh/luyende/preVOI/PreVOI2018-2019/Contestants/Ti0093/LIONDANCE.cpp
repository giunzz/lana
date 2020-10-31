#define taskname "LIONDANCE"
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 4009;

int n, delta, a[maxn], b[maxn], f[maxn][maxn];
int m, res[maxn], table[maxn], parent[maxn];
int result = 0, index = -1;
int lcis[maxn], arr1[maxn], arr2[maxn];

void Eratos(int arr1[], int n, int arr2[], int m) {
    for (int j = 0; j < m; ++j) table[j] = 0;
    for (int i = 0; i < n; ++i) {
        int current = 0, last = -1;
        for (int j = 0; j < m; ++j) {
            if (arr1[i] == arr2[j]) {
                if (current + 1 > table[j]) {
                    table[j] = current + 1;
                    parent[j] = last;
                }
            }
            if (arr1[i] > arr2[j]) {
                if (table[j] > current) {
                    current = table[j];
                    last = j;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (table[i] > result) {
           result = table[i];
           index = i;
        }
    }
    for (int i = 0; index != -1; ++i) {
        lcis[i] = arr2[index];
        index = parent[index];
    }
}

void LCS()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            res[++m] = a[i];
            --i;
            --j;
        }
        else if (f[i-1][j] > f[i][j-1]) --i;
        else --j;
    }
    cout << f[n][n] << '\n';
    for (int i = m; i >= 1; --i) cout << res[i] << ' ';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    cin >> n >> delta;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        arr1[i-1] = a[i];
        arr2[i-1] = b[i];
    }
    Eratos(arr1, n, arr2, m);
    if (result == 0) LCS();
    else {
        cout << result << '\n';
        for (int i = result - 1; i >= 0; --i) cout << lcis[i] << ' ';
    }
}
