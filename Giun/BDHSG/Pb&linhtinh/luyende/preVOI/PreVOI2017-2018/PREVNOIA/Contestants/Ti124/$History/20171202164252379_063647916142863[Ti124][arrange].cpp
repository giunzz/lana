#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2006;

ll n, a[N];
ll s = 0;
ll sum[N];
ll dp[N][20];

ll down(ll x){ return (x - (x % n) ) / n; }

main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("arrange.inp", "r", stdin);
	freopen("arrange.out", "w", stdout);
	
	cin >> n;
	for (ll i = 1; i <= n; i++){
		cin >> a[i];
		s = a[i] + s;
		sum[i] = sum[i - 1] + a[i];
	}
	ll x = down(s);
	if (s % n == 0){
		ll res = 0;
		ll rem = 0;
		for (ll i = 1; i < n; i++){
			a[i] += rem;
			res += abs(x - a[i]);
			rem = a[i] - x;
		}
		cout << res;
	}
	else{
		ll bd = s - x * n;
		memset(dp, 60, sizeof dp);
		dp[0][0] = 0;
		for (ll i = 1; i <= n; i++)
			for (ll j = 0; j <= bd; j++){
				for (ll c = 0; c < 2; c++)
					if (j >= c) 
						dp[i][j] = min(dp[i][j], dp[i - 1][j - c] + abs( a[i] - x - c + sum[i - 1] - (x * (i - 1) + j - c) ));
			}
				
		cout << dp[n][bd];
	}
}