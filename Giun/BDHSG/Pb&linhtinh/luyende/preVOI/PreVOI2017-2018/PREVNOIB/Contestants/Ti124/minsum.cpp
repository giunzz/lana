#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 506;

ll t;
pair<ll, ll > que[N];

void enter(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("minsum.inp", "r", stdin);
	freopen("minsum.out", "w", stdout);
	
	cin >> t;
	for (ll i = 1; i <= t; i++){
		cin >> que[i].first >> que[i].second;
	}
}

void solve(ll a, ll b){
	vector<ll > VA, VB;
	ll x = __gcd(a, b);
	a /= x; b /= x;
	ll cla = a, clb = b;
	for (ll i = 2; i <= sqrt(cla); i++){ 
		if (a == 1) break;
		if (a % i == 0){
			ll num = 0;
			while (a % i == 0){
				a /= i; num++;
			}
			num %= 2;
			if (num ) VA.push_back(i);
		}
	}
	for (ll i = sqrt(cla); i >= 2; i--){
		if (a == 1) break;
		if (a % i == 0){
			ll x = a / i, num = 0;
			while (a % x == 0){
				a /= x; num++;
			}
			num %= 2;
			if (num ) VA.push_back(x);
		}
	}
	if (a != 1) VA.push_back(a), a = 1;
	for (ll i = 2; i <= sqrt(clb); i++){ 
		if (b == 1) break;
		if (b % i == 0){
			ll num = 0;
			while (b % i == 0){
				b /= i; num++;
			}
			num %= 2;
			if (num ) VB.push_back(i);
		}
	}
	if (b != 1) VB.push_back(b), b = 1;
	
	for (ll i = sqrt(clb); i >= 2; i--){
		if (b == 1) break;
		if (b % i == 0){
			ll x = b / i, num = 0;
			while (b % x == 0){
				b /= x; num++;
			}
			num %= 2;
			if (num ) VB.push_back(x);
		}
	}
	ll va = VA.size(), vb = VB.size(), oa = 1, ob = 1;
	for (ll i = 0; i < va; i++) oa *= VA[i];
	for (ll i = 0; i < vb; i++) ob *= VB[i];
	pair<ll, ll > ans = make_pair(oa, ob);
	for (ll mask1 = 0; mask1 < (1 << VA.size()); mask1++)
		for (ll mask2 = 0; mask2 < (1 << VB.size()); mask2++){
			ll cla = oa; clb = ob;
			for (ll i = 0; i < va; i++)
				if (mask1 & (1 << i))
					cla /= VA[i], clb *= VA[i];
			for (ll i = 0; i < vb; i++)
				if (mask2 & (1 << i))
					cla *= VB[i], clb /= VB[i];
			if (cla + clb < ans.first + ans.second) ans = make_pair(cla, clb);
		}
	cout << ans.first << ' ' << ans.second << '\n';
}

main(){
	enter();
	for (ll x = 1; x <= t; x++)
	{
		solve(que[x].first, que[x].second);
	}
}