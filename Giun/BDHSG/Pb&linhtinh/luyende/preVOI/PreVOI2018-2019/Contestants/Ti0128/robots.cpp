/*input
4 5
0 4
-2 -4
8 -2
7 -5
5 -1
*/
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

int read() {
	int number = 0, c = getchar(), neg = 1;
	for(; !((c > 47 && c < 58) || (c == '-')); c = getchar());
	if(c == '-') neg = -1, c = getchar();
	for(; (c > 47 && c < 58); c = getchar())
		number = (number << 3) + (number << 1) + c - 48;
	return number * neg;
}

#define int int64_t
typedef pair<int, int> Point;

const int N = 10005;
Point Center[N];
int val[N << 3], Arr[N << 1], U, n;
int Sum[N << 3], lef[N << 3], rig[N << 3];
bool mark[N];
pair<Point, Point> Robot, Square[N];

void update(int node, int l, int r, int u, int v, int x) {
	if(v < l || r < u) return;
	if(u <= l && r <= v) {
		val[node] += x;
		if(val[node] > 0) Sum[node] = (Arr[r] - Arr[l]) / 2 + 1, lef[node] = rig[node] = 1;
			else {
				if(l == r) Sum[node] = 0;
					else {
						Sum[node] = Sum[node << 1] + Sum[node << 1 | 1];
						lef[node] = lef[node << 1], rig[node] = rig[node << 1 | 1];
						int mid = (l + r) >> 1;
						if(rig[node << 1] && lef[node << 1 | 1])
							Sum[node] += (Arr[mid + 1] - 2 - Arr[mid] - 2) / 2;
					}
			}
		return;
	}
	int mid = (l + r) >> 1;
	update(node << 1, l, mid, u, v, x);
	update(node << 1 | 1, mid + 1, r, u, v, x);
	if(val[node] > 0) Sum[node] = (Arr[r] - Arr[l]) / 2 + 1, lef[node] = rig[node] = 1;
		else {
			Sum[node] = Sum[node << 1] + Sum[node << 1 | 1];
			lef[node] = lef[node << 1], rig[node] = rig[node << 1 | 1];
			int mid = (l + r) >> 1;
			if(rig[node << 1] && lef[node << 1 | 1])
				Sum[node] += (Arr[mid + 1] - 2 - Arr[mid] - 2) / 2;
		}
}

bool check(int offset) {
	map<int, int> hashMap;
	for(int i = 1; i <= U; ++ i) {
		mark[i] = 0;
		Point a = Center[i];
		Point x = Point(a.first - offset, a.first + offset);
		Point y = Point(a.second - offset, a.second + offset);

		x.first = max(x.first, Robot.first.first);
		x.second = min(x.second, Robot.first.second);
		y.first = max(y.first, Robot.second.first);
		y.second = min(y.second, Robot.second.second);
		if(x.first > x.second || y.first > y.second) continue;
		// cout << x.first << ' ' << x.second << ' ' << y.first << ' ' << y.second << endl;

		mark[i] = 1, Square[i] = make_pair(x, y);
		hashMap[y.first] = hashMap[y.second] = 1;
	}

	// compress
	int m = 0;
	for(auto it = hashMap.begin(); it != hashMap.end(); ++ it) 
		it->second = ++ m, Arr[m] = it->first;

	vector<pair<Point, Point > > events;
	for(int i = 1; i <= U; ++ i) if(mark[i]) {
		Square[i].second.first = hashMap[Square[i].second.first];
		Square[i].second.second = hashMap[Square[i].second.second];
		events.emplace_back(make_pair(Point(Square[i].first.first, 0), Square[i].second));
		events.emplace_back(make_pair(Point(Square[i].first.second + 1, 1), Square[i].second));
	}
	sort(events.begin(), events.end());
	if(events.empty()) return 1;

	memset(Sum, 0, sizeof Sum), memset(val, 0, sizeof val);
	int last = events[0].first.first, Ans = 0, sign = 0;
	for(auto x : events) {
		int Time = x.first.first, l = x.second.first, r = x.second.second;
		if(sign == 0 && Sum[1] && Time != last) {
			Ans += Sum[1] * (Time - last), Ans -= (Time - last) / 2;
		}
		if(sign == 1 && Sum[1] && Time != last) {
			if(x.first.second == 0) Ans += Sum[1] * (Time - last) - (Time - last + 1) / 2;
				else Ans += Sum[1] * (Time - last) - (Time - last) / 2;
		}
		update(1, 1, m, l, r, x.first.second ? -1 : 1), last = Time, sign = x.first.second;
		// cout << Time << ' ' << x.first.second << ' ' << l << ' ' << r << ' ' << Sum[1] << 
		// 	' ' << Ans << endl;
	}
	// cout << offset << ' ' << Ans << endl;
	return Ans < ((2 * n + 1) * (2 * n + 1) / 2 + 1);
}

int32_t main(){
	#ifndef ToMo
		freopen("robots.inp", "r", stdin);
		freopen("robots.out", "w", stdout);
	#endif // ToMo

	U = read(), n = read();
	for(int i = 1; i <= U + 1; ++ i) {
		int x = read(), y = read();
		int newx = x - y, newy = x + y;
		Center[i] = Point(newx, newy);
	}
	Robot = make_pair(Point(Center[U + 1].first - n, Center[U + 1].first + n),
		Point(Center[U + 1].second - n, Center[U + 1].second + n));

	// check(5);
	int l = 0, r = 2e9;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
			else r = mid - 1;
	}
	cout << l + 1 << endl;
}