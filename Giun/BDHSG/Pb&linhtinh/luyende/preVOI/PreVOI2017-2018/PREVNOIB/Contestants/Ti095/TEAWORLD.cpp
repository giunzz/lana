#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a), _b = (b) ; i <= _b ; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b) ; i <= _b ; --i)
#define For(i, a, b) for(int i = (a), _b = (b) ; i < _b ; ++i)
#define Ford(i, a, b) for(int i = (a), _b = (b) ; i > _b ; --i)
#define ll long long
#define ii pair <int,int>
#define mp make_pair
#define pb push_back
#define X first
#define Y second

using namespace std;

const int N = 2010;
const int add = 505;
const int oo = 1e9;

int n, m, K;
int GS, GSS= 0;
int tea[N], R[N], W[N], d[N], c[N];
int sum[N];
int top = 0;
int res = 0;
bool ok1 = 1, ok2 = 1;

struct P {
	int x, y, z, w, r, id;
} a[N], b[N];

bool cmp_1(P a, P b) {
	return a.x < b.x;
}

void sub_1(void) {

	sort(a+1, a+top+1, cmp_1);
	sort(b+1, b+n+1, cmp_1);

	FOR(i, 1, top) a[i].x += add;
	FOR(i, 1, n) b[i].x += add;

	///FOR(i, 1, top) cout << a[i].x << " "; cout << endl;

	FOR(i, 1, top) {
		if(a[i].r != 0) R[a[i].x] = max(R[a[i].x], a[i].r);
		if(a[i].id == 1) GS = i, GSS = a[i].x;
	}


	FOR(i, 1, n) if(b[i].w != 0) W[b[i].x] += b[i].w;

	FOR(x, 0, 1010) tea[x] = tea[x-1] + W[x];

	int right = 0;
	FOR(left, 0, K)
	///int left = 1;
	{
		int cur = 0;
		right = K - left;

		FOR(i, 1, top) d[i] = 0;
		FOR(i, 1, 1010) c[i] = 0;

		FOR(j, GS-left, GS-1) d[j] = 1;

		FOR(j, GS+1, GS+right) d[j] = 1;

		///FOR(i, 1, top) cout << d[i] << ' '; cout << endl;

		FOR(i, 1, top) if(!d[i] && i != GS) c[a[i].x - a[i].r] = 1, c[a[i].x + a[i].r] = -1;
		sum[0] = 0;
		FOR(i, 1, 1010) sum[i] = sum[i-1] + c[i];

		FOR(i, 1, n) {

			if(b[i].x < GSS && sum[GSS] - sum[b[i].x - 1] == 0) cur += W[b[i].x];
			if(b[i].x > GSS && sum[b[i].x] - sum[GSS - 1] == 0) cur += W[b[i].x];
		}
		res = max(res, cur);
	}
	cout << res << endl;
}

int main()
{
	freopen("TEAWORLD.INP", "r", stdin); freopen("TEAWORLD.OUT", "w", stdout);
	scanf("%d%d%d", &m, &n, &K);
	ok1 = ok2 = 1;
	FOR(i, 1, m) {
		scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].z, &a[i].r);
		///R[a[i].x] = max(R[a[i].x], a[i].r);
		ok1 &= (a[i].y == 0 && a[i].z == 0), ok2 &= (a[i].y == 0);
	}
	top = m;
	FOR(i, 1, n) {
		scanf("%d%d%d%d", &b[i].x, &b[i].y, &b[i].z, &b[i].w);
		ok1 &= (b[i].y == 0 && b[i].z == 0), ok2 &= (b[i].y == 0);
	}
	++top;
	scanf("%d%d%d", &a[top].x, &a[top].y, &a[top].z); a[top].id = 1;
	sub_1();
    return 0;
}
