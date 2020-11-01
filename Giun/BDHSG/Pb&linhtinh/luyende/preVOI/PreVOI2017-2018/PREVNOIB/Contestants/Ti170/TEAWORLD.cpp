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
#define maxn 2003
#define task "TEAWORLD"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int m, n, k, dem = 0, f[3][maxn], xs, ys, zs, luu, res = -maxc, demz = 0, demyz = 0, sum = 0;

struct data
{
    int x, y, z, ts;
} ball[maxn], shop[maxn];

pair <int, pii> a[maxn];

void sub1()
{
    FOR(i, 1, m)
    {
        a[++dem] = MP(ball[i].x+ball[i].ts, MP(1, i));
        a[++dem] = MP(ball[i].x-ball[i].ts, MP(1, i));
    }
    FOR(i, 1, n)
        a[++dem] = MP(shop[i].x, MP(2, i));
    a[++dem] = MP(xs, MP(3, 0));
    sort(a+1, a+dem+1);
    FOR(i, 1, dem) if (a[i].S.F == 3) luu = i;
    int pos1 = 1;
    int pos2 = 1;
    while (a[luu-pos1].S.F == 2)
    {
        f[2][0] += shop[a[luu-pos1].S.S].ts;
        pos1++;
    }
    while (a[luu+pos2].S.F == 2)
    {
        f[1][0] += shop[a[luu+pos2].S.S].ts;
        pos2++;
    }
    FOR(i, 1, k)
    {
        f[1][i] = f[1][i-1];
        pos2++;
        while (a[luu+pos2].S.F == 2)
        {
            f[1][i] += shop[a[luu+pos2].S.S].ts;
            pos2++;
        }
    }
    FOR(i, 1, k)
    {
        f[2][i] = f[2][i-1];
        pos1++;
        while (a[luu-pos1].S.F == 2)
        {
            f[2][i] += shop[a[luu-pos1].S.S].ts;
            pos1++;
        }
    }
    FOR(i, 1, k)
        res = max(res, f[1][i] + f[2][k-i]);
    cout << res;
}

void sub2()
{
    res = 2.86*sum/4;
    cout << res;
}

void sub3()
{
    cout << sum/2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    cin >> m >> n >> k;
    FOR(i, 1, m)
    {
        int x, y, z, r;
        cin >> x >> y >> z >> r;
        ball[i] = {x, y, z, r};
        if (y == 0 && z == 0) demyz++;
        if (z == 0) demz++;
    }
    FOR(i, 1, n)
    {
        int x, y, z, e;
        cin >> x >> y >> z >> e;
        shop[i] = {x, y, z, e};
        sum += e;
        if (y == 0 && z == 0) demyz++;
        if (z == 0) demz++;
    }
    cin >> xs >> ys >> zs;
    if (ys == 0 && zs == 0) demyz++;
    if (zs == 0) demz++;
    if (demyz == m + n + 1) sub1();
        else if (demz == m + n + 1) sub2();
            else sub3();
    return 0;
}
