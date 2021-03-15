#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
#define balololabobo freopen("giun.inp", "r" , stdin) , freopen("giun.out", "w" , stdout);
using namespace std;
cll maxn = 2e5+7;
struct giun
{
    ll vl , vt;
} a[maxn];
bool cmp (giun x , giun y)
{
    return (x.vl <= y.vl);
}
ll n , ans = (ll) 1e18;
int main()
{
    balololabobo;
    giuncute;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].vl , a[i].vt = i;
    sort(a+1,a+1+n,cmp);
    for (int i = 1 ; i <= n ; i++) cerr << a[i].vl << " "<< a[i].vt << endl;
    for (int i = 2 ; i <= n ; i++)
        if (a[i].vt < a[i-1].vt) ans = min(ans, a[i].vl - a[i-1].vl);
    cout << ans;
}