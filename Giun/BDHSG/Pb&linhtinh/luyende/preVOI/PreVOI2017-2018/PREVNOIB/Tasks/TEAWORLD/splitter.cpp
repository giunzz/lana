#include <bits/stdc++.h>
using namespace std;

int N, M, K;

int cnt = 0;

string filename(int subtask, int test) {
	stringstream ss;
	ss << subtask << "-" << setw(2) << setfill('0') << test;
	return ss.str();
}

struct Point {
	int x, y, z, t;
} B[2005], L[2005], E;

void print(ostream &os, Point &p, int s) {
	os << p.x << ' ' << (s <= 1 ? 0 : p.y) << ' ' << (s <= 2 ? 0 : p.z);
}

int sq(int x) { return x * x; }

int val(int d, int x, int y, int z, int s) {
	int p = 
		sq(x - E.x) + 
		sq((s <= 1 ? 0 : y - E.y)) + 
		sq((s <= 2 ? 0 : z - E.z));
	if (p == 0) return d;
	return ceil(d / 1.0 / p);
}

int main() {
	while (cin >> N >> M >> K) {
		if (!N && !M && !K) break;
		++cnt;
		for (int i = 0; i < N; ++i) cin >> B[i].x >> B[i].y >> B[i].z >> B[i].t;
		for (int i = 0; i < M; ++i) cin >> L[i].x >> L[i].y >> L[i].z >> L[i].t;
		cin >> E.x >> E.y >> E.z;
		for (int s = 1; s <= 3; ++s) {
			ofstream out("tests/" + filename(s, cnt) + ".inp");
			out << N << ' ' << M << ' ' << K << endl;
			for (int i = 0; i < N; ++i) {
				print(out, B[i], s); out << ' ' << B[i].t << endl;
			}
			for (int i = 0; i < M; ++i) {
				print(out, L[i], s); out << ' ' << val(L[i].t, L[i].x, L[i].y, L[i].z, s) << endl;
			}
			print(out, E, s); out << endl;
			out.close();
			system(("./sol < tests/" + filename(s, cnt) + ".inp > tests/" + filename(s, cnt) + ".out").c_str());
		}
		cout << cnt << " " << "done" << " (N = " << N << " M = " << M << ")" << endl;
	}
}