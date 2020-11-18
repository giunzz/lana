#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 1e5 + 5;

pair <pair <int, int>, int> a[N];

int n;

bool cmp(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b)
{
    return (a.fi.fi != b.fi.fi) ? (a < b) : (a.fi.se > b.fi.se);
}

void solve()
{
    vector <int> mn(n + 1, -1);
    vector <int> dp(n + 1, 0);
    vector <vector <int>> root(n + 1, vector <int> (0));
    mn[0] = (int) 1e9 + 1;
    for (int i = 1; i <= n; i++)
    {
        int lo = 0;
        int hi = n;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;
            if (mn[mid] >= a[i].fi.se) lo = mid;
            else hi = mid;
        }
        mn[lo + 1] = a[i].fi.se;
        dp[i] = lo + 1;
    }
    int res = *max_element(dp.begin(), dp.end());
    cout << res << "\n";
    for (int i = 1; i <= n; i++)
    {
        root[dp[i]].push_back(a[i].se);
    }
    for (int i = 1; i <= res; i++)
    {
        reverse(root[i].begin(), root[i].end());
        cout << root[i].size() << " ";
        for (int x : root[i]) cout << x << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1, cmp);
    solve();
    return 0;
}
