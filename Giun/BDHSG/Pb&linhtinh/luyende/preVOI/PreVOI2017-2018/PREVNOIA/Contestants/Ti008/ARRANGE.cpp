#include <bits/stdc++.h>
using namespace std;

#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));


const long long N = 1e5 + 10;
const long long INF = 1e18 + 7;
long long n;
long long sum = 0;
long long a[N];

bool minimize (long long &a, long long b)
{
    if (a > b) a = b; else return false;
    return true;
}

namespace sub1
{
    void solve ()
    {
        long long x = sum / n;
        long long ret = 0;
        for (long long i = 1; i <= n; i++)
        {
            if (a[i] == x) continue;
            if (a[i] < x)
            {
                long long need = x - a[i];
                ret += need;
                if (a[i + 1] < need)
                {
                    ret += need - a[i + 1];
                }
                a[i + 1] = max(0LL, a[i + 1] - need);
                a[i] = x;
            }
            else if (a[i] > x)
            {
                a[i + 1] += (a[i] - x);
                ret += a[i] - x;
                a[i] = x;
            }
        }
        cout << ret;
    }
}

namespace sub2
{

    const long long NSECOND = 2005;
    long long x, y;
    long long f[NSECOND];
    long long t[N];
    long long opt[N];
    long long calc (long long n, long long t[], long long opt[])
    {
        //cout << n << endl;
        //for (int i = 1; i <= n; i++) cout << t[i] << " "; cout << endl;
        //for (int i = 1; i <= n; i++) cout << opt[i] << " "; cout << endl;
        long long ret = 0;
        for (long long i = 1; i <= n; i++)
        {
            if (t[i] == opt[i]) continue;
            if (t[i] < opt[i])
            {
                long long need = opt[i] - t[i];
                ret += need;
                if (t[i + 1] < need)
                {
                    ret += need - t[i + 1];
                }
                t[i + 1] = max(0LL, t[i + 1] - need);
                t[i] = opt[i];
            }
            else if (t[i] > opt[i])
            {
                t[i + 1] += (t[i] - opt[i]);
                ret += t[i] - opt[i];
                t[i] = opt[i];
            }
        }
        //cout << ret << endl;
        //cout << endl;
        return ret;
    }
    long long cost (long long l, long long r)
    {
        long long sum = 0;
        for (int i = l; i <= r; i++)
        {
            t[i - l + 1] = a[i];
            sum += a[i];
        }
        long long ret = INF;
        if (sum > y * (r - l + 1) || sum < x * (r - l + 1))
            return ret;

        long long cy = sum % (r - l + 1);
        long long cx = (r - l + 1) - cy;
        for (int i = 1; i <= cx; i++)
            opt[i] = x;
        for (int i = cx + 1; i <= (r - l + 1); i++)
            opt[i] = y;
        ret = min(ret, calc(r - l + 1, t, opt));
        for (int i = l; i <= r; i++)
            t[i - l + 1] = a[i];
        for (int i = 1; i <= cy; i++)
            opt[i] = y;
        for (int i = cx + 1; i <= (r - l + 1); i++)
            opt[i] = x;
        ret = min(ret, calc(r - l + 1, t, opt));
        return ret;
    }

    void solve ()
    {
        f[0] = 0;
        x = sum / n;
        y = x + 1;
        for (int i = 1; i <= n; i++)
        {
            f[i] = INF;
            for (int p = 0; p < i; p++)
                f[i] = min(f[i], f[p] + cost(p + 1, i));
        }

        cout << f[n];
    }

}


int main()
{
    #define file "ARRANGE"
    freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n == 0)
    {
        sub1 :: solve();
        return 0;
    }
    sub2 :: solve();
    return 0;
}

