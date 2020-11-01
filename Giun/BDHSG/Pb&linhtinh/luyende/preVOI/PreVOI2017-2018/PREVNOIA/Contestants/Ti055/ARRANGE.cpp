#include<bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef pair<int, long long> ii;
const int maxN = 1e5 + 7;
long long n, res, a[maxN], sum;
ii b[maxN];

bool ccw(ii O, ii A, ii B)
{
    A.f = A.f - O.f;     A.s = A.s - O.s;
    B.f = B.f - O.f;     B.s = B.s - O.s;
    return A.f*B.s > A.s*B.f;
}

int main()
{
    freopen("ARRANGE.INP", "r", stdin);
    freopen("ARRANGE.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum = sum + a[i];
    }
    if (sum % n == 0)
    {
        sum = sum / n;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == sum)    continue;
            if (a[i] > sum)
            {
                int t = a[i] - sum;
                for (int j = i + 1; j <= n; j++)
                    if (a[j] < sum)
                    {
                        int x = sum - a[j];
                        int k = min(x, t);
                        t = t - k;
                        res = res + (j - i)*k;
                        if (t == 0) break;
                    }
            }
            else    if (a[i] < sum)
            {
                int t = sum - a[i];
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > sum)
                    {
                        int x = a[j] - sum;
                        int k = min(x, t);
                        a[j] -= k;
                        t -= k;
                        res = res + k*(j - i);
                        if (t == 0) break;
                    }
                }
            }
        }
        cout << res;
        exit(0);
    }
    for (int i = 1; i <= n; i++)
    {
        b[i].s = b[i - 1].s + a[i];
        b[i].f = i;
    }
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        while (j >= 2 && !ccw(b[j - 2], b[j - 1], b[i]))
        {
            long long tes = 0;
            tes += (b[j - 1].f - b[j - 2].f)*(b[j - 1].s + b[j - 2].s);
            tes += (b[i].f - b[j - 1].f)*(b[i].s + b[j - 1].s);
            tes += (b[j - 2].f - b[i].f)*(b[j - 2].s + b[i].s);
            res = res + abs(tes);
            j--;
        }
        b[j++] = b[i];
    }
    cout << res/2;
    return 0;
}
