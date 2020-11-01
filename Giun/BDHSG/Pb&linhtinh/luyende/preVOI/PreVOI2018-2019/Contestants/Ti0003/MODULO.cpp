#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 1500012;

ll n, A, B, m, tmp, res, k, n1, num;
string s;
struct data
{
    ll gt;
    string s;
};
data a[N];

bool cmp(data a, data b)
{
    return a.gt < b.gt;
}

int get(int x, int i)
{
    return (x >> i) & 1;
}

ll mul(ll x, ll y, ll mod)
{
    if (y == 1) return x % mod;
    ll res = mul(x, y / 2, mod);
    res = (res + res) % mod;
    if (y % 2 == 1) res = (res + x) % mod;
    return res;
}

int tk(ll x)
{
    int l = 1, r = num;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (a[mid].gt == x) return mid;
        if (a[mid].gt > x) r = mid - 1;
        else l = mid + 1;
    }

    return -1;
}

void sub2()
{
    ll mod = 1;
    for (int i = 1; i <= n; i++) mod = mod * 2LL;
    n1 = n/2;
    for (int mask = 0; mask < (1 << n1); mask++)
    {
        num++;
        a[num].gt = 0, a[num].s = "";
        for (int j = 0; j < n1; j++)
        {
            a[num].gt = (a[num].gt * 10) % mod;
            if (get(mask, j)) a[num].gt = (a[num].gt + A) % mod, a[num].s = a[num].s + char(A + 48);
            else a[num].gt = (a[num].gt + B) % mod, a[num].s = a[num].s + char(B + 48);
        }
        //cout << num <<" "<< mask <<" "<< a[num].gt <<" "<< a[num].s <<"\n";
    }
    n1 = n - n1;
    tmp = 1;
    for (int i = 1; i <= n1; i++)
        tmp = tmp * 10 % mod;
    for (int i = 1; i <= num; i++)
        a[i].gt = mul(a[i].gt, tmp, mod);
    sort(a + 1, a + 1 + num, cmp);
    for (int mask = 0; mask < (1 << n1); mask++)
    {
        ll gt = 0;
        s = "";
        for (int j = 0; j < n1; j++)
        {
            gt = (gt * 10) % mod;
            if (get(mask, j)) gt = (gt + A) % mod, s = s + char(A + 48);
            else gt = (gt + B) % mod, s = s + char(B + 48);
        }
        ll ss = (k + mod - gt) % mod;
        int id = tk(ss);
        //cout << mask <<" "<< gt <<" "<< s <<" "<< ss <<"\n";
        if (id != -1)
        {
            cout << a[id].s << s;
            return;
        }
        //cout << num <<" "<< mask <<" "<< a[num].gt <<" "<< a[num].s <<"\n";
    }
    cout << -1 <<"\n";
}

int main()
{
    #define file "MODULO"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> A >> B;
    cin >> n >> k;
    if (n <= 40) return sub2(), 0;
    cout << -1;

    return 0;
}
