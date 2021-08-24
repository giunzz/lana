#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "dankien"
using namespace std;

const ll mxn = 1e6 + 7;
ll a[mxn] = {0}, x[mxn] = {0}, n, ans;

ll cnp(ll l , ll r){
	ll mid = (l+r)/2;
	ll sum = 0 , sum1 = 0, sum2 = 0;
	for (ll i = 1 ; i <= n ; i++){
		sum += abs((x[i] - mid))*a[i], sum1 += abs((x[i] - (mid - 1)))*a[i], sum2 += abs((x[i] - (mid + 1)))*a[i];
	}
	if (sum < sum1 && sum >= sum2) return cnp(mid+1,r);
	else
		if (sum >= sum1 && sum < sum2) return cnp(l,mid-1);
	else
		if ((sum <= sum1 && sum <= sum2) || (sum1 <= sum && sum <= sum2)) {
			ans = mid;
			return sum;
		}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	lp(i, 1, n)
		cin >> a[i];
	lp(i, 1, n)
		cin >> x[i];
	ll maxn = 1e9;
	ll res = cnp(1,maxn);
	cout << res << '\n';
	return 0;
}
