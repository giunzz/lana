#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k;
int a[1000010], f[1000010], s[1000010], Max[4 * 1000010];

bool check(int x) {
    int mintam = 1e15;
    for (int i = 1; i + k - 1 <= n; ++i) {
        int maxtam = -1e15;
        for (int j = 1; j + k - 1 < i; ++j) {
            maxtam = max(maxtam, s[j + k - 1] - s[j - 1]);
        }
        for (int j = i + k; j + k - 1 <= n; ++j) {
            maxtam = max(maxtam, s[j + k - 1] - s[j - 1]);
        }
        mintam = min(mintam, maxtam);
    }
    return mintam <= x;
}

int Get_Max(int u, int ll, int rr, int L, int R) {
    if (rr < L || R < ll) return -1e15;
    if (L <= ll && rr <= R) return Max[u];
    int mid = (ll + rr) >> 1;
    int Max1 = Get_Max(u * 2, ll, mid, L, R);
    int Max2 = Get_Max(u * 2 + 1, mid + 1, rr, L, R);
    return max(Max1, Max2);
}

void Build(int u, int ll, int rr) {
    if (ll == rr) {
        Max[u] = f[ll];
        return;
    }
    int mid = (ll + rr) >> 1;
    Build(u * 2, ll, mid);
    Build(u * 2 + 1, mid + 1, rr);
    Max[u] = max(Max[u * 2], Max[u * 2 + 1]);
}

bool chk(int x) {
    int mintam = 1e15;
    for (int i = 1; i + k - 1 <= n; ++i) {
        int maxtam = -1e15;
        maxtam = max(maxtam, Get_Max(1, 1, n, 1, i - k));
        maxtam = max(maxtam, Get_Max(1, 1, n, i + k, n - k + 1));
        mintam = min(mintam, maxtam);
    }
    return mintam <= x;
}

void solve() {
    for (int i = 1; i + k - 1 <= n; ++i) {
        f[i] = s[i + k - 1] - s[i - 1];
    }
    Build(1, 1, n);
    int l = -1, r = 1e15 + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (chk(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}

main() {
    freopen("gifts.inp", "r", stdin);
    freopen("gifts.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    if (n > 5000) {
        solve();
        return 0;
    }
    int l = -1, r = 1e15 + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}
