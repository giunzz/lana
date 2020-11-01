#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 1e5;
int n, A[maxn+1], Ok[maxn+1], X[maxn+1], k, B[maxn+1];
ll Sum, ans;

void Solve1()
{
    ll carry = 0;
    for (int i=1; i<=n; i++)
    {
        ans += carry;
        if (A[i] >= carry) A[i] -= carry, carry = 0;
        else A[i] = 0, carry -= A[i];
        if (A[i] < Sum/n) carry += Sum/n - A[i];
        if (A[i] > Sum/n) A[i+1] += A[i] - Sum/n, ans += A[i] - Sum/n;
    }
    cout << ans;
    exit(0);
}

void Solve()
{
    for (int i=1; i<=n; i++) B[i] = A[i];
    ll carry = 0, res = 0;
    for (int i=1; i<=n; i++)
    {
        res += carry;
        if (B[i] >= carry) B[i] -= carry, carry = 0;
        else B[i] = 0, carry -= B[i];
        if (B[i] < Sum/n + Ok[i]) carry += Sum/n + Ok[i] - B[i];
        if (B[i] > Sum/n + Ok[i]) B[i+1] += B[i] - Sum/n - Ok[i], res += B[i] - Sum/n - Ok[i];
    }
    ans = min(ans, res);
}

void Back(int i)
{
    for (int j=X[i-1]+1; j<=n; j++)
    {
        X[i] = j;
        Ok[j] = 1;
        if (i == k) Solve();
        else Back(i+1);
        Ok[j] = 0;
    }
}

int main()
{
    freopen("ARRANGE.INP", "r", stdin);
    freopen("ARRANGE.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> A[i], Sum += A[i];
    if (Sum % n == 0) Solve1();

    ans = 1e18;
    k = Sum % n;
    Back(1);
    cout << ans;
    return 0;
}
