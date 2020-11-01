#include <bits/stdc++.h>
#define NAME "minsum"
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i,a ,b) for(int i = (a), _b = (b); i >= _b; --i)
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
int t;
ll ans;
void io()
{
	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);
}
int main()
{
	io();
	ll x, y;
	cin >> t;
	while (t--)
	{
		cin >> x >> y;
		ans = 1e18;
		ll k = x * y;
		ll a, b;
		ll g = __gcd(x, y);
		x /= g, y /= g;
		for (int i = 1; 1LL * i * i <= k; i++)
		{
			if (k % i == 0)
			{
				ll v = k / i;
				ll u = __gcd(1LL * i, v);
				if (ans > i / u + v / u) {
					ans = i / u + v / u;
					a = i / u, b = v / u;
				}
			}
		}
		cout << a << " " << b << "\n";
	}
	return 0;
}