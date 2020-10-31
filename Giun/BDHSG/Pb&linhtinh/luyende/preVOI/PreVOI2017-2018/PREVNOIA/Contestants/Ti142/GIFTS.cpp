#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1ll*1000000000000000007

using namespace std;

int n, k, a[N];
long long s[N], lef[N], rig[N], res = maxc;

long long get(int l, int r)
{
    return s[r] - s[l-1];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    for (int i = k; i <= n; i++)
        lef[i] = max(lef[i-1], get(i-k+1, i));
    for (int i = n-k+1; i >= 1; i--)
        rig[i] = max(rig[i+1], get(i, i+k-1));
    for (int i = 1; i <= n-k+1; i++)
    {
        long long ans = max(lef[i-1], rig[i+k]);
        res = min(res, ans);
    }
    cout <<res;
}
