#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 9;

void add(int& x,int y) {
	x += y; if (x >= mod) x -= mod;
}

void sub(int& x,int y) {
	x -= y; if (x < 0) x += mod;
}

int n, mmax;
int m1, m2, m4;
int f[2][305][10005];

int main() {
	freopen("icecream.inp", "r", stdin);
	freopen("icecream.out", "w", stdout);
	scanf("%d %d %d %d %d", &n, &mmax, &m1, &m2, &m4);
	f[0][0][m2] = 1;
	int sum = m1 + m2 * 2 + m4 * 4;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i - 1 && j + m4 <= mmax; ++j) {
			for (int n2 = 0; n2 <= mmax; ++n2) if (f[0][j][n2]) {
				int n1 = (sum - (m4 + j) * 4 - n2 * 2);
				int n4 = j + m4;
				if (n1 < mmax) {
					add(f[1][j][n2], f[0][j][n2]);
				}
				if (n2 < mmax && n1) {
					add(f[1][j][n2 + 1], f[0][j][n2]);
				}
				if (n4 < mmax) {
					if (n1 && n2) {
						add(f[1][j + 1][n2 - 1], f[0][j][n2]);
					}
					else if (n1 >= 3) {
						add(f[1][j + 1][n2], f[0][j][n2]);
					}
				}
			}
		}
		for (int j = 0; j <= i && j + m4 <= mmax; ++j) {
			for (int n2 = 0; n2 <= mmax; ++n2) {
				f[0][j][n2] = f[1][j][n2];
				f[1][j][n2] = 0;
			}
		}
		sum++;
	}
	int ans = 0;
	for (int i = 0; i < 305; ++i) for (int j = 0; j < 10005; ++j) add(ans, f[0][i][j]);
	printf("%d\n", ans);
}
