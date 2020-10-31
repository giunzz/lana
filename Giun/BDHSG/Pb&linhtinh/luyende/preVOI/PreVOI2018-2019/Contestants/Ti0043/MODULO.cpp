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
#define taskname "MODULO"
//#define BeztDonkey

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int a, b, n;
ll k;

struct TSub1
{
    int c[64], mask;
    inline void Attemp(int i, int mod)
    {
        if (i == n)
        {
            if (mod == k)
            {
                for (int i = 0; i < n; ++i) cout << (c[i] ? a : b);
                exit(0);
            }
            return;
        }
        c[i] = 1; Attemp(i + 1, mod * 10 + a & mask);
        c[i] = 0; Attemp(i + 1, mod * 10 + b & mask);
//        c[i] = 1; Attemp(i + 1, (mod * 10 + a) % (1 << n));
//        c[i] = 0; Attemp(i + 1, (mod * 10 + b) % (1 << n));
    }
    void Solve()
    {
        mask = (1 << n) - 1;
        Attemp(0, 0);
        cout << -1;
    }
} *Sub1;

int main()
{
    #ifdef BeztDonkey
    auto start = chrono::steady_clock::now();
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);

    cin >> a >> b >> n >> k;
    Sub1 = new TSub1, Sub1->Solve();

    #ifdef BeztDonkey
    auto end = chrono::steady_clock::now();
    cerr << "In milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << '\n' << "In seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count() << '\n';
    #endif
    return 0;

}

