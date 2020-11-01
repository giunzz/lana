#include    <bits/stdc++.h>
#define     TITLE "MINSUM"
#define     ll long long
#define     up(k, n) for (int i = k ; i < n ; i ++)
const int maxT = (int) 1e6 + 7;

using namespace std;

bool a[maxT * 10]; ll T, A, B;

bool prime (long long n)
{
    if (n == 0 || n == 1) return false;
	for (int i = 2 ; i * i <= n ; i ++)
    if (n % i == 0) return false;
    return true;
}

void Sang (int n)
{
    fill_n(a, n + 1, true);
    a[1] = false;
    for (int i = 2 ; i <= sqrt(n) ; i ++)
    if (a[i] == true)
    for (int j = i * i ; j <= n ; j += i) a[j] = false;
}

ll div(ll x)
{
    ll t;
    up(2, x + 1)
    if (x % i == 0)
    {
        t = i;
        break;
    }
    return t;
}

void solve(ll x, ll y)
{
    ll t = __gcd(x, y);
    x /= t;
    y /= t;
    while(true)
    {
        if (a[x] && a[y] || (a[x] && y == 1) || (a[y] && x == 1) || (x == 1 && y == 1)) break;
        t = __gcd(x, y);
        if (t != 1) x /= t, y /= t;
        if (!a[x] && x != 1)
        {
            ll z = div(x);
            x /= z;
            y *= z;
        }
        else if (!a[y] && y != 1)
        {
            ll z = div(y);
            y /= z;
            x *= z;
        }
    }
    cout << x << ' ' << y << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    Sang(maxT * 10);
    cin >> T;
    up(0, T)
    {
        cin >> A >> B;
        solve(A, B);
    }
}
