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
#define maxn 1000006
#define task "GIFTS"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int n, k, a[maxn];

pii luu;

ll s[maxn], pos = 0, res1 = 0, res2 = 0, res3 = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    cin >> n >> k;
    s[0] = 0;
    FOR(i, 1, n)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    FOR(i, k, n)
        if (s[i] - s[i-k] > pos)
        {
            pos = s[i] - s[i-k];
            luu = MP(i-k+1, i);
        }
    FOR(i, k, n)
    {
        int l = i-k+1;
        int r = i;
        if (r < luu.F || l > luu.S)
            res1 = max(res1, s[r] - s[l-1]);
    }
    FOR(i, k, n)
    {
        int l = i-k+1;
        int r = i;
        if (r < luu.F-1 || l > luu.S+1)
            res2 = max(res2, s[r] - s[l-1]);
    }
    FOR(i, k, n)
    {
        int l = i-k+1;
        int r = i;
        if (r < luu.F+1 || l > luu.S-1)
            res3 = max(res3, s[r] - s[l-1]);
    }
    cout << min(res1, min(res2, res3));
    return 0;
}
