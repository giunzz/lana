#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 10005
#define maxn 100005
#define maxc 1ll*1000000000000000007

using namespace std;

int n;
ll a[maxn];
ll s[maxn], S, M1, M2, dp[N][N];

void setup()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i-1] + a[i];
    S = s[n];
    M1 = S / n;
    M2 = S % n;
}

ll get(int x, int y)
{
    ll ans = s[x] - (M1+1)*y - M1*(x-y);
    return abs(ans);
}
void sub2()
{
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= n+1; j++) dp[i][j] = maxc;
    dp[0][0] = 0;
    for (int i = 1; i <= n+1; i++)
        for (int j = 0; j <= min(1ll*i-1, M2); j++)
        {
            dp[i][j] = dp[i-1][j] + get(i-1, j);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + get(i-1, j));
        }
    cout <<dp[n+1][M2];
}

void sub1()
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == M1) continue;
        if (a[i] < M1)
        {
            a[i+1] -= (M1 - a[i]);
            res += M1 - a[i];
        }
        else if (a[i] > M1)
        {
            a[i+1] += (a[i] - M1);
            res += a[i] - M1;
        }
    }
    cout <<res;
}
void TryYourBest()
{
    ll res = 0; ll y = 0;
    for (int x = 1; x <= n; x++)
    {
        if (abs(s[x] - M1*x - y) > abs(s[x] - M1*x - y - 1) && y < M2) y++;
        res += abs(s[x] - M1*x - y);
    }
    cout <<res;
}
void solve()
{
    if (S % n == 0) sub1();
    else if (n < N) sub2();
    else TryYourBest();
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ARRANGE.INP", "r", stdin);
    freopen("ARRANGE.OUT", "w", stdout);
    setup();
    solve();
}
