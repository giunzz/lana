#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 4007;

int n, m, a[maxn], b[maxn], k;
int dp[maxn][maxn];
int pos[maxn];
pair<int, int> maxcnt[maxn];
pair<int, int> Trace[maxn][maxn];
vector<int> vt;

void trace(int hihi, int haha)
{
    cout << a[hihi] << ' ';
    if(Trace[hihi][haha].first > 0) trace(Trace[hihi][haha].first, Trace[hihi][haha].second);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("liondance.inp", "r", stdin);
    freopen("liondance.out", "w", stdout);
    cin >> n >> k;
    for(int i = n; i >= 1; i--) cin >> a[i];
    for(int i = n; i >= 1; i--) cin >> b[i];
    for(int i = 1; i <= n; i++)
    {
        int oldcnt = -1, oldj = -1, oldi = -1;
        for(int j = 1; j <= n; j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = oldcnt + 1;
                Trace[i][j] = {oldi, oldj};
            }
            if(abs(a[i] - b[j]) <= k)
            {
                if(oldcnt < maxcnt[j].first)
                {
                    oldcnt = maxcnt[j].first;
                    oldi = maxcnt[j].second;
                    oldj = j;
                }
                else if(oldcnt == maxcnt[j].first && a[oldi] < a[maxcnt[j].second])
                {
                    oldcnt = maxcnt[j].first;
                    oldi = maxcnt[j].second;
                    oldj = j;
                }
            }
        }
        for(int j = 1; j <= n; j++)
        {
            if(a[i] == b[j]) maxcnt[j] = max(maxcnt[j], {dp[i][j], i});
        }
    }
    pair<int, int> ans = {-1, -1};
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i] != b[j]) continue;
            if(ans.first == -1 || dp[ans.first][ans.second] < dp[i][j] || a[ans.first] <= a[i])
            {
                ans = {i, j};
            }
        }
    }
    cout << dp[ans.first][ans.second] + 1 << '\n';
    trace(ans.first, ans.second);
}
