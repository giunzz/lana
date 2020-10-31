#include <bits/stdc++.h>

#define fn "test"
#define fn1 "MODULO"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int a, b, n, k;
int tr[30];

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

void attemp (int id, long long r)
{
    if (id == n)
    {
        if (r == k)
        {
            for (int j = 0; j < n; ++ j)
            if (!tr[j])
            cout << a;
            else 
            cout << b;
            exit (0);
        }
        return;
    }
    for (int j = 0; j < 2; ++ j)
    {
        tr[id] = j;
        if (!j)
        attemp  (id + 1, (r * 10 + a) % (1ll << n));
        else
        attemp (id + 1, (r * 10 + b) % (1ll << n));
    }
}

void enter()
{
    cin >> a >> b >> n >> k;
    if (n <= 20)
    attemp (0, 0);
    cout << - 1;
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