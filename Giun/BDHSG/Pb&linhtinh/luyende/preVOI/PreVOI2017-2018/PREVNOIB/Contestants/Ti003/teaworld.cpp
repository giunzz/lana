#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define ft first
#define sd second
#define _(a) #a << " : " << (a)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
const int maxm = 1e3 + 1;
int n, k, m;
struct vec;
typedef vec point;
struct vec
{
	ld x, y, z;
	vec () {}
	vec (ld xx, ld yy, ld zz)
	{
		x = xx, y = yy, z = zz;
	}
	vec (point a, point b)
	{
		x = b.x - a.x;
		y = b.y - a.y;
		z = b.z - a.z;
	}
	ld operator * (vec a)
	{
		return a.x * x + a.y * y + a.z * z;
	}
};
ld length (vec a)
{
	return sqrt (a.x * a.x + a.y * a.y + a.z * a.z);
}
ld angle (vec a, vec b)
{
	ld prod = a * b, la = length (a), lb = length (b);
	ld g = prod / (la * lb);
	if (g < 0) g += eps;
	else g -= eps;
	return acos (g);
}
struct sphere
{
	point o;
	ld r;
	sphere () {}
	sphere (point oo, ld rr)
	{
		o = oo, r = rr;
	}
	bool contain (point a)
	{
		ld d = length (vec (o, a));
		return d <= r;
	}
};
struct shop
{
	point p;
	ld e;
};
bool sphere_in_between (point &a, point &b, sphere &c)
{
	bool a_in = c.contain (a), b_in = c.contain (b);
	if (a_in and b_in) return 0;
	else if (a_in ^ b_in) return 1;
	vec ao = vec (a, c.o), ab = vec (a, b);
	ld al = angle (ao, ab);
	if (al >= pi / 2) return 0;
	ld h = length (ao) * sin (al), g = length (ao) * cos (al);
	if (h <= c.r and g < length (ab)) return 1;
	else return 0;
}
point s;
shop shop_list [16];
sphere sphere_list [maxm];
vector <int> between[16];
int cnt[maxn] = {};
ld res = 0;
void attempt (int id, int s_cnt, ld en_sum)
{
	if (k == s_cnt) res = max (res, en_sum);
	for (int i = id + 1; i <= n; ++i)
	{
		int h = s_cnt;
		for (int j : between[i])
		{
			++cnt[j];
			if (cnt[j] == 1) ++h;
		}
		attempt (i, h, en_sum + shop_list[i].e);
		for (int j : between[i])
			--cnt[j];
	}
}
void input ()
{
	cin >> m >> n >> k;
	ld x, y, z, g;
	for (int i = 1; i <= m; ++i)
	{
		cin >> x >> y >> z >> g;
		sphere_list[i] = sphere (point (x, y, z), g);
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> x >> y >> z >> g;
		shop_list[i] = shop {point (x, y, z), g};
	}
	cin >> x >> y >> z;
	s = point (x, y, z);
}
void print (point a)
{
	cout << a.x << ' ' << a.y << ' ' << a.z;
}
void solve ()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if (sphere_in_between (s, shop_list[i].p, sphere_list[j]))
			{
				between[i].pb (j);
			}
		}
	attempt (0, 0, 0);
	cout << res;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("teaworld.inp", "r", stdin);
	freopen ("teaworld.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}