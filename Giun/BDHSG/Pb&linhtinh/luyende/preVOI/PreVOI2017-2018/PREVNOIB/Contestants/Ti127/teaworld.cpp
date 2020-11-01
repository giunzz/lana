#include <bits/stdc++.h>
using namespace std;

const int N = 20, M = 2005;
const double pi = acos(-1), eps = 1e-9;

struct Data {
	double x, y, z, r;
};

int n, m, k;
double xs, ys, zs;
vector<int> era[1 << N];
Data cir[M], point[N];
bool check[M];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("teaworld.inp", "r", stdin);
	freopen("teaworld.out", "w", stdout);
	cin >> m >> n >> k;
	for(int i = 0; i < m; ++i) {
		double x, y, z, r;
		cin >> x >> y >> z >> r;
		cir[i] = {x, y, z, r};
	}
	for(int i = 0; i < n; ++i) {
		double x, y, z, r;
		cin >> x >> y >> z >> r;
		point[i] = {x, y, z, r};
	}
	cin >> xs >> ys >> zs;
	int ans = 0;
	for(int i = 1; i < (1 << n); ++i) {
		int pos, cur = 0;
		for(int j = 0; j < n; ++j) if((1 << j) & i) pos = j, cur += point[j].r;
		int last = i ^ (1 << pos);
		for(int j = 0; j < m; ++j) check[j] = false;
		for(int j = 0; j < era[last].size(); ++j) check[era[last][j]] = true;
		for(int j = 0; j < m; ++j) {
			if(check[j]) { era[i].push_back(j); continue; }
			double A = hypot(cir[j].x - xs, cir[j].y - ys);
			double B = hypot(point[pos].x - xs, point[pos].y - ys);
			double C = hypot(cir[j].x - point[pos].x, cir[j].y - point[pos].y);
			if(A <= cir[j].r + eps && C > cir[j].r + eps) {
				era[i].push_back(j); continue;
			}
			if(A <= cir[j].r + eps && C <= cir[j].r + eps) continue;
			double goc1 = asin(cir[j].r / A);
			double goc2 = acos((A * A + B * B - C * C) / (A * B) / 2);
			double b = -A*2*cos(goc2), a = 1, c = A * A - cir[j].r * cir[j].r;
			double delta = b * b - 4 * a * c;
			double dis = min((- b - sqrt(delta)) / (2 * a), (- b + sqrt(delta)) / (2 * a));
			if(B >= dis - eps && goc2 <= goc1 + eps) era[i].push_back(j);
		}
		if(era[i].size() <= k) ans = max(ans, cur);
	}
	cout << ans;
}