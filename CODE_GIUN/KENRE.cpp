#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
ll n , a[maxn] , ans = 0 , b[maxn];
using namespace std;
inline bool check_day(ll a[maxn])
{
    for (int i = 1 ; i < 2*n ; i++)
        if (a[i] > a[i+1]) return false;
    return true;
}
inline bool check (ll a[maxn])
{
    ll k = 0 , c = 0 ;
    for (int i = 1 ; i <= 2*n ; i++) 
    {
        if (a[i] == b[i]) k++;
        else c = max(k,c) , k = 0 ;
    }
    if (k == 2*n) return false;
    if (c > 1) return true;
    return false;
}
int main()
{
    giuncute;
    freopen("giun.inp" , "r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> n ;
    for (int i = 1 ; i <= 2*n ; i++)  cin >> a[i] , b[i] = a[i];
    sort(b + 1 , b + 1 + 2*n);
    ll k = 0;
    while (check_day(a) == false)
    {
        ans++;
        if (k == 0)
        {
            for (int i = 1 ; i <= 2*n ; i += 2) swap(a[i] , a[i+1]);
            k = 1;
        }
        else
        {
            for (int i = 1 ; i <= n ; i++) swap(a[i] , a[i+n]);
            k = 0 ;
        }
        if (check(a) == true)
        {
            ans = -1;
            break;
        }
    }
    cout << ans;
}