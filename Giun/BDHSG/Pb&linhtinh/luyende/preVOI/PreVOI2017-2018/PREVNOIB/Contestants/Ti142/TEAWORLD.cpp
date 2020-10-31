#include <bits/stdc++.h>
#define N 2005
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
using namespace std;

int n, m, k, ans, dd[N], xx[N], Z;
struct point
{
    int x, y, z, r, e;
}c[N], p[N], st;
struct line
{
    int a, b, c;
    line(int a=0, int b=0, int c=0) : a(a), b(b), c(c) {}
};
line createLine(point a, point b)
{
    pii v = mp(b.y - a.y, a.x - b.x);
    line z = line(v.F, v.S, -v.F*a.x - v.S*a.y);
    return z;
}
bool inside(point a, point b)
{
    pii v = mp(a.x - b.x, a.y-b.y);
    return v.F*v.F + v.S*v.S <= b.r*b.r;
}
void tinh()
{
    memset(dd, 0, sizeof dd);
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!xx[i]) continue;
        res += p[i].e;
        line li = createLine(st, p[i]);
        for (int j = 1; j <= m; j++)
        {
            if (dd[j]) continue;
            if (inside(p[i], c[j]) != inside(st, c[j]))
            {
                dd[j] = 1;
                continue;
            }
            if (inside(p[i], c[j]) == 1) continue;
            int tuso = li.a*c[j].x + li.b*c[j].y + li.c;
            if (tuso*tuso <= c[j].r*c[j].r*(li.a*li.a + li.b*li.b))
                dd[j] = 1;
        }
    }
    int dem = 0;
    for (int i = 1; i <= m; i++) dem += dd[i];
    if (dem <= k) ans = max(ans, res);
}
void duyet(int pos)
{
    if (pos > n)
    {
        tinh();
        return;
    }
    duyet(pos+1);
    xx[pos] = 1;
    duyet(pos+1);
    xx[pos] = 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("TEAWORLD.INP", "r", stdin);
    freopen("TEAWORLD.OUT", "w", stdout);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        cin >> c[i].x >> c[i].y >> c[i].z >> c[i].r, Z |= (c[i].z != 0);
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y >> p[i].z >> p[i].e, Z |= (p[i].z != 0);
    cin >> st.x >> st.y >> st.z, Z |= (st.z != 0);
    duyet(1);
    cout <<ans;
}
