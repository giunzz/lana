#define Link ""

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>

#define TASK "ARRANGE"

using namespace std;

void OpenFile()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
}

const int maxn = 1e4 + 1;
int n,a[maxn];
long long s,cost[maxn],f[maxn][maxn];

void Enter()
{
    cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> a[i];
        s += a[i];
    }
}

void Init()
{
    s /= n;
    int d = 0;
    for (int i=1;i<n;++i) {
        if (a[i] >= s) {
            d += a[i] - s;
            a[i] -= a[i] - s;
        }
        else
            if (d >= s - a[i]) {
                d -= s - a[i];
                a[i] += s - a[i];
            }
            else {
                d = 0;
                a[i] += d;
            }
        cost[i] += d;
    }
    for (int i=n;i>=1;--i) {
        if (a[i] >= s) {
            d += a[i] - s;
            a[i] -= a[i] - s;
        }
        else
            if (d >= s - a[i]) {
                d -= s - a[i];
                a[i] += s - a[i];
            }
            else {
                d = 0;
                a[i] += d;
            }
        cost[i-1] -= d;
    }
}

void Solve()
{
    int D = -cost[0];
    for (int i=0;i<=n;++i)
        fill(f[i],f[i]+D+1,(long long)1e18);
    f[n][0] = 0;
    for (int i=n-1;i>=0;--i) {
        f[i][0] = f[i+1][0] + abs(cost[i] + 0);
        for (int s=1;s<=D;++s)
            f[i][s] = min(f[i+1][s] + abs(cost[i] + s), f[i+1][s-1] + abs(cost[i] + s - 1));
    }
    cout << f[1][D];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    OpenFile();

    Enter();
    Init();
    Solve();
}
