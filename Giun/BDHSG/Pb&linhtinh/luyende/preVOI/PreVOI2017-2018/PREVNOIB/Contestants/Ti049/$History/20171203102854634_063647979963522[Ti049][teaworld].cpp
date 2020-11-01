#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define endl '\n'
#define pi acos(-1)
#define pque priority_queue
#define N 1000000
#define lmax LONG_LONG_MAX
#define cin fi
#define cout fo
ifstream fi("teaworld.inp");
ofstream fo("teaworld.out");
typedef pair < int, int > ii;
typedef vector < int > vi;
typedef vector < vi > vii;
int mod = 1000000007;
bitset < 2009 > d[20];
int x[2009], y[2009], z[2009], r[2009], a[20], b[20], c[20], f[20], ans, xs, ys, zs, n, m, k;

int dist(int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
bool kt(int x1, int y1, int x2, int y2, int xr, int yr, int rr)
{
	if(x1 == x2)
		swap(x1, y1), swap(x2, y2), swap(xr, yr);
	if(x1 > x2)
		swap(x1, x2), swap(y1, y2);
	int l = x1;
	int r = x2;
	int mid = (l + r) / 2;
	while(l != mid && r != mid)
	{
		int m1 = dist(mid * (x1 - x2), (mid - x1) * (y1 - y2) + y1 * (x1 - x2), xr * (x1 - x2), yr * (x1 - x2));
		int m2 = dist((mid + 1) * (x1 - x2), (mid - x1 + 1) * (y1 - y2) + y1 * (x1 - x2), xr * (x1 - x2), yr * (x1 - x2));
		if(m1 > m2)
			l = mid + 1;
		else
			r = mid;
		mid = (l + r) / 2;
	}
	if(dist(l * (x1 - x2), (l - x1) * (y1 - y2) + y1 * (x1 - x2), xr * (x1 - x2), yr * (x1 - x2)) <= rr * rr * (x1 - x2) * (x1 - x2) || dist((r) * (x1 - x2), (r - x1) * (y1 - y2) + y1 * (x1 - x2), xr * (x1 - x2), yr * (x1 - x2)) <= rr * rr * (x1 - x2) * (x1 - x2))
		return true;
	return false;
}
bool cak(int x1, int y1, int x2, int y2, int xr, int yr, int rr)
{
	if(dist(x1, y1, xr, yr) <= rr * rr && dist(x2, y2, xr, yr) <= rr * rr)
		return true;
	return false;
}
bool checkin(int st, int ba)
{
	if(cak(xs, ys, a[st], b[st], x[ba], y[ba], r[ba]) && cak(ys, zs, b[st], c[st], y[ba], z[ba], r[ba]) && cak(zs, xs, c[st], a[st], z[ba], x[ba], r[ba]))
		return true;
}
bool check(int st, int ba)
{
	if(checkin(st, ba) == true)
		return false;
	if(!kt(xs, ys, a[st], b[st], x[ba], y[ba], r[ba]) || !kt(ys, zs, b[st], c[st], y[ba], z[ba], r[ba]) || !kt(zs, xs, c[st], a[st], z[ba], x[ba], r[ba]))
		return false;
	return true;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin >> m >> n >> k;
	for(int i = 1; i <= m; i ++)
		cin >> x[i] >> y[i] >> z[i] >> r[i];
	for(int i = 1; i <= m; i ++)
		x[i] *= 10, y[i] *= 10, z[i] *= 10, r[i] *= 10;
	for(int i = 0; i < n; i ++)
		cin >> a[i] >> b[i] >> c[i] >> f[i];
	for(int i = 0; i < n; i ++)
		a[i] *= 10, b[i] *= 10, c[i] *= 10;
	cin >> xs >> ys >> zs;
	xs *= 10, ys *= 10, zs *= 10;
	for(int i = 0; i < n; i ++)
		for(int j = 1; j <= m; j ++)
			if(check(i, j))
				d[i].set(j);
	for(int mask = 0; mask < (1 << n); mask ++)
	{
		bitset < 2009 > cur;
		cur.reset();
		int val = 0;
		for(int i = 0; i < n; i ++)
			if((mask & (1 << i)) > 0)
				cur = cur | d[i], val += f[i];
		if(cur.count() > k)
			continue;
		else
			ans = max(ans, val);
	}
	cout << ans;
}

