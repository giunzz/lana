/*******************THACH THAO*******************/

#include <bits/stdc++.h>
#define maxn 1000007
#define maxC 1000000007
#define Task "GIFTS"
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define F first
#define S second

using namespace std;

int n, k, ans = maxC;
int a[maxn], f[maxn];
pii d[maxn];
pair <int, pii> save;

void setup()
{
    cin >> n >> k;
    f[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        f[i] = f[i-1] + a[i];
        if (i >= k) d[i] = mp(f[i] - f[i-k], i);
    }
}

bool compare(pii p, pii q)
{
    if (p.F != q.F) return p.F < q.F;
    return p.S < q.S;
}

void solve()
{
    sort(d + k, d + n + 1, compare);
    save.F = d[n].F;
    save.S.F = d[n].S;
    int id = n - 1;
    while (d[id].F == save.F && (d[id].S >= save.S.F - k + 1)) save.S.S = id, id--;
    id = n - 1;
    while (id >= k)
    {
        if (d[id].F < save.F && (d[id].S < save.S.S || d[id].S - k + 1 > save.S.F))
            ans = min(ans, d[id].F);
        else if (ans != maxC) break;
        id--;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
    setup();
    solve();
    return 0;
}
