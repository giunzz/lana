#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 1e6+7 ;
ll n ,  x  , ans = 0 ;
struct giun
{
    ll val , color;
} a[maxn];
bool cmp (giun &x , giun &y)
{
    return (x.val < y.val);
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1  ; i <= n ; i++) cin >> a[i].val , a[i].color = 0 ;
    for (int i = n+1  ; i <= 2 * n ; i++) cin >> a[i].val , a[i].color = 1 ;
    sort(a + 1 , a + 1 + 2 *n , cmp);
    for (ll i = 1 ; i < 2 * n ; i++)
    {
        if (a[i].color != a[i+1].color) i++ , ans++;
    }
    cout << ans;
}