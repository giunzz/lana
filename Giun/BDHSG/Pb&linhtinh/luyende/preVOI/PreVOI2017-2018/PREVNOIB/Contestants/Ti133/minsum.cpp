#include <bits/stdc++.h>

using namespace std;

map < int, int > f;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}
	else{
		freopen("minsum.inp", "r", stdin);
		freopen("minsum.out", "w", stdout);
	}

	int nTest;
	cin >> nTest;
	while(nTest--){
		int a, b;
		f.clear();
		cin >> a >> b;


		for(int i = 2, g = a; i * i <= g; ++i){
			while(a % i == 0){
				++f[i];
				a /= i;
			}
		}
		if(a > 1) ++f[a];

		for(int i = 2, g = b; i * i <= g; ++i){
			while(b % i == 0){
				++f[i];
				b /= i;
			}
		}
		if(b > 1) ++f[b];

		vector < int > primes;
		for(auto p : f){
			if(p.second % 2 == 1) primes.push_back(p.first);
		}

		int u = 1e9, v = 1e9;
		int len = primes.size();

		for(int mask = 0; mask < (1 << len); ++mask){
			int x = 1, y = 1;
			for(int i = 0; i < len; ++i){
				if(mask & (1 << i)) x *= primes[i];
				else y *= primes[i];
			}
			if(x + y < u + v){
				u = x;
				v = y;
			}
		}
		cout << u << " " << v << endl;
	}

	return 0;
}