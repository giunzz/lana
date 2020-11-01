
#define task "teaworld"
#define st first
#define nd second
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct node{
    int x, y, z, r;
    node(){}
    node(int _x, int _y, int _z, int _r) : x(_x), y(_y), z(_z), r(_r) {}
};

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const int maxN = 20;
const int maxM = 2005;

int n, m, k, sx, sy, sz, x[maxN], xmin, xmax, LLx, RRx, ans;
vector<int> choose;
node circle[maxM];
node shop[maxN];

template<class T> inline maximize(T& a, const T& b){ return a < b ? a = b, 1 : 0; }
template<class T> inline minimize(T& a, const T& b){ return a > b ? a = b, 1 : 0; }

bool inn(int p, int L, int R){
    return L <= p && p <= R;
}

void Try(int i, int sum){
    if (i == n+1){
        if (sum == 0 || sum <= ans) return;

        int cnt = 0;
        for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        if (x[j] == 1){
            LLx = circle[i].x-circle[i].r;
            RRx = circle[i].x+circle[i].r;
            xmin = min(sx, shop[j].x);
            xmax = max(sx, shop[j].x);
            if ((inn(LLx, xmin, xmax) && !inn(RRx, xmin, xmax)) || (!inn(LLx, xmin, xmax) && inn(RRx, xmin, xmax))) ++cnt;
            if (cnt > k) return;
        }
        if (cnt != k) return;
        maximize(ans, sum);
        return;
    }
    x[i] = 0; Try(i+1, sum);
    x[i] = 1; Try(i+1, sum + shop[i].r);
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);

    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= m; ++i) scanf("%d%d%d%d", &circle[i].x, &circle[i].y, &circle[i].z, &circle[i].r);
    for (int i = 1; i <= n; ++i) scanf("%d%d%d%d", &shop[i].x, &shop[i].y, &shop[i].z, &shop[i].r);
    scanf("%d%d%d", &sx, &sy, &sz);

    ans = 0;
    Try(1, 0);
    printf("%d\n", ans);

	return 0;
}

