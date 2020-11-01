#include <bits/stdc++.h>

#define fn "test"
#define fn1 "ICECREAM"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 9;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
unordered_map<long long, int> f;
int n, MMAX;

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
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

inline int mo (int x)
{
    return (x < mod ? x : x - mod);
}

int F (int a, int b, int c, int n)
{
    if (max (a, max (b, c)) > MMAX) return 0;
    if (min (a, min (b, c)) < 0) return 0;
    if (!n) return 1;
    long long d = 1ll * a * (MMAX + 1) * (MMAX + 1) * 301 + 1ll * b * (MMAX + 1) * 301 + c * 301 + n;
    if (f.count (d)) return f[d];
    return f[d] = mo (mo (F (a + 1, b, c, n - 1) + F (a - 1, b + 1, c, n - 1)) + mo (F (a - 3, b, c + 1, n - 1) + F (a - 1, b - 1, c + 1, n - 1)));
}

void enter()
{
    cin >> n >> MMAX;
    int a, b, c;
    cin >> a >> b >> c;
    cout << F (a, b, c, n);
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