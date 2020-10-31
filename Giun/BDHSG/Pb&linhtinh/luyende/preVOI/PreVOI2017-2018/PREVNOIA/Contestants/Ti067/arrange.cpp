
#define task "arrange"
#define st first
#define nd second
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const int maxN = 1e5 + 5;
stack<int> st;
int n, x, a[maxN];

template<class T> inline maximize(T& a, const T& b){ return a < b ? a = b, 1 : 0; }
template<class T> inline minimize(T& a, const T& b){ return a > b ? a = b, 1 : 0; }

void sub1(){
	stack<int> st;
	int j, tmp;
	LL ans = 0;

	for (int i = 1; i <= n; ++i)
	if (a[i] < x) st.push(i);

	for (int i = n; i >= 1; --i)
		while (a[i] >= x+1 && !st.empty()){
			j = st.top();
			tmp = min(a[i]-x, x-a[j]);
			ans += (LL) tmp * abs(i-j);
			a[j] += tmp;
			a[i] -= tmp;
			if (a[j] == x) st.pop();
	}

	printf("%lld\n", ans);
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);

	LL sum = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		sum += a[i];
	}

	x = sum/n;

	sub1();

	return 0;
}

