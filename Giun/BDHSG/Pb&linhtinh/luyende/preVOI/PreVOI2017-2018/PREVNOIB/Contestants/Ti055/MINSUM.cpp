#include<bits/stdc++.h>

using namespace std;

long long A, B, tes, res, t, p, k, ans1, ans2, Test;

int main()
{
    freopen("MINSUM.INP", "r", stdin);
    freopen("MINSUM.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> Test;
    for (int te = 1; te <= Test; te++)
    {
        cin >> A >> B;
        tes = A*B;
        res = 1e9 + 7;
        for (int i = 1; i <= tes; i++)
        {
            if (tes % i == 0)
            {
                t = i;
                p = tes / i;
                k = __gcd(t, p);
                t = t / k;
                p = p / k;
                if (res > (t + p))
                {
                    res = t + p;
                    ans1 = t;
                    ans2 = p;
                }
            }
        }
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
