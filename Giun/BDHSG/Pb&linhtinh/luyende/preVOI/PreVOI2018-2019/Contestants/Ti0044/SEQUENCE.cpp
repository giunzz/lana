#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SEQUENCE"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 3 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;

struct Z
{
    int x, y, v;
    pair<int, int> b;
    Z (){}
    Z (int X, int Y, pair<int, int> B, int V)
    {
        x = X; y = Y; b = B; v = V;
    }
};
int a[mm], mi1[mm][mm], mi2[mm][mm], b[mm], ok[mm][mm];
pair<int, int> tr[mm][mm];

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        if (!aNs) freopen(fn".out", "w", stdout);
		else freopen (fn".ans", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}

template <typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
void write (T a)
{
    if (a < 0)
    {
        putchar ('-');
        write (-a);
        return;
    }
    if (a < 10)
    {
        putchar ('0' + a);
        return;
    }
    write (a / 10);
    putchar ((char)('0' + (a % 10)));
}

void PreMin (int a[mm], int mi[mm][mm], int n)
{
    for (int i = 1; i <= n; ++ i)
    for (int j = i; j <= n; ++ j)
    mi[i][j] = ((i == j) ? i : (a[mi[i][j - 1]] <= a[j] ? mi[i][j - 1] : j));
}

void enter()
{
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++ i)
    cin >> a[i];
    for (int i = 1; i <= n; ++ i)
    cin >> b[i];
    PreMin (a, mi1, m);
    PreMin (b, mi2, n);
    vector<pair<int, int> > qu;
    qu.emplace_back(0, 0);
    for (int i = k; i >= 1; -- i)
    {
        vector<Z> v;
        int mi = INT_MAX;
        for (auto x : qu)
        {
            auto X = mi1[x.first + 1][min (m, m + n + 1 - i - x.second)];
            auto Y = mi2[x.second + 1][min (n, m + n + 1 - i - x.first)];
            if (!X)
            {
                v.emplace_back(x.first, Y, x, b[Y]);
                mi = min (mi, b[Y]);
                continue;
            }
            if (!Y)
            {
                v.emplace_back(X, x.second, x, a[X]);
                mi = min (mi, a[X]);
                continue;
            }
            if (a[X] < b[Y])
            {
                v.emplace_back(X, x.second, x, a[X]);
                mi = min (mi, a[X]);
            }
            else if (a[X] > b[Y])
            {
                v.emplace_back(x.first, Y, x, b[Y]);
                mi = min (mi, b[Y]);
            }
            else if (a[X] == b[Y])
            {
                v.emplace_back(X, x.second, x, a[X]);
                v.emplace_back(x.first, Y, x, b[Y]);
                mi = min (mi, a[X]);
            }
        }
        qu.clear();
        for (auto x : v)
        if (x.v == mi)
        {
            if (ok[x.x][x.y] == i) continue;
            ok[x.x][x.y] = i;
            qu.emplace_back (x.x, x.y);
            tr[x.x][x.y] = x.b;
        }
    }
    auto x = qu.back();
    // cerr << x.first << " " << x.second << "\n";
    vector<int> v;
    while (x.first || x.second)
    {
        auto r = tr[x.first][x.second];
        if (x.first == r.first) v.emplace_back(b[x.second]);
        else v.emplace_back(a[x.first]);
        x = r;
    }
    reverse (v.begin(), v.end());
    for (auto x : v)
    cout << x << " ";
}

void solve()
{

}

void print_result()
{

}

int main()
{
    docfile();
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}