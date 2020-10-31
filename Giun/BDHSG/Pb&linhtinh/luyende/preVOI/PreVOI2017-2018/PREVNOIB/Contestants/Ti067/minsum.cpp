
#define task "minsum"
#define st first
#define nd second
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const int maxN = 1e5;
int n, m, x[maxN], y[maxN], dx[maxN], dy[maxN];
long long a, b, g, tmp, ans, ansa, ansb;

template<class T> inline maximize(T& a, const T& b){ return a < b ? a = b, 1 : 0; }
template<class T> inline minimize(T& a, const T& b){ return a > b ? a = b, 1 : 0; }

long long gcd(long long a, long long b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

void phantich_a(){
    long long a_base = a;
    g = 2; n = 0;
    while (g*g <= a_base){
        if (a % g == 0){
            x[++n] = g;
            dx[n] = 0;
            while (a%g == 0){
                ++dx[n];
                a /= g;
            }
        }
        ++g;
    }
    if (a > 1){
        x[++n] = a;
        dx[n] = 1;
    }
}

void phantich_b(){
    long long b_base = b;
    g = 2; m = 0;
    while (g*g <= b_base){
        if (b % g == 0){
            y[++m] = g;
            dy[m] = 0;
            while (b%g == 0){
                ++dy[m];
                b /= g;
            }
        }
        ++g;
    }
    if (b > 1){
        y[++m] = b;
        dy[m] = 1;
    }
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);

	int tc;
	scanf("%d", &tc);

	while (tc--){
		scanf("%lld%lld", &a, &b);

        g = gcd(a, b);
        a /= g; b /= g;

        phantich_a();
        phantich_b();

        tmp = 1;
        for (int i = 1; i <= n; ++i) tmp = tmp * (dx[i]%2 ? x[i] : 1);
        for (int i = 1; i <= m; ++i) tmp = tmp * (dy[i]%2 ? y[i] : 1);

        ans = tmp+1; ansa = tmp; ansb = 1;

        for (int i = 1; (LL) i*i <= tmp; ++i)
        if (tmp%i == 0 && minimize(ans, tmp/i + i)){
            ansa = tmp/i;
            ansb = i;
        }

		printf("%lld %lld\n", ansa, ansb);
	}

	return 0;
}

