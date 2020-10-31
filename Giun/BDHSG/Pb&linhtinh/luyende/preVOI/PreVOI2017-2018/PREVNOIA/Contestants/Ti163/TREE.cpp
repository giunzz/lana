/*******************THACH THAO*******************/

#include <bits/stdc++.h>
#define maxn 5007
#define maxC 1000000007
#define Task "TREE"
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define F first
#define S second

using namespace std;

int n, ans = 0, q = 0;
int a[maxn], b[maxn], save[maxn], in[maxn], out[maxn], tr[maxn], ch[2][maxn];
bool dd[maxn];

void setup()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
        save[i] = a[i];
    }
    int x, y;
    for (int i = 1; i < n; ++i)
    {
        cin >> x >> y;
        tr[y] = x;
        if (ch[0][x] != 0) ch[1][x] = y;
            else ch[0][x] = y;
    }
}

void DFS(int u)
{
    dd[u] = true;
    in[u] = ++q;
    for (int i = 0; i < 2; ++i)
    {
        int v = ch[i][u];
        if (dd[v] == true || v == 0) continue;
        DFS(v);
    }
    out[u] = q;
}

int Check(int id, int val)
{
    int res = abs(a[id] - val);
    b[id] = val;
    id = tr[id];
    while (id != 1)
    {
        b[id] = b[ch[0][id]] + b[ch[1][id]];
        res += abs(a[id] - b[id]);
        id = tr[id];
    }
    b[1] = b[ch[0][1]] + b[ch[1][1]];
    res += abs(a[1] - b[1]);
    return res;
}

void Update(int id, int val)
{
    a[id] = val;
}

void Update()
{
    for (int i = 1; i <= n; ++i)
        if (dd[i] == false)
        {
            int id = tr[i];
            while (id != 1)
            {
                a[id] = a[ch[0][id]] + a[ch[1][id]];
                id = tr[id];
            }
            a[1] = a[ch[0][1]] + a[ch[1][1]];
        }
}

void solve()
{
    DFS(1);
    for (int i = 1; i <= n; ++i)
        if (in[i] == out[i]) dd[i] = false;
    for (int i = 1; i <= n; ++i)
        if (dd[i] == false)
        {
            int res1 = Check(i, 0);
            int res2 = Check(i, 1);
            if (res1 < res2) a[i] = 0;
                else a[i] = 1;
        }
    Update();
    for (int i = 1; i <= n; ++i)
        ans += abs(save[i] - a[i]);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
    setup();
    solve();
    return 0;
}
