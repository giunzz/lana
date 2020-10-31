#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e6 + 7;
const ll Inf = 1e18 + 7;
int n, m, tmp, i, j, k, t;
ll a[N], b[N], maxtr[N], maxsa[N], res;

int main()
{
//#define file "r"
#define file "GIFTS"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        if(i < k) b[i] = a[i] + b[i - 1];
        else b[i] = b[i - 1] + a[i] - a[i - k], maxtr[i] = max(maxtr[i - 1], b[i]);
    }
    for(int i = n; i >= 1; i --)
    {
        b[i] = 0;
        if(i + k > n + 1) b[i] = b[i + 1] + a[i];
        else b[i] = b[i + 1] + a[i] - a[i + k], maxsa[i] = max(maxsa[i + 1], b[i]);
    }
    res = Inf;
    for(int i = 1; i <= n - k; i ++)
    {
        res = min(res, max(maxtr[i - 1], maxsa[i + k]));
    }
    cout << res << "\n";
    return 0;
}
