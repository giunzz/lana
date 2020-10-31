#include <bits/stdc++.h>
using namespace std;

#define task "arrange"
#define maxN 5123
#define maxN1 112345


long long sum;
int n;
int a[maxN1];

void sub1() {
	int k = sum / n;
	long long res=0,t=0;
	for (int i=1; i<=n-1; ++i) {
		t += a[i] - k;
		res += abs(t);
	}
	printf("%lld\n", res);
}

long long f[maxN][maxN],g[maxN][maxN];

void sub2() {
	int k = sum / n;
	int x = sum % n;
	for (int i=1; i<=n-1; ++i) 
		for (int j=0; j<=x; ++j) { 
			g[i][j] = g[i-1][j] + a[i] - k;
			f[i][j] = f[i-1][j] + abs(g[i][j]);
			if (j && f[i][j] > f[i-1][j-1] + abs(g[i][j]-1)) {
				--g[i][j];
				f[i][j] = f[i-1][j-1] + abs(g[i][j]);
			}
			// cerr << i << " " << j << " " << f[i][j] << " " << g[i][j] << endl;  
		}
	printf("%lld\n", min(f[n-1][x],f[n-1][x-1]));
}

int main() {
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	scanf("%d",&n);
	for (int i=1; i<=n; ++i) {
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if (!(sum%n)) sub1();
	else sub2();
}