#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define int long long
using namespace std;
const int N = 5e4 + 5;

pair <pair <int, int>, int> a[N];

int n;

bool minimize(int &a, int b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i;
    }
    sort(a, a + n);
    set <pair <pair <int, int>, int>> s;
    int mn = (int) 1e18;
    pair <int, int> res = mp(-1, -1);
    for (int i = 0, j = 0; i < n; i++)
    {
        int d = ceil(sqrt(mn));
        while (a[i].fi.fi - a[j].fi.fi >= mn)
        {
            s.erase(mp(mp(a[j].fi.se, a[j].fi.fi), a[j].se));
            j++;
        }
        auto l = s.lower_bound(mp(mp(a[i].fi.se - d, a[i].fi.fi), 0));
        auto r = s.upper_bound(mp(mp(a[i].fi.se + d, a[i].fi.fi), 0));
        for (auto it = l; it != r; it++)
        {
            int dx = a[i].fi.fi - it->fi.se;
            int dy = a[i].fi.se - it->fi.fi;
            if (minimize(mn, dx * dx + dy * dy))
            {
                res = mp(it->se, a[i].se);
            }
        }
        s.insert(mp(mp(a[i].fi.se, a[i].fi.fi), a[i].se));
    }
    if (res.fi > res.se) swap(res.fi, res.se);
    cout << res.fi << " " << res.se << " " << fixed << setprecision(6) << sqrt(mn);
    return 0;
}
