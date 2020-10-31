#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 100015;

int n, m, tmp, res, k;
int a[2][N];
struct data
{
    vector <int> v;
};
data f[2];
void cal(int id, int n, int m)
{
    f[id].v.clear();
    int vt = 0, mi = 121512;
    int d = 0;
    while (m)
    {
        m--; mi = 121512;
        int d = vt + 1;
        for (int i = d; i <= (n - m); i++)
        {
            if (mi > a[id][i]) mi = a[id][i], vt = i;
        }
        f[id].v.push_back(a[id][vt]);
    }
}

void co(data a)
{
    cout << a.v.size() <<"\n";
    for (int i = 0; i < a.v.size(); i++) cout << a.v[i] <<" "; cout <<"\n";
}

int tn(data a, data b, int na, int nb)
{
    int i = 0;
    while (1)
    {
        if (na + i == a.v.size()) return 1;
        if (nb + i == b.v.size()) return 0;
        if (a.v[na + i] > b.v[nb + i]) return 1;
        if (a.v[na + i] < b.v[nb + i]) return 0;
        i++;
    }
}

data cmp(data a, data b)
{
    data res = a;
    if (a.v.size() < b.v.size()) return b;
    if (b.v.size() < a.v.size()) return a;
    for (int i = 0; i < a.v.size(); i++)
    {
        if (a.v[i] < b.v[i]) return a;
        if (b.v[i] < a.v[i]) return b;
    }
    return a;
}


void sub2()
{
    data ans, ss;
    ans.v.clear(); ss.v.clear();
    int s0 = 0, s1 = 0;
    for (int i = 0; i <= k; i++)
    {
        s0 = i, s1 = k - i;
        if (n < s0) continue;
        if (m < s1) continue;
        cal(0, n, s0); cal(1, m, s1);
        ss.v.clear();
        int d0 = 0, d1 = 0;
        while (ss.v.size() != k)
        {
            if (tn(f[0], f[1], d0, d1)) ss.v.push_back(f[1].v[d1]), d1++;
            else ss.v.push_back(f[0].v[d0]), d0++;
        }
        //co(ss);
        ans = cmp(ans, ss);
    }
    for (int i = 0; i < ans.v.size(); i++) cout << ans.v[i] <<" ";
    cout <<"\n";
}


const ll mod1 = 1e9 + 15;
const ll mod2 = 1e6 + 12;
int na, nb;
ll ha1[5][N], ha2[5][N];
data RES, ss;

bool check(int x, int u, int l)
{
    x++, u++;
    for (int i = 1; i <= 4; i++)
    {
        ll ss = ha1[i][x + l - 1] - ha1[i][x - 1];
        ll an = ha2[i][u + l - 1] - ha2[i][u - 1];
        if (ss != an) return false;
    }
    return true;
}
int kt(data a, data b, int x, int u)
{
    int res = 0;
    int l = 1, r = min(na - x, nb - u);
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(x, u, mid)) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    if (x + res == na) return 1;
    if (u + res == nb) return 0;
    if (a.v[x + res] > b.v[u + res]) return 1;
    else return 0;
}

void uni(data a, data b)
{
    //co(a);co(b);
    na = a.v.size();
    nb = b.v.size();
    ss.v.clear();
    for (int i = 1; i <= na; i++)
    {
        ha1[1][i] = (ha1[1][i - 1] + 1LL*a.v[i - 1] % mod1) % mod1;
        ha1[2][i] = (ha1[2][i - 1] + 1LL*a.v[i - 1] % mod2) % mod2;
        ha1[3][i] = (ha1[3][i - 1] + 1LL*a.v[i - 1] * 1LL*a.v[i] % mod1) % mod1;
        ha1[4][i] = (ha1[4][i - 1] + 1LL*a.v[i - 1] * 1LL*a.v[i] % mod2) % mod2;
    }
    for (int i = 1; i <= nb; i++)
    {
        ha2[1][i] = (ha2[1][i - 1] + 1LL*b.v[i - 1] % mod1) % mod1;
        ha2[2][i] = (ha2[2][i - 1] + 1LL*b.v[i - 1] % mod2) % mod2;
        ha2[3][i] = (ha2[3][i - 1] + 1LL*b.v[i - 1] * 1LL*b.v[i] % mod1) % mod1;
        ha2[4][i] = (ha1[4][i - 1] + 1LL*b.v[i - 1] * 1LL*b.v[i] % mod2) % mod2;
    }
    int d0 = 0, d1 = 0;
    //cout << kt(a, b, d0, d1) <<"\n";
    while (ss.v.size() != k)
    {
        if (kt(a, b, d0, d1)) ss.v.push_back(b.v[d1]), d1++;
        else ss.v.push_back(a.v[d0]), d0++;
    }
    RES = cmp(RES, ss);
    //co(ss);
}



int main()
{
    #define file "SEQUENCE"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[0][i];
    for (int i = 1; i <= m; i++) cin >> a[1][i];
    if (n <= 100 && m <= 100) return sub2(), 0;
    RES.v.clear();
    for (int i = 0; i <= k; i++)
    {
        int s0 = i, s1 = k - s0;
        if (s0 > n) continue;
        if (s1 > m) continue;
        cal(0, n, s0); cal(1, m, s1);
        uni(f[0], f[1]);
    }
    for (int i = 0; i < RES.v.size(); i++) cout << RES.v[i] <<" ";

    return 0;
}
