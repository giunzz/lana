#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 111539786;

struct Matrix {
	int n, m;
	vector <vector <int>> mat;
	Matrix() {}
	Matrix(int _n, int _m) {
		this -> n = _n;
		this -> m = _m;
		mat.assign(n, vector <int>(m, 0));
	}
};

Matrix operator * (Matrix a, Matrix b) {
	int p = a.n, q = a.m, r = a.m;
	Matrix c = Matrix(p, r);
	for (int k = 0; k < q; ++k) {
		for (int i = 0; i < p; ++i) {
			for (int j = 0; j < r; ++j) {
				(c.mat[i][j] += a.mat[i][k] * b.mat[k][j]) %= MOD;
			}
		}
	}
	return c;
}

Matrix modPow(Matrix a, int n) {
	Matrix res = a; n--;
	while (n) {
		if (n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

int machine[25][3];
	int n;
	string s;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("ADSTR.INP", "r", stdin);
	// freopen("ADSTR.OUT", "w", stdout);


	while (cin >> n >> s) {
		int m = s.size();
		memset(machine, 0, sizeof machine);
		Matrix trans = Matrix(m, m);
		s = ' ' + s;
		for (int i = 0; i < m; ++i) {
			for (int nxt = 0; nxt < 2; ++nxt) {
				if (s[i + 1] - '0' == nxt) machine[i][nxt] = i + 1;
				else {
					for (int j = 1; j < i; ++j) if (s.substr(1, j) == s.substr(i - j + 1, j) && s[j + 1] - '0' == nxt)
						machine[i][nxt] = max(machine[i][nxt], j + 1);
					if (s[1] - '0' == nxt) machine[i][nxt] = max(machine[i][nxt], 1LL);
				}
				if (machine[i][nxt] != m) {
					trans.mat[machine[i][nxt]][i] = 1;
				}
				// cerr << "machine[" << i << "][" << nxt << "] : " << machine[i][nxt] << endl;
			}
		}
		Matrix F0 = Matrix(m, 1);
		F0.mat[0][0] = 1;
		F0 = modPow(trans, n) * F0;
		int res = 0;
		for (int i = 0; i < m; ++i) {
			res = res + F0.mat[i][0];
			res %= MOD;
		}
		cout << res << endl;
	}
	

	return 0;
}