#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long
const ll maxn = 2e5+7;
ll n , a[maxn] ;

ll  f(ll x)
{
    //cerr << x << " ";
    ll tmp = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if (a[i] > x) tmp += a[i]-x;
        else tmp += x-a[i];
    }
    return tmp;
}
ll min_f(ll left, ll right) 
{
	for (int i = 0; i < 100; i++) 
    {

		ll x1 = left + (right - left) / 3;
		ll x2 = right - (right - left) / 3;
		if (f(x1) < f(x2)) right = x2 -1;
		else left = x1 + 1;
	}
	return f(right);
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> a[i];
        a[i] -= i ;
    }
    sort(a+1 , a+1+n); 
    cout << min_f(a[1], a[n]);
}