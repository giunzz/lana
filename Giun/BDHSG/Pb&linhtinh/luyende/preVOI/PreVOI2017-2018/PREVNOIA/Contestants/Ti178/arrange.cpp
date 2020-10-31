#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[100005];
typedef pair <int, int> ii;
stack <ii> st_1, st_2;
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("arrange.inp", "r", stdin);
    freopen("arrange.out", "w", stdout);
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res += a[i];
    }
    if (res % n == 0) {
        int val = res / n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == val) continue;
            if (a[i] > val) {
                int cur = a[i] - val;
                a[i] = val;
                while (!st_2.empty() && cur > 0) {
                    ii tmp = st_2.top(); st_2.pop();
                    if (cur >= tmp.first) {
                        cur -= tmp.first; ans += (i - tmp.second) * tmp.first;
                    }
                    else {
                        tmp.first -= cur; ans += (i - tmp.second) * cur;
                        st_2.push(ii(tmp.first, tmp.second));
                    }
                }
            }
            else {
                while (!st_1.empty() && a[i] != val) {
                    ii tmp = st_1.top(); st_1.pop();
                    if (tmp.first >= val - a[i]) {
                        tmp.first -= (val - a[i]);
                        ans += (i - tmp.second) * (val - a[i]);
                        if (tmp.first) st_1.push(ii(tmp.first, tmp.second));
                        a[i] = val;
                    }
                    else {
                        a[i] += tmp.first; ans += (i - tmp.second) * tmp.first;
                    }
                }
                if (a[i] < val) st_2.push(ii(val - a[i], i));
            }
        }
        cout << ans;
    }
    else {
        int val = res / n, sl_2 = res % n, sl_1 = n - sl_2;
        int ans = 0, cnt_1 = 0, cnt_2 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == val && cnt_1 < sl_1) {cnt_1++; continue;}
            if (a[i] == val + 1 && cnt_2 < sl_2) {cnt_2++; continue;}
            int cur_22 = val;
            if (cnt_1 == sl_1) cur_22++;
            if (a[i] > cur_22) {
                int cur = a[i] - cur_22;
                a[i] = cur_22;
                while (!st_2.empty() && cur > 0) {
                    ii tmp = st_2.top(); st_2.pop();
                    if (cur >= tmp.first) {
                        cur -= tmp.first; ans += (i - tmp.second) * tmp.first;
                    }
                    else {
                        tmp.first -= cur; ans += (i - tmp.second) * cur;
                        st_2.push(ii(tmp.first, tmp.second));
                    }
                }
            }
            else {
                while (!st_1.empty() && a[i] != cur_22) {
                    ii tmp = st_1.top(); st_1.pop();
                    if (tmp.first >= cur_22 - a[i]) {
                        tmp.first -= (cur_22 - a[i]);
                        ans += (i - tmp.second) * (cur_22 - a[i]);
                        if (tmp.first) st_1.push(ii(tmp.first, tmp.second));
                        a[i] = cur_22;
                    }
                    else {
                        a[i] += tmp.first; ans += (i - tmp.second) * tmp.first;
                    }
                }
                if (a[i] < cur_22) st_2.push(ii(cur_22 - a[i], i));
            }
        }
        cout << ans;
    }
    return 0;
}
