#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a); i <= (b); i ++)
#define FORd(i, a, b) for(int i = (a); i >= (b); i --)
#define FORv(i, a, b) for(int i = (a); i < (b); i ++)
#define II pair<int, int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 1e6 + 69;
ll n, k, a[maxn], sum[maxn], fl[maxn], fr[maxn], res = 1e18;
int main()
{
    freopen("GIFTS.inp", "r", stdin);
    freopen("GIFTS.out", "w", stdout);
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%lld%lld", &n, &k);
    FOR(i, 1, n){
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    FOR(i, k, n){
        fl[i] = max(fl[i - 1], sum[i] - sum[i - k]);
      //  cout << fl[i] << ' ';
    }
   // cout << endl;
    FORd(i, n - k + 1, 1){
        fr[i] = max(fr[i + 1], sum[i + k - 1] - sum[i - 1]);
     //   cout << fr[i] << ' ';
    }
   // cout << endl;
    FOR(i, 1, n - k + 1){
        int l = i, r = i + k - 1;
     //   cout << fl[l - 1] << ' ' << fr[r + 1] << ' ';
        res = min(res, max(fl[l - 1], fr[r + 1]));
       // cout << res << endl;
    }
    printf("%lld", res);
    return 0;
}
