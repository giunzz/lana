#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a), _b = (b) ; i <= _b ; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b) ; i >= _b ; --i)
#define For(i, a, b) for(int i = (a), _b = (b) ; i < _b ; ++i)
#define Ford(i, a, b) for(int i = (a), _b = (b) ; i > _b ; --i)
#define ll long long
#define ii pair <int,int>
#define mp make_pair
#define pb push_back
#define X first
#define Y second

using namespace std;

const int N = 1e6+5;
const ll oo = 1e18;

int n, k;
int x;
ll sum[N], b[N], res = oo, cur = 0;
ll tree[N<<2];

#define mid ((l + r) >> 1)
void build(int i, int l, int r) {
	if(l == r) {tree[i] = b[l]; return;}
	build(i<<1, l, mid);
	build(i<<1|1, mid+1, r);
	tree[i] = max(tree[i<<1], tree[i<<1|1]);
}

ll get(int i, int l, int r, int u, int v) {
	if(u > r ||v < l) return 0;
	if(u <= l && r <= v) return tree[i];
	return max(get(i<<1, l, mid, u, v), get(i<<1|1, mid+1, r, u, v));
}
#undef mid

int main()
{
	freopen("GIFTS.INP", "r", stdin); freopen("GIFTS.OUT", "w", stdout);
	scanf("%d%d", &n, &k);
	sum[0] = 0;
	FOR(i, 1, n) scanf("%d", &x), sum[i] = sum[i-1] + x;
	int top = 0;
	FOR(i, k, n) b[++top] = sum[i] - sum[i-k];

	///cerr << endl; FOR(i, 1, top) cout << b[i] << " " ; cout << endl;

	build(1, 1, top);
	FOR(i, 1, top) {
		cur = 0;
		///FOR(j, 1, top) if(j >= i+k || j <= i - k) cur = max(cur, b[j]);
		if(i - k >= 1) cur = max(cur, get(1, 1, top, 1, i - k));
		if(i + k <= top) cur = max(cur, get(1, 1, top, i+k, top));
		if(cur <= b[i]) res = min(res, b[i]);
	}
	cout << res << endl;
    return 0;
}
