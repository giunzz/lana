#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define FOR(i, u, v) for (int i = u; i <= v; i++)
#define FORD(i, v, u) for (int i = v; i >= u; i--)
#define N 10004
#define maxc 1ll*100000000000007
#define mid (r + l)/2
#define ll long long


using namespace std;

int n;
ll Time, Sxmn, Symn, Sxmx, Symx, rr[2*N];
pii a[N];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct Event
{
    ll x, y1, y2, type;
    Event(ll _x=0, ll _y1=0, ll _y2=0, ll _type=0) : x(_x), y1(_y1), y2(_y2), type(_type) {}
    bool operator < (const Event &rhs) const
    {
        if (x != rhs.x) return x < rhs.x;
        return type < rhs.type;
    }
}e[2*N];
struct intervalTree
{
    int t[N << 3], lazy[N << 3];

    void reset()
    {
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }
    void push(int l, int r, int id)
    {
        if (lazy[id] == 0) return;
        int z = lazy[id]; lazy[id] = 0;
        t[id] += z;
        if (l == r) return;
        lazy[id*2] += z;
        lazy[id*2+1] += z;
    }
    void upd(int l, int r, int id, int x, int y, int val)
    {
        push(l, r, id);
        if (l > y || r < x) return;
        if (l >= x && r <= y)
        {
            lazy[id] += val;
            push(l, r, id);
            return;
        }
        upd(l, mid, id*2, x, y, val);
        upd(mid+1, r, id*2+1, x, y, val);
        t[id] = min(t[id*2], t[id*2+1]);
    }
    int getMin(int l, int r, int id, int x, int y)
    {
        push(l, r, id);
        if (l > y || r < x) return 1;
        if (l >= x && r <= y) return t[id];
        return min(getMin(l, mid, id*2, x, y), getMin(mid+1, r, id*2+1, x, y));
    }
}t;
bool check(ll val)
{
    ll xmn, ymn, xmx, ymx, cc = 0, cur = 0;
    FOR(i, 1, n-1)
    {
        ll u = a[i].F;
        ll v = a[i].S;
        xmn = maxc, ymn = maxc, xmx = -maxc, ymx = -maxc;
        FOR(j, 0, 3)
        {
            ll x = u + val*dx[j];
            ll y = v + val*dy[j];
            ll xx = x - y;
            ll yy = x + y;
            xmn = min(xmn, xx);
            xmx = max(xmx, xx);
            ymn = min(ymn, yy);
            ymx = max(ymx, yy);
        }
        ll x2 = min(xmx, Sxmx);
        ll y2 = min(ymx, Symx);
        ll x1 = max(xmn, Sxmn);
        ll y1 = max(ymn, Symn);
        if (x1 > x2 || y1 > y2) continue;
        e[++cur] = {x1, y1, y2, 0};
        e[++cur] = {x2+1, y1, y2, 1};
        rr[++cc] = y1;
        rr[++cc] = y2;
    }
    if (cur == 0) return 1;
    rr[++cc] = Symn; rr[++cc] = Symx;
    sort(rr+1, rr+cc+1);
    cc = unique(rr+1, rr+cc+1) - rr - 1;
    sort(e+1, e+cur+1);
    ll L = lower_bound(rr+1, rr+cc+1, Symn) - rr;
    ll R = lower_bound(rr+1, rr+cc+1, Symx) - rr;

    FOR(i, 1, cur)
    {
        e[i].y1 = lower_bound(rr+1, rr+cc+1, e[i].y1) - rr;
        e[i].y2 = lower_bound(rr+1, rr+cc+1, e[i].y2) - rr;
    }
    t.reset();
    if (e[1].x > Sxmn || e[cur].x <= Sxmx) return 1;
    t.upd(1, cc, 1, e[1].y1, e[1].y2, 1);
    FOR(i, 2, cur)
    {
        if (e[i].x != e[i-1].x && e[i-1].x <= Sxmx)
        {
            ll val = t.getMin(1, cc, 1, L, R);
            if (val == 0) return 1;
        }
        if (e[i].type == 0)
            t.upd(1, cc, 1, e[i].y1, e[i].y2, 1);
        else t.upd(1, cc, 1, e[i].y1, e[i].y2, -1);
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ROBOTS.INP", "r", stdin);
    freopen("ROBOTS.OUT", "w", stdout);
    cin >> n >> Time;
    n++;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;

    Sxmn = maxc, Symn = maxc, Sxmx = -maxc, Symx = -maxc;
    FOR(j, 0, 3)
    {
        ll x = a[n].F + Time*dx[j];
        ll y = a[n].S + Time*dy[j];
        ll xx = x - y;
        ll yy = x + y;
        Sxmn = min(Sxmn, xx);
        Sxmx = max(Sxmx, xx);
        Symn = min(Symn, yy);
        Symx = max(Symx, yy);
    }
    ll l = 0, r = maxc;
    while (r - l > 1)
    {
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout <<r;
}
