#include <bits/stdc++.h>
using namespace std;

#define task "minsum"
#define inf 1123456789012345678

bool dd[112345];
int p[112345];
int f[100];
long long res,u,v;

int np;
int k;

void findPrime() {
	for (int i=2; i<=100000; ++i) 
		if (!dd[i]) {
		 	p[++np] = i;
		 	long long j = (long long) i * i;
		 	for ( ; j <= 100000; j+=i)
		 		//cerr << j << endl;
		 		dd[j] = true;
		}
}

void backtrack(int i,long long x,long long y) {
	if (i==k+1) {
		if (res > x + y) {
			u = x;
			v = y;
			res = x + y;
		}
	}
	else {
		backtrack(i+1,x*f[i],y);
		backtrack(i+1,x,y*f[i]);
	}
}

void solve() {
	int a,b;
	k = 0;
	res = inf;
	scanf("%d%d",&a,&b);
	long long c = (long long) a * b;
	for (int i=1; i<=np; ++i) 
		if (!(c%p[i])) {
			int cnt = 0;
			while (!(c%p[i])) {
				++cnt;
				c /= p[i];
			}
			if (cnt%2) f[++k] = p[i];
		}
	if (c == (long long) a * b) {
		if (a != 1) f[++k] = a;
		if (b != 1) f[++k] = b;
	}
	else if (c != 1) f[++k] = c;
	backtrack(1,1,1);
	printf("%lld %lld\n", u, v);
}

int main() {
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	findPrime();
	int t;
	scanf("%d",&t);
	while (t--) solve();
}