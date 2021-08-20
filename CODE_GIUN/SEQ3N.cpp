#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll maxn = 3e5+7;
ll n , a[maxn] , ans = -1e18 , s1 = 0 , s2 = 0 , l[maxn] , r[maxn];
priority_queue<ll, vector<ll> , greater<ll>> ma2N ;
priority_queue<ll, vector<ll> > ma3N;
int main()
{
    giuncute;
    freopen("SEQ3N.inp","r",stdin);
    freopen("SEQ3N.out","w",stdout);
    cin >> n ;
    for (ll i = 1 ; i <= 3 * n ; i++) 
    {
        cin >> a[i];
        if (i <= n)  ma2N.push(a[i]) , s1 += a[i];
        if (i > 2*n) ma3N.push(a[i]) , s2 += a[i];
    }
    l[n] = s1;
    r[2*n+1] = s2;
    for (int i = n + 1 ; i <= 2*n ; i++)
    {
        if(ma2N.top() < a[i])
        {
            s1 = s1 - ma2N.top() + a[i]; 
            ma2N.pop();
            ma2N.push(a[i]);
        }
        l[i] = s1;
    }
    for (int i = 2*n ; i >= n + 1 ; i--)
    {
        if(ma3N.top() > a[i])
        {
            s2 = s2 - ma3N.top() + a[i];
            ma3N.pop();
            ma3N.push(a[i]);
        }
        r[i] = s2;
    }
    for (int i = n ; i <= 2 *n ; i++) ans = max (ans , l[i] - r[i+1]);
    cout << ans;
}