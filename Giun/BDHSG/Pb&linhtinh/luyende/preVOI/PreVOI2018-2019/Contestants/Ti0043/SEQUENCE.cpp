#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
#include<cstring>
#include<iomanip>
#include<string>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
#include<cstring>
#include<iomanip>
#include<string>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
#include<functional>
#include<chrono>
//#include<windows.h>
//#include<direct.h>
#include<random>
#include<sstream>

#define y0 asdahsdlkahsdad
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define taskname "SEQUENCE"
//#define BeztDonkey

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int M = 3009, N = 105;

static int f[N << 1][N][N], trace[N << 1][N][N], x[M], y[M], m, n, k;
vector<int> xy;
typedef array<int, 210> TArray;
static TArray Next1[N], Next2[N];
map<int, int> s1[N], s2[N];

inline bool Minimize(int &a, int b) { return a > b ? a = b, 1 : 0; }

int main()
{
    #ifdef BeztDonkey
    auto start = chrono::steady_clock::now();
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);

    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) cin >> x[i], xy.push_back(x[i]);
    for (int j = 1; j <= n; ++j) cin >> y[j], xy.push_back(y[j]);
    sort(xy.begin(), xy.end());
    xy.erase(unique(xy.begin(), xy.end()), xy.end());
    for (int i = 1; i <= m; ++i) x[i] = upper_bound(xy.begin(), xy.end(), x[i]) - xy.begin();
    for (int j = 1; j <= n; ++j) y[j] = upper_bound(xy.begin(), xy.end(), y[j]) - xy.begin();
//    for (int i = 1; i <= m; ++i) cout << x[i] << ' ';
//    cout << '\n';
//    for (int i = 1; i <= n; ++i) cout << y[i] << ' ';
//    cout << '\n';
    for (int i = 2; i <= m + 1; ++i)
    {
        //Next1[i] = Next1[i - 1]; Next1[i][x[i - 1]] = i - 1;
        s1[i] = s1[i - 1]; s1[i][x[i - 1]] = i - 1;
    }
    for (int j = 2; j <= n + 1; ++j)
    {
        //Next2[j] = Next2[j - 1], Next2[j][y[j - 1]] = j - 1;
        s2[j] = s2[j - 1]; s2[j][y[j - 1]] = j - 1;
    }
    //for (int i = 1; i <= m + 1; ++i, cout << '\n')
    //    for (auto &p : s1[i]) cout << p.first << ' ' << p.second << ' ';
    fill_n(&f[0][0][0], sizeof f / sizeof f[0][0][0], M);
    f[0][m + 1][n + 1] = 0;
    for (int a = 0; a < k; ++a)
        for (int b = m + 1; b > 0; --b)
            for (int c = n + 1; c > 0; --c)
            {
                if (f[a][b][c] >= M) continue;
                for (auto &p : s1[b])
                    if (Minimize(f[a + 1][p.second][c], p.first))
                        trace[a + 1][p.second][c] = b;
                for (auto &p : s2[c])
                    if (Minimize(f[a + 1][b][p.second], p.first))
                        trace[a + 1][b][p.second] = c + m + 1;
            }

    int b, c, val = M;
    for (int _b = 1; _b <= m + 1; ++_b)
        for (int _c = 1; _c <= n + 1; ++_c)
            if (Minimize(val, f[k][_b][_c])) b = _b, c = _c;
    //cout << b << ' ' << c << ' '<< val << '\n';
    for (int a = k; a > 0; --a)
    {
        int t = trace[a][b][c];
        if (t <= m + 1) cout << xy[x[b] - 1] << ' ', b = t;
        else cout << xy[y[c] - 1] << ' ', c = t - m - 1;
    }

    #ifdef BeztDonkey
    auto end = chrono::steady_clock::now();
    cerr << "In milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << '\n' << "In seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count() << '\n';
    #endif
    return 0;

}

