
#define task "tree"
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

const int maxN = 5005;
int n, a[maxN], x[maxN], par[maxN], degout[maxN];

template<class T> inline maximize(T& a, const T& b){ return a < b ? a = b, 1 : 0; }
template<class T> inline minimize(T& a, const T& b){ return a > b ? a = b, 1 : 0; }

void sub1(){
    vector<int> leaf;
    int tmp, ans;

    leaf.clear();
    for (int i = 1; i <= n; ++i) if (degout[i] == 0) leaf.push_back(i);

    ans = maxN * maxN;

    for (int i = 0; i < (1 << leaf.size()); ++i){
        for (int j = 1; j <= n; ++j) x[j] = 0;
        for (int j = 0; j < leaf.size(); ++j){
            tmp = (i >> j) & 1;
            for (int u = leaf[j]; u != 0; u = par[u]) x[u] += tmp;
        }
        tmp = 0;
        for (int j = 1; j <= n; ++j) tmp += abs(a[j] - x[j]);
        minimize(ans, tmp);
    }
    printf("%d\n", ans);
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);

    int u, v;

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n-1; ++i){
        scanf("%d%d", &u, &v);
        ++degout[u];
        par[v] = u;
    }

    sub1();

	return 0;
}

