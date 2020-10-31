#include    <bits/stdc++.h>
#define     TITLE "TEAWORLD"
#define     ll long long
#define     up(k, n) for (int i = k ; i < n ; i ++)
#define     down(k, n) for (int i = k ; i >= n ; i --)
const int maxN = (int) 1e4 + 7;

using namespace std;

struct ii
{
    int X, Y, Z, R;
    char T;
} a[maxN];

int m, n, k, t, start, finish, ans = 0; static int sum[1007], dd[1007], gate[1007]; bool chk = true;

bool cmp(ii a, ii b)
{
    return a.X < b.X;
}

void solve()
{
    if (start - 1 < 0) ans = sum[finish];
    else ans = sum[finish] - sum[start - 1];
    while (finish <= 1000)
    {
        finish ++;
        if (dd[finish] == 1)
        {
            if (gate[finish] < start) t ++;
        }
        else if (dd[finish] == -1) t ++;
        while (t > k)
        {
            while (dd[start] != 1) start ++;
            while (dd[start] == 1)
            {
                start ++;
                t --;
                if (t == k) break;
            }
        }
        ans = max(ans, sum[finish] - sum[start - 1]);
    }
    cout << ans;
}

void sub1()
{
    up(m, m + n) sum[a[i].X + 500] = a[i].R;
    up(1, 1007) sum[i] += sum[i - 1];
    up(0, m)
    {
        int dx = a[i].X + a[i].R + 500;
        int dy = a[i].X - a[i].R + 500;
        if (dx < 0) dx = 0;
        if (dx > 1000) dx = 1000;
        dd[dx] = -1;
        dd[dy] = 1;
        gate[dy] = dx;
    }
    start = 0;
    down(a[m + n].X + 500, 0)
    {
        if (dd[i] == -1) t ++;
        if (t == k)
        {
            while (dd[i] != 1) i --;
            while (dd[i] == 1) i ++;
            start = i;
        }
    }
    finish = a[m + n].Y + 500;
    if (finish > 1000) finish = 1000;
    solve();
}

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    scanf("%d%d%d", &m, &n, &k);
    up(0, m)
    {
        scanf("%d%d%d%d", &a[i].X, &a[i].Y, &a[i].Z, &a[i].R);
        a[i].T = 'C';
        if (a[i].Y != 0 || a[i].Z != 0) chk = false;
    }
    up(m, m + n)
    {
        scanf("%d%d%d%d", &a[i].X, &a[i].Y, &a[i].Z, &a[i].R);
        a[i].T = 'S';
        if (a[i].Y != 0 || a[i].Z != 0) chk = false;
    }
    scanf("%d%d%d", &a[m + n].X, &a[m + n].Y, &a[m + n].Z);
    a[m + n].T = 'X';
    if (chk) sub1();
}

int main()
{
    Input();

}
