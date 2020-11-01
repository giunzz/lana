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
ll a[maxn], low, high;
ll sum = 0;
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], sum += a[i];
}
void solve ()
{
	if (sum % n)
	{
		cout << "can not solve yet";
		exit (0);
	}
	int low = sum / n;
	ll res = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] < low)
		{
			a[i + 1] -= (low - a[i]);
			res += low - a[i];
		}
		else if (a[i] > low)
		{
			a[i + 1] += (a[i] - low);
			res += a[i] - low;
		}
	}
	cout << res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("arrange.inp", "r", stdin);
	freopen ("arrange.out", "w", stdout);
	input ();
	solve ();
}