#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> ii;
const int N = 100015;
const ll oo = 1e12 + 15;

int n, m, tmp, kt;
ll res, mi1, mi2;
int hu[] = {0, 0, -1, 1};
int hv[] = {1, -1, 0, 0};
struct data
{
    int x, y;
    data (int x = 0, int y = 0) : x(x), y(y) {}
};
data a[N], b[N];
data s;
int check[4015][4015];
map <ii, int> mp;

ll tn(data a, data b)
{
    ll ss = 1LL*a.x - 1LL*b.x;
    ll an = 1LL*a.y - 1LL*b.y;
    return abs(ss) + abs(an);
}

void sub1()
{
    queue <data> q;
    q.push(s);
    mp[ii(s.x, s.y)] = 0;
    while (!q.empty())
    {
        data ss = q.front(); q.pop();
        ll an = oo;
        for (int i = 1; i <= m; i++)
            an = min(an, tn(ss, a[i]));
        res = max(res, an);
        if (mp[ii(ss.x, ss.y)] == n) continue;
        for (int i = 0; i < 4; i++)
        {
            int u = ss.x + hu[i];
            int v = ss.y + hv[i];
            if (mp[ii(u, v)])continue;
            mp[ii(u, v)] = mp[ii(ss.x, ss.y)] + 1;
            q.push(data(u, v));
        }
    }
    cout << res <<"\n";
}

void sub2()
{
    queue <data> q;
    int c = 2015, lim = 4015;
    for (int i = 1; i <= m; i++) a[i].x += c, a[i].y += c;
    s.x += c, s.y += c;
    int minx = s.x - n, miny = s.y - n;
    int maxx = s.x + n, maxy = s.y + n;
    for (int i = 1; i <= m; i++)
    {
        q.push(a[i]);
        check[a[i].x][a[i].y] = 1;
    }
    //cout << maxx <<" "<< maxy <<" "<<minx <<" "<< miny <<"\n";
    maxx = maxy = lim, minx = miny = 0;
    int d = 0;
    while (!q.empty())
    {
        data ss = q.front(); q.pop();
        if (tn(ss, s) <= n)
            res = check[ss.x][ss.y] - 1;
        for (int i = 0; i < 4; i++)
        {
            d++;
            int u = ss.x + hu[i];
            int v = ss.y + hv[i];
            if (check[u][v]) continue;
            if (u > maxx || v > maxy) continue;
            if (u < minx || v < miny) continue;
            if (tn(ss, s) >= n && tn(data(u,v), s) > tn(ss, s)) continue;
            check[u][v] = check[ss.x][ss.y] + 1;
            q.push(data(u, v));
        }
    }
    cout << res <<"\n";
}

int main()
{
    #define file "ROBOTS"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    kt = 0;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].x >> a[i].y;
        if (abs(a[i].x) > 1000 || abs(a[i].y) > 1000) kt = 1;
    }
    if (abs(s.x) > 1000 || abs(s.y) > 1000) kt = 1;
    if (n <= 300 && m <= 300) return sub1(), 0;
    if (n <= 1000 && kt == 0) return sub2(), 0;

    for (int i = 1; i <= 5; i++) b[i] = s;
    b[2].x = s.x + n; b[3].x = s.x - n;
    b[4].y = s.y + n, b[4].y = s.y - n;
    res = 0;
    for (int i = 1; i <= 5; i++)
    {
        ll ss = oo;
        for (int j = 1; j <= m; j++)
            ss = min(ss, tn(b[i], a[j]));
        res = max(res, ss);
    }
    mi1 = mi2 = oo;
    for (int i = 1; i <= m; i++)
    {
        if (a[i].x >= s.x) mi1 = min(mi1, tn(a[i], s));
        if (a[i].x <= s.x) mi2 = min(mi2, tn(a[i], s));
    }
    ll an = abs(mi2 - mi1) / 2;
    if (an <= 1LL * n)
    {
        n -= an;
        if (mi1 > mi2) s.x -= an;
        else s.x += an;
    }
    else
    {
        if (mi1 > mi2) s.x -= n;
        else s.x += n;
    }
    mi1 = mi2 = oo;
    for (int i = 1; i <= m; i++)
    {
        if (a[i].y >= s.y) mi1 = min(mi1, tn(a[i], s));
        if (a[i].x <= s.y) mi2 = min(mi2, tn(a[i], s));
    }
    an = abs(mi2 - mi1) / 2;
    if (an <= 1LL * n)
    {
        n -= an;
        if (mi1 > mi2) s.y -= an;
        else s.y += an;
    }
    else
    {
        if (mi1 > mi2) s.y -= n;
        else s.y += n;
    }
    ll ss = oo;
    for (int i = 1; i <= m; i++)
        ss = min(ss, tn(a[i], s));
    res = max(res, ss);
    cout << res <<"\n";

    return 0;
}
