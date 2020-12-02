https://codeforces.com/problemset/problem/1455/D
#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
int main()
{
    giuncute;
	freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        if (is_sorted(a.begin(),a.end())) cout << 0 << endl , continue;


        vector<vector<int>> dp(n, vector<int>(501, int(1e9)));
        for(int i = 0; i < n; i++)
        {
            cerr << a[i];

            if(a[i] > x && (i == 0 || a[i - 1] <= x)) dp[i][x] = 1;
            if(i < n - 1 && a[i] > a[i + 1]) break;
        }
        int ans = int(1e9);
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= 500; j++)
            {
                if(dp[i][j] == int(1e9))
                    continue;
                if(i == n || (j <= a[i + 1] && is_sorted(a.begin() + i + 1, a.end())))
                    ans = min(ans, dp[i][j]);
                bool ok = true;
                for(int k = i + 1; k < n; k++)
                {
                    int pr = k == i + 1 ? j : a[k - 1];
                    if(ok && a[i] >= pr && a[i] < a[k])
                        dp[k][a[i]] = min(dp[k][a[i]], dp[i][j] + 1);
                    ok &= a[k] >= pr;
                }
            }
        if(ans == int(1e9))ans = -1;
        cout << ans << endl;

    }


