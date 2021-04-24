#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)
const ll maxn = 1e5+7;
ll n , a[maxn] , BIT[maxn]={0};
ll sol (ll x)
{
    ll sum = 0 ;
    for (int i = x ; i >= 1 ; i -= (i&-i) ) sum += BIT[i];
    return sum ;
}
void update(ll x)
{
    for (int i = x ; i < maxn ; i += (i&-i) ) BIT[i]++;
}
int main()
{
    giuncute;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    ll ans = 0 ;
    for (int i = n ; i >= 1 ; i--)
    {
        ans += sol(a[i] - 1);
        update(a[i]);
    }
    cout << ans ;
}