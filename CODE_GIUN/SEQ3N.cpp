#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll maxn = 3e5+7;
ll n , a[maxn] , ans = 0;
priority_queue<ll, vector<ll>, greater<ll> > mip;
priority_queue<ll, vector<ll> > pa;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    ll s1 = 0  , s2 = 0;
    for (ll i = 1 ; i <= 3 * n ; i++) 
    {
        cin >> a[i];
        if (i <= n) mip.push(a[i]) , s1 += a[i];
        if (i > 2*n) pa.push(a[i]) , s2 += a[i];
    }
    ll i = n , j = 2*n+1;
    while (i < j -1)
    {
        ll t1 = mip.top() , t2 = pa.top() , a1 =  (s1 - t1 + a[i+1]) - s2  , b = s1 - (s2 - t2 + a[j-1]) ;
        ll c = (s1 - t1 + a[i+1]) - (s2 - t2 + a[j-1])   ; 
        cerr << a1 << " " << b << " " << c << endl;
        if (i+1 < j-1) c = INT_MIN;
        if (a1 >= c && a1 >= b && i+1 < j) mip.pop() , s1 -= t1 , i++ , mip.push(a[i]) , s1 += a[i];
        else if (c >= b  && c >= a1 && i+1 < j-1) mip.pop() , s1 -= t1 , s2 -= t2 , pa.pop() , i++ , j-- , mip.push(a[i]) , pa.push(a[j]) , s1 += a[i] , s2 += a[j];
        else if (b >= c && b >= a1  && j-1 > i) pa.pop() , s2 -= t2 , j-- , pa.push(a[j]) , s2 += a[j];
        cerr << t1 << " " << t2 << " " << s1 << " " << s2 << endl;
        cerr << endl;
        ans = max (ans , s1 - s2);
    }
    cout << ans;
}