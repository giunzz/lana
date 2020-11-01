#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define pb push_back

const int maxn = 50004;

int t;
int d[maxn];
bool dd[maxn];
vector <int> p;

int increase(int i)
{
    if (i%6 == 1) return i + 4;

    return i + 2;
}

void Eratosthenes(int limit)
{
    for (int i = 5; i <= limit; i = increase(i))
        dd[i] = true;

    int i = 5, nn = sqrt(limit);

    for (; i <= nn; i = increase(i))
    {
        if (dd[i])
        {
            int j = i * i, ii = i;
            for (; j <= limit;)
            {
                dd[j] = false;
                ii = increase(ii);
                j = ii * i;
            }
        }
    }

    p.pb(2); p.pb(3);

    for (int i = 5; i <= limit; i = increase(i))
        if (dd[i]) p.pb(i);
}

int gcd(int a, int b)
{
    for (; b;)
    {
        int r = a%b;
        a = b;
        b = r;
    }

    return a;
}

void inp_out()
{
    Eratosthenes(maxn);

    cin >> t;

    for (; t; --t)
    {
        fill (d, d + maxn, 0);
        int a, b;
        cin >> a >> b;
        int r = gcd(a, b);
        a /= r;
        b /= r;
        for (int i = 0; i < p.size(); ++i)
        {
            while (a%p[i] == 0) { ++d[p[i]]; a /= p[i];}
            while (b%p[i] == 0) { --d[p[i]]; b /= p[i];}
            if (d[p[i]] < 0 && abs(d[p[i]])%2) b *= p[i];
            else if (d[p[i]] > 0 && d[p[i]]%2) a *= p[i];
        }
        cout << a << ' ' << b << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("MINSUM.inp", "r", stdin);
    freopen("MINSUM.out", "w", stdout);

    inp_out();

    return 0;
}
