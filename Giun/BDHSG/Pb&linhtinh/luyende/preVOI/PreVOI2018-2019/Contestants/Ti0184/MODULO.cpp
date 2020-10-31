#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define II pair<int, int>
#define x first
#define y second
#define mp make_pair
using namespace std;
ll a, b, n, k, mod;
void sub1()
{
	mod = (1LL << n);
	ll maxst = (1LL << n) - 1;
	for(int i = 0; i <= maxst; i ++){
		ll tmp = 0;
		for(int j = 0; j < n; j ++)
			if((i >> j) & 1) tmp = (tmp * 10 + a) % mod;
				else tmp = (tmp * 10 + b) % mod;
		if(tmp == k){
			for(int j = 0; j < n; j ++)
				if((i >> j) & 1) cout << a;
					else cout << b;
			return;
		}
	}	
	cout << -1;
}
void sub2()
{
	map<ll, ll> Map;
	mod = (1LL << n);
	int sl1 = n / 2;
	int sl2 = n - sl1;
	ll Pow = 1;
	for(int i = 1; i <= sl2; i ++) Pow = Pow * 10 % mod;
	ll maxst = (1LL << sl1) - 1;
	for(int i = 0; i <= maxst; i ++){
		ll tmp = 0;
		for(int j = 0; j < sl1; j ++)
			if((i >> j) & 1) tmp = (tmp * 10 + a) % mod;
				else tmp = (tmp * 10 + b) % mod;
		tmp = tmp * Pow % mod;
		Map[tmp] = i;
	}
	maxst = (1LL << sl2) - 1;
	for(int i = 0; i <= maxst; i ++){
		ll tmp = 0;
		for(int j = 0; j < sl2; j ++)
			if((i >> j) & 1) tmp = (tmp * 10 + a) % mod;
				else tmp = (tmp * 10 + b) % mod;
		ll x = (k - tmp + mod) % mod;
		if(Map.find(x) != Map.end()){
			int st1 = Map[x], st2 = i;
			for(int j = 0; j < sl1; j ++)
				if((st1 >> j) & 1) cout << a;
					else cout << b;
			for(int j = 0; j < sl2; j ++)
				if((st2 >> j) & 1) cout << a;
					else cout << b;
			return;
		}
	}
	cout << -1;
}
int main()
{
	freopen("MODULO.inp", "r", stdin);
	freopen("MODULO.out", "w", stdout);
	cin >> a >> b >> n >> k;
	if(n <= 20) sub1();
	else if(n <= 40) sub2();
	else cout << -1;
}