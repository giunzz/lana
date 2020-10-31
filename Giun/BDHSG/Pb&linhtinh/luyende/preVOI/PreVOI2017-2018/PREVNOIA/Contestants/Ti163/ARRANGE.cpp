/*******************THACH THAO*******************/

#include <bits/stdc++.h>
#define maxn 100007
#define maxC 1000000007
#define Task "ARRANGE"
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define F first
#define S second

using namespace std;

int n;
long long ans = 0;
int a[maxn];
long long f[maxn];

void setup()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        f[i] = f[i-1] + 0ll + a[i];
    }
}

void solve()
{
    int cur = f[n] / n;
    for (int i = 1; i <= n; ++i)
        if (a[i] == cur) continue;
        else if (a[i] > cur)
        {
            int id = i - 1;
            while (id > 0)
            {
                if (a[id] < cur)
                {
                    if (a[i] - cur >= cur - a[id])
                    {
                        int t = cur - a[id];
                        a[i] -= t;
                        a[id] += t;
                        ans += 1ll * t * (i - id);
                    }
                    else
                    {
                        int t = a[i] - cur;
                        a[id] += t;
                        a[i] = cur;
                        ans += 1ll * t * (i - id);
                    }
                }
                if (a[i] == cur) break;
                id--;
            }
            id = i + 1;
            while (id <= n)
            {
                if (a[id] < cur)
                {
                    if (a[i] - cur >= cur - a[id])
                    {
                        int t = cur - a[id];
                        a[i] -= t;
                        a[id] += t;
                           ans += 1ll * t * (id - i);
                    }
                    else
                    {
                        int t = a[i] - cur;
                        a[id] += t;
                        a[i] = cur;
                        ans += 1ll * t * (id - i);
                    }
                }
                if (a[i] == cur) break;
                id++;
            }
        }
        for (int i = 1; i <= n; ++i)
        if (a[i] > cur + 1)
        {
            int id = i - 1;
            while (id > 0)
            {
                if (a[id] == cur)
                {
                    a[id] = cur + 1;
                    a[i]--;
                    ans += i - id;
                    if (a[i] == cur + 1) break;
                    id--;
                }
            }
            id = i + 1;
            while (id <= n)
            {
                if (a[id] == cur)
                {
                    a[id] = cur + 1;
                    a[i]--;
                    ans += id - i;
                    if (a[i] == cur + 1) break;
                    id++;
                }
            }
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
