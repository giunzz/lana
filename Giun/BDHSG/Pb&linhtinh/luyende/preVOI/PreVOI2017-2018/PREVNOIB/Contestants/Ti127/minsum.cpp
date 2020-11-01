#include <bits/stdc++.h>
using namespace std;

const int sq = 1e5 + 5;

int T, A, B;

int main() {
	freopen("minsum.inp", "r", stdin);
	freopen("minsum.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> A >> B;
		int valA = 1, valB = 1;
		int oldA = A, oldB = B;
		A = A / __gcd(oldA, oldB);
		B = B / __gcd(oldA, oldB);
		oldA = A, oldB = B;
		for(int i = 2; i <= sqrt(oldA); ++i) {
			int cnt = 0;
			while(A % i == 0) A /= i, cnt++;
			if(cnt & 1) valA *= i;
		}
		valA *= A;
		for(int i = 2; i <= sqrt(oldB); ++i) {
			int cnt = 0;
			while(B % i == 0) B /= i, cnt++;
			if(cnt & 1) valB *= i;
		}
		valB *= B;
		cout << valA << ' ' << valB << '\n';
	}
}

