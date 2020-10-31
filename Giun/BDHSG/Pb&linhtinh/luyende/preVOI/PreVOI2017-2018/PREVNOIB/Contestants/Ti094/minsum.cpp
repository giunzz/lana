#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define task "minsum"
#define N 1000001
int t, a, b;

void sub1()
{
    int u = a, v = b;
    int ok = 0,x, y;
    while (ok == 0)
        {
            int s = __gcd(u,v);
            int d, typ = 0;
            for(int i=2; i<=sqrt(u); i++)
                if (a % i == 0)
                    {
                        int x = __gcd(u/i, v*i);
                        if (x > s)
                        {
                            s = x;
                            d = i;
                            typ = 1;
                        }
                    }
            for(int i=2; i<=sqrt(v); i++)
                if (b % i == 0)
                    {
                        int x = __gcd(u*i, v/i);
                        if (x > s)
                        {
                            s = x;
                            d = i;
                            typ = 2;
                        }
                    }
            if (typ == 0) ok = 1;
            else
            {
                if (typ == 1) u /= d, v *= d;
                else u *= d, v/= d;
            }
            x = u / s;
            y  = v / s;
        }
    cout << x << " " << y << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> t;
    while (t --)
    {
        cin >> a >> b;
        sub1();
    }
    return 0;
}
