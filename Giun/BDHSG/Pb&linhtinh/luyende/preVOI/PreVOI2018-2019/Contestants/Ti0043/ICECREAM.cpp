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
#define taskname "ICECREAM"
//#define BeztDonkey

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int Mod = (int)1e9 + 9;

int n, m, m0, m1, m2;

struct TSub1
{
    int x[300], ans;
    inline void Attemp(int i)
    {
        if (i == n) { ++ans; return; }
        if (m0 < m) x[i] = 0, ++m0, Attemp(i + 1), --m0;
        if (m1 < m && m0) x[i] = 1, ++m1, --m0, Attemp(i + 1), --m1, ++m0;
        if (m2 < m)
            if (m0 && m1) x[i] = 2, ++m2, --m1, --m0, Attemp(i + 1), --m2, ++m1, ++m0;
            else if (m0 >= 3) x[i] = 2, ++m2, m0 -= 3, Attemp(i + 1), --m2, m0 += 3;
    }
    void Solve()
    {
        ans = 0;
        Attemp(0);
        cout << ans;
    }
} *Sub1;

struct TSub2
{
    int f[2][201][201][201];
    inline void Add(int &a, int b) { if ((a += b) >= Mod) a -= Mod; }
    void Solve()
    {
        bool s;
        fill_n(&f[s][0][0][0], pow(201, 3), 0);
        f[s][m0][m1][m2] = 1;
        while (--n >= 0)
        {
            s ^= 1;
            fill_n(&f[s][0][0][0], pow(201, 3), 0);
            for (int m0 = 0; m0 <= m; ++m0)
                for (int m1 = 0; m1 <= m; ++m1)
                    for (int m2 = 0; m2 <= m; ++m2)
                    {
                        int val = f[s ^ 1][m0][m1][m2];
                        if (val == 0) continue;
                        if (m0 < m) Add(f[s][m0 + 1][m1][m2], val);
                        if (m1 < m && m0) Add(f[s][m0 - 1][m1 + 1][m2], val);
                        if (m2 < m)
                            if (m1 && m0) Add(f[s][m0 - 1][m1 - 1][m2 + 1], val);
                            else if (m0 >= 3) Add(f[s][m0 - 3][m1][m2 + 1], val);
                    }
        }
        int ans = 0;
        for (int m0 = 0; m0 <= m; ++m0)
            for (int m1 = 0; m1 <= m; ++m1)
                for (int m2 = 0; m2 <= m; ++m2) Add(ans, f[s][m0][m1][m2]);
        cout << ans;
    }
} *Sub2;
int main()
{
    #ifdef BeztDonkey
    auto start = chrono::steady_clock::now();
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);

    cin >> n >> m >> m0 >> m1 >> m2;
    if (n <= 16) Sub1 = new TSub1, Sub1->Solve();
    else Sub2 = new TSub2, Sub2->Solve();

    #ifdef BeztDonkey
    auto end = chrono::steady_clock::now();
    cerr << "In milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << '\n' << "In seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count() << '\n';
    #endif
    return 0;

}

