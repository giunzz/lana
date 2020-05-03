#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N];
void Min(int &a, int b) { 
    if (a == -1) a = b;
    else a = (a < b ? a : b);}
int dp[1 << N][N];

int main() {
    freopen("GREEDY.inp","r",stdin);
    freopen("GREEDY.out","w",stdout);
    int n, x;
    cin >> n >> x;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i) cin >> a[i];
    dp[0][1] = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) if (mask >> i & 1) {
            int preMask = mask ^ (1 << i);
            for (int cnt = 0; cnt <= n; ++cnt) if (dp[preMask][cnt] != -1) {
                // cout << mask << ' ' << i << ' ' << cnt << '\n';
                if (dp[preMask][cnt] + a[i] <= x) {
                    Min(dp[mask][cnt], dp[preMask][cnt] + a[i]);
                } else {
                    Min(dp[mask][cnt + 1], a[i]);
                }
            }
        }
    }
    for (int cnt = 0; cnt <= n; ++cnt) if (dp[(1 << n) - 1][cnt] != -1) {
        cout << cnt << '\n';
        return 0;
    }
    
}