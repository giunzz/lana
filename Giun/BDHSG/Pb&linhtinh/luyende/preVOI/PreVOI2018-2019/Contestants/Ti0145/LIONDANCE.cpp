#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define FOR(i, u, v) for (int i = u; i <= v; i++)
#define FORD(i, v, u) for (int i = v; i >= u; i--)
#define mid (r + l)/2
#define N 4005
#define maxc 1000000007


using namespace std;

struct IntervalTree
{
    int t[N << 3];
    void reset()
    {
        memset(t, 0, sizeof t);
    }
    void push(int l, int r, int id)
    {
        if (l == r) return;
        t[id*2] = max(t[id*2], t[id]);
        t[id*2+1] = max(t[id*2+1], t[id]);
    }
    void update(int l, int r, int id, int x, int y, int val)
    {
        push(l, r, id);
        if (l > y || r < x) return;
        if (l >= x && r <= y)
        {
            t[id] = max(t[id], val);
            push(l, r, id);
            return;
        }
        update(l, mid, id*2, x, y, val);
        update(mid+1, r, id*2+1, x, y, val);
    }
    int get(int l, int r, int id, int x)
    {
        push(l, r, id);
        if (l == r) return t[id];
        if (x <= mid) return get(l, mid, id*2, x);
        else return get(mid+1, r, id*2+1, x);
    }
}t;
int n, D, a[N], b[N], rr[2*N], cur, lef[2*N], rig[2*N], dp[N][N], f[N];
int nxt[2][N][2*N];

void setup()
{
    cin >> n >> D;
    FOR(i, 1, n) cin >> a[i], rr[++cur] = a[i];
    FOR(i, 1, n) cin >> b[i], rr[++cur] = b[i];
    sort(rr+1, rr+cur+1);
    cur = unique(rr+1, rr+cur+1) - rr - 1;
    FOR(i, 1, n)
    {
        a[i] = lower_bound(rr+1, rr+cur+1, a[i]) - rr;
        b[i] = lower_bound(rr+1, rr+cur+1, b[i]) - rr;
    }
    FOR(i, 1, cur)
    {
        int x = rr[i] + D;
        rig[i] = upper_bound(rr+1, rr+cur+1, x) - rr - 1;
        x = rr[i] - D;
        lef[i] = lower_bound(rr+1, rr+cur+1, x) - rr;
    }
}
void prepare()
{
    FOR(i, 1, cur) nxt[0][n+1][i] = n+1, nxt[1][n+1][i] = n+1;
    FORD(i, n, 1)
    {
        FOR(j, 1, cur) nxt[0][i][j] = nxt[0][i+1][j];
        nxt[0][i][a[i]] = i;
    }
    FORD(i, n, 1)
    {
        FOR(j, 1, cur) nxt[1][i][j] = nxt[1][i+1][j];
        nxt[1][i][b[i]] = i;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("LIONDANCE.INP", "r", stdin);
    freopen("LIONDANCE.OUT", "w", stdout);
    setup();
    prepare();
    FORD(i, n, 1)
    {
        t.reset();
        FORD(j, n, 1)
        {
            if (a[i] == b[j])
                dp[i][j] = t.get(1, cur, 1, a[i]) + 1;
            t.update(1, cur, 1, lef[b[j]], rig[b[j]], f[j]);
        }
        FORD(j, n, 1)
            f[j] = max(f[j], dp[i][j]);
    }
    int res = 0;
    FOR(i, 1, n)
        FOR(j, 1, n) res = max(res, dp[i][j]);
    int pos1 = 1, pos2 = 1, pre;
    cout <<res<<'\n';
    while (res--)
    {
        FORD(i, cur, 1)
        {
            if (pos1 > 1)
            {
                if (abs(pre - rr[i]) > D) continue;
            }
            int u = nxt[0][pos1][i];
            int v = nxt[1][pos2][i];
            if (dp[u][v] == res+1)
            {
                cout <<rr[i]<<' ';
                pre = rr[i];
                pos1 = u+1;
                pos2 = v+1;
                break;
            }
        }
    }
}
