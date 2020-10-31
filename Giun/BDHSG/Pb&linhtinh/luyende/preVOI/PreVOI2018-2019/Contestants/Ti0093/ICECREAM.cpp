#define taskname "ICECREAM"
#include <bits/stdc++.h>

using namespace std;

const int maxn = 350;
const int base = 1e9 + 9;

int n, m, m1, m2, m50, a, b, c;
bool ok;
int x[maxn], ret = 0;

void Update()
{
    ok = true;
    a = m50;
    b = m1;
    c = m2;
    for (int i = 1; i <= n; ++i) {
        if (x[i] == 0) {
            ++a;
            if (a > m) ok = false;
        }
        if (x[i] == 1) {
            if (a > 0) {
                ++b;
                --a;
                if (b > m) ok = false;
            }
            else ok = false;
        }
        if (x[i] == 2) {
            if (b > 0 && a > 0) {
                ++c;
                --b;
                --a;
                if (c > m) ok = false;
            }
            else if (a >= 3) a -= 3;
            else ok = false;
        }
    }
    if (ok == true) ++ret;
}

void Try(int i)
{
    for (int j = 0; j <= 2; ++j) {
        x[i] = j;
        if (i == n) Update();
        else Try(i + 1);
    }
}

void Subtask_1()
{
    Try(1);
    cout << ret % base;
}

void Subtask_2()
{
    int ans = n + m + 1;
    ans -= m50;
    ans -= m1;
    ans -= m2;
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    cin >> n >> m;
    cin >> m50 >> m1 >> m2;
    if (n <= 15 && m <= 10) Subtask_1();
    if (n >= 16 && n <= 50) Subtask_2();
}
