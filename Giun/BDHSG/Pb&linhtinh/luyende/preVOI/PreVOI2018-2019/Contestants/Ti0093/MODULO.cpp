#define taskname "MODULO"
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 70;
const int N = 1e8;

int n, a, b, k, x[maxn], res, m, ans;
bool ok;

void Update()
{
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (x[i] == 0) sum = sum * 10 + a;
        else sum = sum * 10 + b;
    }
    if (sum % m == k) res = sum;
}

void Try(int i)
{
    for (int j = 0; j <= 1; ++j) {
        x[i] = j;
        if (i == n) Update();
        else Try(i + 1);
    }
}
bool Check(int d)
{
    while (d) {
        if (d % 10 != a && d % 10 != b) return false;
        d /= 10;
    }
    return true;
}

void Subtask_1()
{
    res = -1;
    Try(1);
    cout << res;
}

void Subtask_2()
{
    int s = m;
    ans = -1;
    int abc = 1 << (n + 2);
    while (s % m != k && s <= abc) {
        ++s;
        if (s % m == k) {
            if (Check(s) == false) ++s;
            else ans = s;
        }
    }
    cout << ans;
}

void Subtask_3()
{
    cout << -1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    cin >> a >> b >> n >> k;
    m = 1 << n;
    if (n <= 20) Subtask_1();
    else if (n <= 40) Subtask_2();
    else Subtask_3();
}
