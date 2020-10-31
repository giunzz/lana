#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 1e6 + 1;

int n, k, A[maxn+1];
ll S[maxn+1], L[maxn+1], R[maxn+1], ans;

/*void trau()
{
    for (int i=1; i<=n; i++) cin >> A[i], S[i] = S[i-1] + A[i];
    for (int i=1; i<=n; i++) L[i] = max(L[i-1], S[i] - S[max(0, i-k)]);
    for (int i=n; i>=1; i--) R[i] = max(R[i+1], S[min(n, i+k-1)] - S[i-1]);
    ans = 1e18;
    for (int l=1; l<=n; l++)
        for (int r=l; r<=min(n, l+k-1); r++)
        {
            ll mid = S[r] - S[l-1];
            if (mid >= L[l-1] && mid >= R[r+1]) ans = min(ans, mid);
        }
    cout << ans;
    exit(0);
}*/

int main()
{
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> A[i], S[i] = S[i-1] + A[i];
    for (int i=1; i<=n; i++) L[i] = max(L[i-1], S[i] - S[max(0, i-k)]);
    for (int i=n; i>=1; i--) R[i] = max(R[i+1], S[min(n, i+k-1)] - S[i-1]);
    int r = 0;
    ans = 1e18;
    for (int l=1; l<=n; l++)
    {
        while (r+1 <= n && r-l+2 <= k && (S[r+1] - S[l-1] < L[l-1] || S[r+1] - S[l-1] < R[r+2])) r++;
        if (r+1 > n || r-l+2 > k) continue;
        r++;
        if (S[r] - S[l-1] >= L[l-1] && S[r] - S[l-1] >= R[r+1]) ans = min(ans, S[r] - S[l-1]);
        r--;
    }
    cout << ans;
    return 0;
}
