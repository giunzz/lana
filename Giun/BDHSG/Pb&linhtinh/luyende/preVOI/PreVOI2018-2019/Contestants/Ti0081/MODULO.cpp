//Make_Sam^^
#include <bits/stdc++.h>
#define nmax 65
#define SIZE(f) int(f.size())
#define vti vector<int>
#define pii pair<int, int>
#define vtp vector<pii>
#define vtv vector<vti>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define oo 1000000009
#define MOD 1000000007
#define real double
#define Task "MODULO"
#define reset(f) memset(f, 0, sizeof f)
#define resetF(f) memset(f, 1, sizeof f)
#define resetM(f) memset(f, 60, sizeof f)

using namespace std;
typedef unsigned long long ull;
int a, b, n, k, nghiem[nmax];
bool avail[nmax];
ull P = 1;

void solve()
{
    ull res = 0;
    P = 1;
    for (int i = 1; i < n; i++) P *= 10;
    for (int i = 1; i <= n; i++){
        res += nghiem[i] * P;
        P /= 10;
    }
    if ((res % (1ull << ull(n))) == ull(k)) cout << res, exit(0);
}

void backtrack(int i)
{
    if (i > n){
        solve();
        return;
    }
    int tmp = a;
    for (int x = 1; x <= n; x++)
        if (avail[i]){
            nghiem[i] = tmp;
            avail[i] = 0;
            backtrack(i + 1);
            avail[i] = 1;
            tmp = b;
        }
}

int main()
{
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> a >> b >> n >> k;
    resetF(avail);
    backtrack(1);
    cout << -1;
}
