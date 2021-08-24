// #include <bits/stdc++.h>
// #define ll long long
// #define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
// #define fi first
// #define se second
// #define pl pair<ll,ll>
// const ll oo = 1e18;
// const ll maxn = 1e6 + 7;
// using namespace std;
// ll ans = oo;
// ll n , x[maxn] , a[maxn] , b[maxn] , fl[maxn] , fr[maxn];
// int main()
// {
//     freopen("giun.inp","r",stdin);
//     freopen("giun.out","w",stdout);
//     scanf("%lld", &n);
//     b[0] = 0;
//     for (int i = 1 ; i <= n ; i++) scanf("%lld", &a[i]) , b[i] = b[i-1] + a[i];
//     for (int i = 1 ; i <= n ; i++) scanf("%lld", &x[i]);
//     for (int i = 1 ; i <= n ; i++) fl[i] = fl[i-1] + b[i-1] * (x[i] - x[i-1]);
//     for (int i = n ; i >= 1 ; i--)
//     {
//         fr[i] = fr[i+1] + (b[n] - b[i]) * (x[i+1] - x[i]);
//         ans = min(ans , fl[i] + fr[i]);
//     }
//     cout << ans;
// }
#include <iostream>
#include <cmath>

using namespace std;
#define ll long long
#define max (ll) 1e6 +7
ll a[max] = {0} , x[max] = {0} , n ;
ll ans;

ll binarysearch(ll l , ll r)
{
	ll mid = (l+r)/2;
	ll sum = 0 , sum1 = 0, sum2 = 0;
	for (ll i = 1 ; i <= n ; i++)
    {
		sum += abs((x[i] - mid))*a[i];
		sum1 += abs((x[i] - (mid - 1)))*a[i];
		sum2 += abs((x[i] - (mid + 1)))*a[i];
	}
	if (sum < sum1 && sum >= sum2) return binarysearch(mid+1,r);
	else 
		if (sum >= sum1 && sum < sum2) return binarysearch(l,mid-1);
	else
		if ((sum <= sum1 && sum <= sum2) || (sum1 <= sum && sum <= sum2)) {
			ans = mid;
			return sum;
		}
	return 0;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("dankien.inp","r",stdin);
	freopen("dankien.out","w",stdout);
	cin >> n;
	for (ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	for (ll i = 1 ; i <= n ; i++)
		cin >> x[i];
	ll maxn = 1e9;
	ll res = binarysearch(1,maxn);
	cout << res << '\n';
	cout << ans;

	return 0;
}