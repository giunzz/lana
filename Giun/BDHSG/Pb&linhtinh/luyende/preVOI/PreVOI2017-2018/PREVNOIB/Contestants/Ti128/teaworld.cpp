/*input
1 2 0
0 0 0 1
-1 0 0 5
2 0 0 100
1 0 0

12 5 4
0 10 0 1
1 5 0 2
1 4 0 2
0 0 0 2
10 0 0 1
3 -1 0 2
5 -1 0 2
10 10 0 15
0 -10 0 1
10 -10 0 1
-10 -10 0 1
10 10 0 1
0 10 0 240
10 0 0 200
10 -2 0 52
-10 0 0 100
1 1 0 2
0 0 0
*/
#include <bits/stdc++.h>
using namespace std;

const long long N = 2005;

long long x[N], y[N], r[N], num[N], mark[N], used[N], m, n, k;
int ans = 0;
pair<long long, long long> pos[N];

long long Sq(long long a){
	return a * a;
}

vector<long long> calc(long long index){
	vector<long long> v;

	long long A = pos[index].second - pos[n + 1].second, B = pos[n + 1].first - pos[index].first;
	long long C = - (pos[index].first * A + pos[index].second * B);
	for(long long i = 1; i <= m; ++i){
		if(mark[i]) continue;
		if(A == 0){ 
			if(y[i] - r[i] <= pos[index].second && pos[index].second <= y[i] + r[i]){
				long long c = Sq(x[i]) + Sq(pos[index].second - y[i]) - Sq(r[i]);
				long long a = 1, b = -2 * x[i];
				if(b * b < 4 * a * c) continue;
			
				double delta = sqrtl(b * b - 4 * a * c);
				double x2 = (delta - b) / (2.0 * a), x1 = - (delta + b) / (2.0 * a);

				int l = min(pos[index].first, pos[n + 1].first), r = max(pos[index].first, pos[n + 1].first);

				if(l <= x1 && x2 <= r) continue;
				if(l > x2 || r < x1) continue;

				v.push_back(i), mark[i] = 1;
			}
			continue;
		}

		long long a = Sq(A) + Sq(B), b = 2 * (B * C - x[i] * A * B + Sq(A) * y[i]);
		long long c = Sq(C) - 2 * x[i] * A * C - Sq(A) * (Sq(r[i]) - Sq(x[i]) - Sq(y[i]));

		if(b * b < 4 * a * c) continue;
		double delta = sqrtl(b * b - 4 * a * c);
		double x2 = (delta - b) / (2.0 * a), x1 = - (delta + b) / (2.0 * a);

		int l = min(pos[index].first, pos[n + 1].first), r = max(pos[index].first, pos[n + 1].first);
		if(l <= x1 && x2 <= r) continue;
		if(l > x2 || r < x1) continue;

		v.push_back(i), mark[i] = 1;
	}
	return v;
}

void backtrack(long long pos, long long count, int sum){
	if(pos <= n + 1){
		ans = max(ans, sum);
		return;
	}

	for(long long i = 1; i <= n; ++i)
		if(used[i] == 0){
			used[i] = 1;
			backtrack(pos + 1, count, sum);
			
			vector<long long> v = calc(i);
			if(count + (long long)v.size() <= k) backtrack(pos + 1, count + (long long)v.size(), sum + num[i]);

			used[i] = 0;
			while(v.size()) mark[v.back()] = 0, v.pop_back();
		}
}

int main(){
	#ifndef ToMo
		freopen("teaworld.inp", "r", stdin);
		freopen("teaworld.out", "w", stdout);
	#endif

	cin >> m >> n >> k;
	for(long long i = 1; i <= m; ++i){
		long long Z; cin >> x[i] >> y[i] >> Z >> r[i];
	}

	for(long long i = 1; i <= n; ++i){
		long long Z, x, y;
		cin >> x >> y >> Z >> num[i];
		pos[i] = make_pair(x, y);
	}

	cin >> pos[n + 1].first >> pos[n + 1].second;
	backtrack(1, 0, 0);
	printf("%d\n", ans);
}