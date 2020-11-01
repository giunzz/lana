/*******************THACH THAO*******************/

#include <bits/stdc++.h>
#define maxn 1000007
#define maxC 1000000007
#define Task "MINSUM"
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define F first
#define S second

using namespace std;

int T, a, b;
int dd[maxn];

void setup()
{
    cin >> T;
}

void prepare()
{
    for (int i = 2; i <= maxn; ++i)
        if (dd[i] == 0)
        {
            for (int j = i + i; j <= maxn; j += i)
                dd[j] = 1;
        }
}

void solve()
{
    while (T--)
    {
        cin >> a >> b;
        int x = __gcd(a, b);
        a /= x;
        b /= x;
        if (dd[a] && dd[b]) cout << a << " " << b << "\n";
        else
        {
            int k1 = sqrt(a);
            int k2 = sqrt(b);
            for (int i = k1; i > 1; --i) if (a % (i * i) == 0) while (a % (i * i) == 0) {a /= (i * i);}
            for (int i = k2; i > 1; --i) if (b % (i * i) == 0) while (b % (i * i) == 0) {b /= (i * i);}
            if (dd[a] && dd[b]) cout << a << " " << b << "\n";
                else
                {
                    int sum = a + b;
                    for (int i = k1; i > 1; --i) if (a % i == 0 && (a / i + b * i < sum)) a /= i, b *= i, sum = a + b;
                    for (int i = k2; i > 1; --i) if (b % i == 0 && (a * i + b / i < sum)) a *= i, b /= i, sum = a + b;
                    cout << a << " " << b << "\n";
                }
        }
    }
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
