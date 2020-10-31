/*input
7 4 9
1 2 3 1 1 2 1
3 1 2 1
*/
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

const int N = 3005, Mod = 1000000009;
int n[2], a[2][N], k, p;
int Arr[2][N][N], hashT[2][N][N], Log2[N], Ans[N << 1], Pow[N];
pair<int, int> Min[2][12][N];

#define cin fin
#define cout fout
ifstream fin("sequence.inp");
ofstream fout("sequence.out");

pair<int, int> get(int idx, int l, int r) {
	int dis = Log2[r - l + 1];
	return min(Min[idx][dis][l], Min[idx][dis][r - (1 << dis) + 1]);
}

int getHash(int idx, int len, int l, int r) {
	int x = (hashT[idx][len][r] - (l ? (1ll * hashT[idx][len][l - 1] * Pow[r - l + 1]) : 0ll)) % Mod;
	x += (x < 0) * Mod; return x;
}

bool check(int len1, int suf1, int len0, int suf0) {
	// placing suf1 -> len1 before suf0 -> len0 is better

	int pos = 0, r = len1 - suf1 + len0 - suf0;
	for(int i = 12; i >= 0; -- i) if(pos + (1 << i) <= r) {
		pos += (1 << i);

		int x = getHash(1, len1, suf1, min(suf1 + pos - 1, len1 - 1));
		if(suf1 + pos - 1 >= len1)
			x = (1ll * x * Pow[pos - len1 + suf1] + getHash(0, len0, suf0, suf0 + (pos - (len1 - suf1)) - 1)) % Mod;

		int y = getHash(0, len0, suf0, min(suf0 + pos - 1, len0 - 1));
		if(suf0 + pos - 1 >= len0)
			y = (1ll * y * Pow[pos - len0 + suf0] + getHash(1, len1, suf1, suf1 + (pos - (len0 - suf0)) - 1)) % Mod;
		assert(x >= 0 && y >= 0);
		if(x != y) pos -= (1 << i);
	}
	if(pos == r) return 1;
	int x = (suf1 + pos > len1 - 1) ? Arr[0][len0][suf0 + suf1 + pos - len1] : Arr[1][len1][suf1 + pos];
	int y = (suf0 + pos > len0 - 1) ? Arr[1][len1][suf1 + suf0 + pos - len0] : Arr[0][len0][suf0 + pos];
	// cout << len1 << ' ' << suf1 << ' ' << len0 << ' ' << suf0 << ' ' << pos << ' ' << x << ' ' << y << endl;
	return x < y;
}

int main(){
	Log2[0] = -1, Pow[0] = 1;
	for(int i = 1; i < N; ++ i) Log2[i] = Log2[i / 2] + 1, Pow[i] = Pow[i - 1] * 1000003ll % Mod;

	cin >> n[0] >> n[1] >> k;
	for(int j = 0; j < 2; ++ j) for(int i = 1; i <= n[j]; ++ i)
		cin >> a[j][i], Min[j][0][i] = make_pair(a[j][i], i);

	for(int idx = 0; idx < 2; ++ idx)
		for(int j = 1; j < 12; ++ j) for(int i = 1; i + (1 << j) - 1 <= n[idx]; ++ i)
			Min[idx][j][i] = min(Min[idx][j - 1][i], Min[idx][j - 1][i + (1 << (j - 1))]);

	for(int idx = 0; idx < 2; ++ idx)
		for(int len = 1; len <= n[idx]; ++ len) {
			int l = 1;
			for(int cnt = len; cnt > 0; -- cnt) {
				int r = n[idx] - cnt + 1, pos = get(idx, l, r).second;
				Arr[idx][len][len - cnt] = a[idx][pos], l = pos + 1;
				if(cnt == len) hashT[idx][len][0] = Arr[idx][len][0];
					else {
						int hehh = len - cnt;
						hashT[idx][len][hehh] = (hashT[idx][len][hehh - 1] * 1000003ll + Arr[idx][len][hehh]) % Mod;
					}
			}
		}

	// for(int idx = 0; idx < 2; ++ idx) {
	// 	cout << (idx ? "b" : "a") << endl;
	// 	for(int len = 1; len <= n[idx]; ++ len) {
	// 		cout << "Len #" << len << " List: ";
	// 		for(int i = 0; i < len; ++ i) cout << Arr[idx][len][i] << ' ';
	// 			cout << endl;
	// 	}
	// }

	for(int i = 0; i < k; ++ i) Ans[i] = N;
	for(int len = 1; len <= n[0]; ++ len) {
		int lenn = k - len, l = 0;
		if(n[1] < lenn || lenn < 0) continue;

		// cout << "Len #" << len << ' ' << lenn << endl;
		vector<int> tmp;
		for(int i = 0; i < len; ++ i) {
			// cout << i << ' ' << l << ' ';
			while(l < lenn && check(lenn, l, len, i)) tmp.emplace_back(Arr[1][lenn][l ++]);
			tmp.emplace_back(Arr[0][len][i]);
			// cout << l << endl;
		}
		while(l < lenn) tmp.emplace_back(Arr[1][lenn][l ++]);
		// for(auto x : tmp) cout << x << ' ';
		// 	cout << endl;

		bool ok = 0;
		for(int i = 0; i < k; ++ i) if(Ans[i] != tmp[i]) {
			ok = (Ans[i] > tmp[i]); break;
		}
		if(ok) for(int i = 0; i < k; ++ i) Ans[i] = tmp[i];
	}
	for(int i = 0; i < k; ++ i) cout << (i ? " " : "") << Ans[i];
		cout << endl;
}