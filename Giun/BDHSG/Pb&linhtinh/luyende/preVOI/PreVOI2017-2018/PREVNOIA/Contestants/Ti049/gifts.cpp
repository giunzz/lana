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
ifstream fi("gifts.inp");
ofstream fo("gifts.out");
typedef pair < int, int > ii;
typedef vector < int > vi;
typedef vector < vi > vii;
int mod = 1000000007;
int n, k, ans = 1e18, a[1000009], d[1000009], pre[1000009], suf[1000009];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		d[i] = d[i - 1] + a[i];
	for(int i = k + 1; i <= n; i ++)
		pre[i] = max(pre[i - 1], d[i - 1] - d[i - k - 1]);
	for(int i = n - k; i > 0; i --)
		suf[i] = max(suf[i + 1], d[i + k] - d[i]);
	for(int i = 1; i <= n - k + 1; i ++)
		ans = min(ans, max(pre[i], suf[i + k - 1]));
	cout << ans;
}

