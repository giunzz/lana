/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ll long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define pi acos(-1)
#define N 3003
#define task "sequence"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int m, n, k, a[N], ans[N], res[N], b[N];

void Duyet(int tt, int x, int y)
{
    if (tt == k)
    {
        FOR(i, 1, k)
        {
            if (res[i] == ans[i]) continue;
            if (ans[i] < res[i])
            {
                FOR(j, 1, k) res[j] = ans[j];
                return;
            }
            return;
        }
        return;
    }
    FOR(i, x+1, m)
    {
        ans[tt+1] = a[i];
        Duyet(tt+1, i, y);
        ans[tt+1] = 0;
    }
    FOR(i, y+1, n)
    {
        ans[tt+1] = b[i];
        Duyet(tt+1, x, i);
        ans[tt+1] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> m >> n >> k;
    FOR(i, 1, m) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    if (k == m+n)
    {
        int l1 = 1, l2 = 1;
        while (1)
        {
            if (l1 == m)
            {
                if (l2 <= n) cout << b[l2++] << ' ';
                    else break;
            }
                else
                {
                    if (l2 == n)
                    {
                        if (l1 <= m) cout << a[l1++] << ' ';
                            else break;
                    }
                        else
                        {
                            if (a[l1] < b[l2]) cout << a[l1++] << ' ';
                                else cout << b[l2++] << ' ';
                        }
                }
        }
        return 0;
    }
    res[1] = maxc;
    Duyet(0, 0, 0);
    FOR(i, 1, k) cout << res[i] << ' ';
    return 0;
}
