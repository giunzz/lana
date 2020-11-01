/*******************THACH THAO*******************/

#include <bits/stdc++.h>
#define maxn 2027
#define maxC 1000000007
#define Task "TEAWORLD"
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define F first
#define S second

using namespace std;

struct data
{
    int fi, se, th, fo, ff;
};

int m, n, k, ans = -maxC, dem = 0, xs, ys, zs, boss;
int tea[maxn], lamp[maxn];
data a[maxn];

void setup()
{
    cin >> m >> n >> k;
    int x, y, z, t;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y >> z >> t;
        a[++dem] = {x, y, z, t, 0};
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y >> z >> t;
        a[++dem] = {x, y, z, t, 1};
    }
    cin >> xs >> ys >> zs;
    a[++dem] = {xs, ys, zs, 0, 2};
}

int compare(data p, data q)
{
    return p.fi < q.fi;
}

void solve()
{
    if (ys == zs && ys == 0)
    {
        sort(a+1, a+dem+1, compare);
        for (int i = 1; i <= dem; ++i)
        {
            if (a[i].ff == 2) boss = i;
            tea[i] = tea[i-1] + (a[i].ff == 1 ? a[i].fo : 0);
            lamp[i] = lamp[i-1] + (a[i].ff == 0 ? 1 : 0);
        }
        if (k == 0)
        {
            ans = 0;
            for (int i = boss - 1; i >= 1; --i)
                if (a[i].ff == 0) break;
                else ans += a[i].fo;
            for (int i = boss + 1; i <= dem; ++i)
                if (a[i].ff == 0) break;
                else ans += a[i].fo;
        }
        else
        {
            int id1 = 1;
            int id2 = boss - 1;
            while (id1 <= boss + 1 && id2 <= dem)
            {
                while (lamp[id2] - lamp[id1-1] <= k && id2 <= dem) id2++;
                if (id2 > dem) id2 = dem;
                while (lamp[id2] - lamp[id1-1] > k && id1 > 0) id1++;
                ans = max(ans, tea[id2] - tea[id1-1]);
                id2++;
                id1++;
                k -= lamp[id2] - lamp[id1-1];
            }
        }
        cout << ans;
    }
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
