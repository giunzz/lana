#define task "MODULO"
#include <bits/stdc++.h>
using namespace std;

int a[3], n, cnt;
long long k, s = 1, t;
bool ch;

void atp (int x)
{
    if (t % s == k && cnt == n)
    {
        cout << t;
        ch = 1;
        return;
    }
    for (int i = 1; i <= 2 && cnt <= n; i++)
    {
        t = t * 10 + a[i];
        cnt++;
        if (ch == 1) break;
        atp(x + 1);
        t /= 10; cnt--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    cin >> a[1] >> a[2] >> n >> k;
    for (int i = 1; i <= n; i++)
        s *= 2;
    atp (1);
    if (!ch) cout << -1;
}
