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
#define maxn 100005
#define task "ARRANGE"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int n, a[maxn], res = 0, ans = maxc, b[maxn];

ll sum = 0;

void trau()
{
    int pos = sum/n;
    FOR(i, 1, n)
    {
        bool dd = 0;
        if (a[i] < pos) continue;
        int cur = a[i] - pos;
        int need;
        FORD(j, i-1, 1)
            if (a[j] < pos)
            {
                if (cur == 0) break;
                need = min(cur, pos - a[j]);
                a[j] += need;
                res += need * (i-j);
                cur -= need;
            }
        FOR(j, i+1, n)
        {
            if (a[j] < pos)
            {
                if (cur == 0) break;
                need = min(cur, pos - a[j]);
                a[j] += need;
                res += need * (j-i);
                cur -= need;
            }
        }
        FOR(i, 1, n)
            if (a[i] < pos || a[i] > pos)
            {
                dd = 1;
                break;
            }
        if (!dd) break;
    }
    ans = min(ans, res);
    memcpy(b, a, sizeof (a));
    FORD(i, n, 1)
    {
        bool dd = 0;
        if (b[i] < pos) continue;
        int cur = b[i] - pos;
        int need;
        FORD(j, i-1, 1)
            if (b[j] < pos)
            {
                if (cur == 0) break;
                need = min(cur, pos - b[j]);
                b[j] += need;
                res += need * (i-j);
                cur -= need;
            }
        FOR(j, i+1, n)
        {
            if (b[j] < pos)
            {
                if (cur == 0) break;
                need = min(cur, pos - b[j]);
                b[j] += need;
                res += need * (j-i);
                cur -= need;
            }
        }
        FOR(i, 1, n)
            if (b[i] < pos || b[i] > pos)
            {
                dd = 1;
                break;
            }
        if (!dd) break;
    }
    cout << min(ans, res);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n == 0)
    {
        trau();
        return 0;
    }
    int pos = sum/n;
    int pos2 = sum/n+1;
    FOR(i, 1, n)
    {
        bool dd = 0;
        if (a[i] < pos2) continue;
        int cur = a[i] - pos;
        int need;
        FORD(j, i-1, 1)
            if (a[j] < pos)
            {
                if (cur == 0) break;
                need = min(cur, pos - a[j]);
                a[j] += need;
                res += need * (i-j);
                cur -= need;
            }
            FOR(j, i+1, n)
            {
                if (a[j] < pos)
                {
                    if (cur == 0) break;
                    need = min(cur, pos - a[j]);
                    a[j] += need;
                    res += need * (j-i);
                    cur -= need;
                }
            }
        FOR(i, 1, n)
            if (a[i] < pos || a[i] > pos2)
            {
                dd = 1;
                break;
            }
        if (!dd) break;
        dd = 0;
        if (cur > 0)
        {
            int pp = min(cur/2, min(n-i+1, i));
            FORD(j, i-1, 1)
            if (a[j] < pos2)
            {
                if (cur == pp) break;
                need = min(cur, pos2 - a[j]);
                a[j] += need;
                res += need * (i-j);
                cur -= need;
            }
            FOR(j, i+1, n)
                if (a[j] < pos2)
                {
                    if (cur == pp) break;
                    need = min(cur, pos2 - a[j]);
                    a[j] += need;
                    res += need * (j-i);
                    cur -= need;
                }
        }
        FOR(i, 1, n)
            if (a[i] < pos || a[i] > pos2)
            {
                dd = 1;
                break;
            }
        if (!dd) break;
    }
    ans = min(ans, res);
    memcpy(b, a, sizeof (a));
    FORD(i, n, 1)
    {
        bool dd = 0;
        if (b[i] < pos2) continue;
        int cur = b[i] - pos;
        int need;
        FORD(j, i-1, 1)
            if (b[j] < pos)
            {
                if (cur == 0) break;
                need = min(cur, pos - b[j]);
                b[j] += need;
                res += need * (i-j);
                cur -= need;
            }
            FOR(j, i+1, n)
            {
                if (b[j] < pos)
                {
                    if (cur == 0) break;
                    need = min(cur, pos - b[j]);
                    b[j] += need;
                    res += need * (j-i);
                    cur -= need;
                }
            }
        FOR(i, 1, n)
            if (b[i] < pos || b[i] > pos2)
            {
                dd = 1;
                break;
            }
        if (!dd) break;
        dd = 0;
        if (cur > 0)
        {
            int pp = min(cur/2, min(n-i+1, i));
            FORD(j, i-1, 1)
            if (b[j] < pos2)
            {
                if (cur == pp) break;
                need = min(cur, pos2 - b[j]);
                b[j] += need;
                res += need * (i-j);
                cur -= need;
            }
            FOR(j, i+1, n)
                if (b[j] < pos2)
                {
                    if (cur == pp) break;
                    need = min(cur, pos2 - b[j]);
                    b[j] += need;
                    res += need * (j-i);
                    cur -= need;
                }
        }
        FOR(i, 1, n)
            if (b[i] < pos || b[i] > pos2)
            {
                dd = 1;
                break;
            }
        if (!dd) break;
    }
    cout << min(ans, res);
    return 0;
}
