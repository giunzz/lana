#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e5 + 5;
const long long INF = (long long) 1e18;

int t;
long long x, y;
vector <long long> p;
map <long long, int> cntx, cnty;
map <long long, int> :: iterator itx, ity;

inline void fact(long long n, map <long long, int> &f) {
	for (int i = 2; i * i <= n; i++) {
    	if (n % i == 0) {
    		p.push_back(i);
    		while (n % i == 0) {
        		n /= i;
        		f[i]++;
      		}
      	}
    }
    if (n != 1) {
    	p.push_back(1);
     	f[1]++;
     }
    p.push_back(n);
  	f[n]++;
}

inline void reset() {
	cntx.clear();
	cnty.clear();
	p.clear();
}

inline long long power(long long a, int n) {
	long long r = 1;
	while (n) {
		if (n & 1) r = r * a;
		a = a * a;
		n >>= 1;
	}
	return r;
}

int main() {
	freopen("MINSUM.inp", "r", stdin); freopen("MINSUM.out", "w", stdout);
	scanf("%d", &t);
    while (t--) {
    	scanf("%lld %lld", &x, &y);
    	fact(x, cntx);
    	fact(y, cnty);
    	sort(p.begin(), p.end()); p.resize(distance(p.begin(), unique(p.begin(), p.end())));
    	int n = p.size();
    	long long resx = x, resy = y;
    	long long ans = INF;
    	for (int mask = 0; mask < (1 << n); mask++) {
    		long long xx = 1, yy = 1;
    		for (int i = 0; i < n; i++)
    			if ((mask >> i) & 1) {
    				xx *= power(p[i], (cntx[p[i]] + cnty[p[i]] + 1) / 2);
    				yy *= power(p[i], (cntx[p[i]] + cnty[p[i]]) / 2);
    			} else {
    				xx *= power(p[i], (cntx[p[i]] + cnty[p[i]]) / 2);
    				yy *= power(p[i], (cntx[p[i]] + cnty[p[i]] + 1) / 2);
    			}
    		long long gcd = __gcd(xx, yy);
    		xx /= gcd;
    		yy /= gcd;
    		if (ans > xx + yy) {
    			ans = xx + yy;
    			resx = xx;
    			resy = yy;
    		}
    	}
    	printf("%lld %lld\n", resx, resy);
    	reset();
    }
	return 0;
}

/*
2
4 5
4 6
*/