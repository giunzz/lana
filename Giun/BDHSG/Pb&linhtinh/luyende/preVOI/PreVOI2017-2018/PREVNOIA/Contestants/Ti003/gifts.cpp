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
int n, k, m;
ll sum[maxn];
int a[maxn];
void input ()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
}
ll f_b[maxn] = {}, f_e[maxn] = {};
void solve ()
{
	ll res = inf;
	for (int i = n - k + 1; i >= 1; --i)
		f_b[i] = max (f_b[i + 1], sum[i + k - 1] - sum[i - 1]);
	for (int i = k; i <= n; ++i)
		f_e[i] = max (f_e[i - 1], sum[i] - sum[i - k]);
	for (int i = 1; i <= n - k + 1; ++i)
	{
		res = min (res, max (f_e[i - 1], f_b[i + k]));
	}
	cout << res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("gifts.inp", "r", stdin);
	freopen ("gifts.out", "w", stdout);
	input ();
	solve ();
}