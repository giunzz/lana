#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 21;
const int maxm = 2003;

int n, m, k;
ll x, y, z, ans;
bool zeroy = true, zeroz = true;
struct circle
{
    ll x, y, z, r;
} c[maxm];

struct teastore
{
    ll x, y, z, e;
} a[maxn];

void inp()
{
    cin >> m >> n >> k;

    for (int i = 1; i <= m; ++i)
    {
        cin >> c[i].x >> c[i].y >> c[i].z >> c[i].r;
        if (c[i].y) zeroy = false;
        if (c[i].z) zeroz = false;
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].y >> a[i].z >> a[i].e;
        if (a[i].y) zeroy = false;
        if (a[i].z) zeroz = false;
    }

    cin >> x >> y >> z;
    if (y) zeroy = false;
    if (z) zeroz = false;
}

void sub1()
{
    return;
}

void sub2()
{
    return;
}

void sub3()
{
    return;
}

void work_out()
{
    if (k == m)
    {
        for (int i = 1; i <= n; ++i)
            ans += a[i].e;
        cout << ans;
        return;
    }

    if (k == 0 && zeroy && zeroz)
    {
        for (int i = 1; i <= n; ++i)
        {
            bool ok = true;
            for (int j = 1; j <= m; ++j)
            {
                if (abs(a[i].x - c[j].x) <= c[j].r && abs(x - c[j].x) > c[j].r || abs(a[i].x - c[j].x) > c[j].r && abs(x - c[j].x) <= c[j].r) { ok = false; break;}
                if (a[i].x < c[j].x - c[j].r && x > c[j].x + c[j].r || a[i].x > c[j].x + c[j].r && x < c[j].x - c[j].r) { ok = false; break;}
            }
            if (ok) ans += a[i].e;
        }
        cout << ans;
        return;
    }

    if (k == 0 && zeroz)
    {
        for (int i = 1; i <= n; ++i)
        {
            bool ok = true;
            ll A = a[i].x - x;
            ll B = a[i].y - y;
            ll C = -(a[i].x*A + B*a[i].y);
            for (int j = 1; j <= m; ++j)
                if ((c[j].x*A + c[j].y*B + C)*(c[j].x*A + c[j].y*B + C) < c[j].r*c[j].r*(A*A + B*B)) { ok = false; break;}
            if (ok) ans += a[i].e;
        }
        cout << ans;
        return;
    }

    for (;;);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("TEAWORLD.inp", "r", stdin);
    freopen("TEAWORLD.out", "w", stdout);

    inp();
    work_out();

    return 0;
}
