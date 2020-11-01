#include <bits/stdc++.h>
#define NAME "arrange"
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i,a ,b) for(int i = (a), _b = (b); i >= _b; --i)
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int maxN = 1e6 + 10;
int n, a[maxN], d[maxN];
int ans;
void io()
{
	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);
}
int main()
{
	io();
	cin >> n;
	ll sum = 0;
	FOR(i, 1, n) cin >> a[i], d[a[i]]++, sum += a[i];
	int t = sum / n;
	int r = sum % n;
	int l = n - r;
	while(1)
	{
		bool ok = true;
		FOR(i, 1, n) if(a[i] > t)
		{
			if(a[i] == t + 1 && r != 0 && d[t + 1] <= r) continue;
			ok = false;
			ans += a[i] - t;
			if(i - 1 > 0 && a[i - 1] != t) d[a[i - 1]]--, a[i - 1] += a[i] - t, d[a[i - 1]]++; 
			else if(i + 1 <= n && a[i + 1] != t) d[a[i + 1]]--, a[i + 1] += a[i] - t, d[a[i + 1]]++;
			else if(i - 1 > 0) d[a[i - 1]]--, a[i - 1] += a[i] - t, d[a[i - 1]]++;
			else if(i + 1 <= n) d[a[i + 1]]--, a[i + 1] += a[i] - t, d[a[i + 1]]++;
			d[a[i]]--;
			a[i] = t;
			d[a[i]]++;
			break;
		}
		if(ok) break;
	}
	cout << ans;
	return 0;
}