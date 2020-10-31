#include <bits/stdc++.h>
#define int long long
using namespace std;
int m, n, k;
struct Point{
    int x, y, z, w;
} rnd[2005], e[20], st;
vector <int> v[20];
int x_1[20], ans_1 = 0;
bool ok_1[2005];
bool kt_1(int i, int j) {
    if (rnd[j].x - rnd[j].w <= st.x && rnd[j].x - rnd[j].w <= e[i].x && rnd[j].x + rnd[j].w >= st.x && rnd[j].x + rnd[j].w >= e[i].x) return 1;
    int x = st.x, y = e[i].x;
    if (x > y) swap(x, y);
    if (rnd[j].x + rnd[j].w < x || rnd[j].x - rnd[j].w > y) return 1;
    return 0;
}
void solve_1() {
    for (int i = 1; i <= m; i++) ok_1[i] = 0;
    int cnt = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (x_1[i]) {
            for (int j = 0; j < v[i].size(); j++) {
                if (ok_1[v[i][j]]) continue;
                cnt++; ok_1[v[i][j]] = 1;
                if (cnt > k) return;
            }
            sum += e[i].w;
        }
    }
    ans_1 = max(ans_1, sum);
}
void Try_1(int i) {
    for (int j = 0; j <= 1; j++) {
        x_1[i] = j;
        if (i == n) solve_1();
        else Try_1(i + 1);
    }
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("teaworld.inp", "r", stdin);
    freopen("teaworld.out", "w", stdout);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) {
        cin >> rnd[i].x >> rnd[i].y >> rnd[i].z >> rnd[i].w;
    }
    for (int i = 1; i <= n; i++) {
        cin >> e[i].x >> e[i].y >> e[i].z >> e[i].w;
    }
    cin >> st.x >> st.y >> st.z >> st.w;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!kt_1(i, j)) v[i].push_back(j);
        }
    }
    Try_1(1);
    cout << ans_1;
    return 0;
}
