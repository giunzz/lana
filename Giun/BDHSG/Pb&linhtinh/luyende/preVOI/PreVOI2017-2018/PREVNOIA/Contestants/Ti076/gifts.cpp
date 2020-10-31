#include <bits/stdc++.h>
#define NAME "gifts"
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i,a ,b) for(int i = (a), _b = (b); i >= _b; --i)
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int maxN = 1e6 + 10;
int n, a[maxN], k;
ll tree[4 * maxN], f[maxN];
ll ans;
void io()
{
	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);
}
void build(int s, int l, int r)
{
	if(l == r) tree[s] = f[l];
	else
	{
		int mid = (l + r) >> 1;
		build(2 * s, l, mid);
		build(2 * s + 1, mid + 1, r);
		tree[s] = max(tree[2 * s], tree[2 * s + 1]);
	}
}
ll get(int s, int l, int r, int u, int v)
{
	if(v < l || r < u) return 0;
	if(u <= l && r <= v) return tree[s];
	int mid = (l + r) >> 1;
	return max(get(2 * s, l, mid, u, v), get(2 * s + 1, mid + 1, r, u, v));
}
int main()
{
	io();
	scanf("%d %d", &n, &k);
	FOR(i, 1, n)
	scanf("%d", &a[i]);
	ll sum = 0;
	int cnt = 0, l = 0;
	FOR(i, 1, n) {
		cnt++;
		if(cnt <= k)
		{
			sum += 1LL * a[i];
		}
		if(cnt == k) cnt--,  sum -= 1LL*a[i - k], f[++l] = sum;
	}
	build(1, 1, n);
	ans = 1e18;
	ll res = 0;
	FOR(i, 1, n)
	{
		res = 0;
		if(i - k > 0) res = max(res, get(1, 1, n, 1, i - k));
		if(i + k <= n - k + 1) res = max(res, get(1, 1, n, i + k, n - k + 1));
		ans = min(ans, res);
	}
	printf("%lld", ans);
	return 0;
}
/*

10 2
1 2 4 5 2 4 2 2 1 6

8 3
2 3 4 5 1 3 2 10
*/