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
vi prime;
bool composite [maxn];
void sieve (int n)
{
	int s = sqrt (n);
	for (int i = 2; i <= s; ++i)
	{
		if (composite[i]) continue;
		for (int j = i * i; j <= n; j += i)
			composite[j] = 1;
	}
	for (int i = 2; i <= n; ++i)
	{
		if (!composite[i]) prime.pb (i);
	}
}
typedef pair <int, int> pii;
typedef vector <pii> vpii;
vpii factorize (int a)
{
	int id = 0;
	vpii res;
	while (a != 1)
	{
		int cnt = 0;
		while (a % prime[id] == 0)
		{
			++cnt;
			a /= prime[id];
		}
		if (cnt) res.pb (mp (prime[id], cnt));
		++id;
	}
	return res;
}
int gcd (int a, int b)
{
	if (a == 0) return b;
	return gcd (b % a, a);
}
struct solution
{
	vpii fact_a, fact_b;
	int a, b;
	void input ()
	{
		cin >> a >> b;
		int g = gcd (a, b);
		a /= g;
		b /= g;
		fact_a = factorize (a);
		fact_b = factorize (b);
	}
	vi t;
	ll prod = 1;
	void optimize (vpii &x)
	{
		// vpii y;
		for (pii g : x)
		{
			if (g.sd % 2)
				// y.pb (mp (g.ft, 1));
				t.pb (g.ft), prod *= g.ft;
		}
		// x = y;
	}
	ll res = inff, resa, resb;
	void partition (int id, ll a)
	{
		if (a + prod / a < res)
		{
			res = a + prod / a;
			resa = a, resb = prod / a;
		}
		for (int i = id + 1; i < m; ++i)
		{
			partition (i, a * t[i]);
		}
	}
	void solve ()
	{
		optimize (fact_a);
		optimize (fact_b);
		sort (whole (t));
		m = t.size ();
		partition (-1, 1);
		cout << resa << ' ' << resb << '\n';
	}
};
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("minsum.inp", "r", stdin);
	freopen ("minsum.out", "w", stdout);
	sieve (maxn - 1);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		solution gg;
		gg.input ();
		gg.solve ();
	}
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}