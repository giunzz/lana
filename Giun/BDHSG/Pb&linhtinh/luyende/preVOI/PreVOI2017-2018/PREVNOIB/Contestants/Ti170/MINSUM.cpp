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
#define task "MINSUM"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int snt[maxn], t, a, b, dem = 0, d[3][maxn], dd[3][maxn], cnt[3];

bool kt[maxn];

void chuanbi()
{
    kt[1] = kt[0] = 1;
    FOR(i, 2, 100000)
    {
        if (kt[i]) continue;
        snt[++dem] = i;
        for (int j = i+i; j <= 1000006; j += i)
            kt[j] = 1;
    }
}

void pt(int x, int id)
{
    FOR(i, 1, dem)
    {
        if (x % snt[i]) continue;
        d[id][++cnt[id]] = snt[i];
        while (x % snt[i] == 0)
        {
            dd[id][snt[i]]++;
            x /= snt[i];
        }
    }
}

int poww(int x, int y)
{
    if (y == 0) return 1;
    int c = poww(x, y/2);
    if (y & 1) return c * c * x;
    return c * c;
}

void reset()
{
    FOR(i, 1, 2)
    {
        cnt[i] = 0;
        FOR(j, 1, 1000000)
        {
            dd[i][j] = d[i][j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    cin >> t;
    chuanbi();
    while (t--)
    {
        reset();
        cin >> a >> b;
        int q = __gcd(a, b);
        a /= q;
        b /= q;
        pt(a, 1);
        pt(b, 2);
        FOR(i, 1, cnt[1])
        {
            if (dd[1][d[1][i]] >= 2)
            {
                int p = dd[1][d[1][i]];
                if (p & 1) p--;
                a /= poww(d[1][i], p);
            }
        }
        FOR(i, 1, cnt[2])
        {
            if (dd[2][d[2][i]] >= 2)
            {
                int p = dd[2][d[2][i]];
                if (p & 1) p--;
                b /= poww(d[2][i], p);
            }
        }
        cout << a << " " << b << '\n';
    }
    return 0;
}
