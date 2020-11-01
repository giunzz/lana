#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, a, b, ans, cs_1, cs_2;
typedef pair <int, int> ii;
vector <ii> factor_a, factor_b;
vector <int> factor;
void pre_a(int x) {
    int i = 2;
    while (i * i <= x) {
        int cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        if (cnt) factor_a.push_back(ii(i, cnt));
        i++;
    }
    if (x > 1) factor_a.push_back(ii(x, 1));
}
void pre_b(int x) {
    int i = 2;
    while (i * i <= x) {
        int cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        if (cnt) factor_b.push_back(ii(i, cnt));
        i++;
    }
    if (x > 1) factor_b.push_back(ii(x, 1));
}
int Pow(int x, int y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    int p = Pow(x, y / 2);
    p *= p;
    if (y % 2) p *= x;
    return p;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("minsum.inp", "r", stdin);
    freopen("minsum.out", "w", stdout);
    cin >> t;
    if (t <= 100) {
        while (t--) {
            cin >> a >> b;
            if (a <= 50 && b <= 50) {
                factor_a.clear(); factor_b.clear(); factor.clear();
                ans = a + b, cs_1 = a, cs_2 = b;
                int tmp = __gcd(a, b);
                a /= tmp; b /= tmp;
                if (a + b < ans) {
                    ans = a + b; cs_1 = a; cs_2 = b;
                }
                pre_a(a); pre_b(b);
                //for (int i = 0; i < factor_a.size(); i++) cout << factor_a[i].first << " " << factor_a[i].second << '\n';
                for (int i = 0; i < factor_a.size(); i++) {
                    int sl = factor_a[i].second / 2;
                    factor_a[i].second -= sl * 2;
                    int tmp = Pow(factor_a[i].first, sl);
                    a /= tmp;
                    if (a + b < ans) {
                        ans = a + b; cs_1 = a; cs_2 = b;
                    }
                    if (factor_a[i].second > 0) factor.push_back(factor_a[i].first);
                }
                //for (int i = 0; i < factor_b.size(); i++) cout << factor_b[i].first << " " << factor_b[i].second << '\n';
                for (int i = 0; i < factor_b.size(); i++) {
                    int sl = factor_b[i].second / 2;
                    factor_b[i].second -= sl * 2;
                    int tmp = Pow(factor_b[i].first, sl);
                    b /= tmp;
                    if (a + b < ans) {
                        ans = a + b; cs_1 = a; cs_2 = b;
                    }
                    if (factor_b[i].second) factor.push_back(factor_b[i].first);
                }
            // cout << ans << " " << cs_1 << " " << cs_2 << '\n';
                sort(factor.begin(), factor.end());
                //cout << factor.size() << '\n';
                //for (int i = 0; i < factor.size(); i++) cout << factor[i] << " "; cout << '\n';
                int l = factor.size();
                for (int i = 0; i < (1 << l); i++) {
                    int tmp_1 = 1, tmp_2 = 1;
                    for (int j = 0; j < l; j++) {
                        if (i & (1 << j)) tmp_1 *= factor[j];
                        else tmp_2 *= factor[j];
                    }
                    if (tmp_1 + tmp_2 < ans) {
                        ans = tmp_1 + tmp_2; cs_1 = tmp_1; cs_2 = tmp_2;
                    }
                }
                cout << cs_1 << " " << cs_2 << '\n';
            }
            else {
                factor_a.clear(); factor_b.clear(); factor.clear();
                ans = a + b, cs_1 = a, cs_2 = b;
                int tmp = __gcd(a, b);
                a /= tmp; b /= tmp;
                if (a + b < ans) {
                    ans = a + b; cs_1 = a; cs_2 = b;
                }
                pre_a(a); pre_b(b);
                for (int i = 0; i < factor_a.size(); i++) {
                    int sl = factor_a[i].second / 2;
                    factor_a[i].second -= sl * 2;
                    if (factor_a[i].second > 0) factor.push_back(factor_a[i].first);
                }
                for (int i = 0; i < factor_b.size(); i++) {
                    int sl = factor_b[i].second / 2;
                    factor_b[i].second -= sl * 2;
                    if (factor_b[i].second) factor.push_back(factor_b[i].first);
                }
                sort(factor.begin(), factor.end());
                int l = factor.size();
                for (int i = 0; i < (1 << l); i++) {
                    int tmp_1 = 1, tmp_2 = 1;
                    for (int j = 0; j < l; j++) {
                        if (i & (1 << j)) tmp_1 *= factor[j];
                        else tmp_2 *= factor[j];
                    }
                    if (tmp_1 + tmp_2 < ans) {
                        ans = tmp_1 + tmp_2; cs_1 = tmp_1; cs_2 = tmp_2;
                    }
                }
                cout << cs_1 << " " << cs_2 << '\n';
            }
        }
    }
    else {
        while (t--) {
            cin >> a >> b;
                factor_a.clear(); factor_b.clear(); factor.clear();
                ans = a + b, cs_1 = a, cs_2 = b;
               // cout << a << " " << b << '\n';
                int tmp = __gcd(a, b);
                a /= tmp; b /= tmp;
                if (a + b < ans) {
                    ans = a + b; cs_1 = a; cs_2 = b;
                }
                pre_a(a); pre_b(b);
                for (int i = 0; i < factor_a.size(); i++) {
                    int sl = factor_a[i].second / 2;
                    factor_a[i].second -= sl * 2;
                    if (factor_a[i].second > 0) factor.push_back(factor_a[i].first);
                }
                for (int i = 0; i < factor_b.size(); i++) {
                    int sl = factor_b[i].second / 2;
                    factor_b[i].second -= sl * 2;
                    if (factor_b[i].second) factor.push_back(factor_b[i].first);
                }
                sort(factor.begin(), factor.end());
                int l = factor.size();
                for (int i = 0; i < (1 << l); i++) {
                    int tmp_1 = 1, tmp_2 = 1;
                    for (int j = 0; j < l; j++) {
                        if (i & (1 << j)) tmp_1 *= factor[j];
                        else tmp_2 *= factor[j];
                    }
                    if (tmp_1 + tmp_2 < ans) {
                        ans = tmp_1 + tmp_2; cs_1 = tmp_1; cs_2 = tmp_2;
                    }
                }
               cout << cs_1 << " " << cs_2 << '\n';
        }
    }
    return 0;
}
