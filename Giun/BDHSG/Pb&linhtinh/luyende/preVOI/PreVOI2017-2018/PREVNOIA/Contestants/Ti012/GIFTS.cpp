#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 1000005
#define Task "GIFTS"
using namespace std;
int n,k,a[maxn];
long long sum[maxn],sur[maxn],pre[maxn],ans = 1ll*maxc*maxc,temp;
bool check1(int i)
{
    if (i <= k) return 1;
    return temp >= pre[i-1];
}
bool check2(int i)
{
    if ( i > n - 2*k + 1) return 1;
    return temp >= sur[i+k];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    cin >> n >> k;
    FOR(i,1,n) cin >> a[i],sum[i] = sum[i-1] + a[i];
    FOR(i,k,n) pre[i] = max(pre[i-1],sum[i] - sum[i-k]);
    FORD(i,n-k+1,1) sur[i] = max(sur[i+1],sum[i+k-1] - sum[i-1]);
    FOR(i,1,n-k+1)
    {
        temp = sum[i+k-1] - sum[i-1];
        if (check1(i) && check2(i)) ans = min(ans,temp);
    }
    cout << ans;
    return 0;
}
