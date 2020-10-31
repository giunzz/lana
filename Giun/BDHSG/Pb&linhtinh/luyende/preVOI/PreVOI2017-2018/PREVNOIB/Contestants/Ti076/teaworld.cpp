#include <bits/stdc++.h>
#define NAME "teaworld"
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i,a ,b) for(int i = (a), _b = (b); i >= _b; --i)
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int maxN = 1e3 + 10;
int n, m, k;
struct P
{
	int x, y, z, r, e;
	int tt;
};
P a[maxN], b[maxN], t;
typedef pair<int, int> ii;
priority_queue<ii> q;
ll ans;
void io()
{
	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);
}
int main()
{
	io();
	cin >> m >> n >> k;
	FOR(i, 1, m)
	{
		cin >> a[i].x >> a[i].y >> a[i].z >> a[i].r;
	}
	FOR(i, 1, n)
	{
		cin >> b[i].x >> b[i].y >> b[i].z >> b[i].e;
		q.push(ii(b[i].e, i));
	}
	cin >> t.x >> t.y >> t.z;
	while(q.size())
	{
		int id = q.top().se;
		q.pop();
		int num = 0;
		FOR(i, 1, m)
		{
			if(a[i].tt == 0 && (a[i].x + a[i].r >= t.x && a[i].x + a[i].r <= b[id].x)) num++;
		}
		if(num <= k)
		{
			FOR(i, 1, m)
			{
				if(a[i].tt == 0 && a[i].x + a[i].r >= t.x && a[i].x + a[i].r < b[id].x) a[i].tt = 1;
			}
			ans += b[id].e;
			k -= num;
		}
	}
	cout << ans;
	return 0;
}
/*
1 2 0
0 0 0 2
-1 0 0 5
2 0 0 100
1 0 0
*/