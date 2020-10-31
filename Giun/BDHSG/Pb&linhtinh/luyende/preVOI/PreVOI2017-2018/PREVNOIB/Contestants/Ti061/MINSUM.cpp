#include <bits/stdc++.h>
#define maxn 1000005
#define maxC 1000000007
#define Reset(d, a) memset(d, a, sizeof(d))
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define Length(a) int(a.length())
#define Size(a) int(a.size())
#define F first
#define S second
#define Task "MINSUM"

using namespace std;

int T, a, b, c, d;

int Process()
{
    FOR(i, 2, sqrt(c))
    {
        int num = 0;
        while (c % i == 0)
        {
            num++;
            c /= i;
            if ((num & 1) == 0) d /= i * i;
        }
    }
    return d;
    //cout << d << " ";
}

void Operate()
{
    d = __gcd(a, b);
    a /= d;
    b /= d;

    c = d = a;
    int x = Process();
    c = d = b;
    int y = Process();
    cout << x << " " << y << '\n';
}

void Setup()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        Operate();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    Setup();
}
