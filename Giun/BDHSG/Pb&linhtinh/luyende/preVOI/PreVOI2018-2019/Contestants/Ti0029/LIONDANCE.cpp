//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <utility>

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
#endif // __cplusplus

using namespace std;

// #define DEBUG
#define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "LIONDANCE"
#define maxinp ()
#define fi first
#define se second
#define pb push_back
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define r_whole(x) x.rbegin(),x.rend()
#define FOR(i, x, y) for(auto i=x; i<=y; ++i)
#define FORl(i, x, y) for(auto i=x; i<y; ++i)
#define FORb(i, x, y) for(auto i=x; i>=y; --i)
#define FORlb(i, x, y) for(auto i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP()                        \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
    freopen(task".err", "w", stderr);   \
}

//Macroes - Optional
#ifdef OPTIONAL_FEATURE
    #define pc(x) putchar(x)
    #define gc() getchar()
#endif



//=====================================
//Auxilary Functions and Fast I/O
#ifdef OPTIONAL_FEATURE
    template<class T, class R> T max(T &x, R &y)
    {
        return x > y ? x : y;
    }
    template<class T, class R> T min(T &x, R &y)
    {
        return x < y ? x : y;
    }
    template<class T, class R> void maximize(T &x, R y)
    {
        x = x > y ? x : y;
    }
    template<class T, class R> void minimize(T &x, R y)
    {
        x = x < y ? x : y;
    }
    template<class T> int getBit(T &x, int i)
    {
        return ((x >> i) & 1) == 1;
    }
    template<class T> T __abs(T x)
    {
        return (x = (x < 0) ? -x : x);
    }
#endif
//Fast I/O
template<class T> inline void scan(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret = (neg) ? -ret : ret;

    #ifdef DEBUG
        cerr << "FastScan Diagnostic: " << ret << el;
    #endif
}
template<class T> void print(T x)
{
    if(x < 0)
    {
        putchar('-');
        x *= -1;
    }

    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

//=====================================
//Constants



//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi a, b, res;
int n, delt;

//=====================================
//Functions and procedures
//File I/O and utilities
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    #ifdef DEBUG
        FILEOP_DEBUG()
    #else
        FILEOP()
    #endif
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}


//Enter
void Enter()
{
    scan(n);
    scan(delt);

    a = b = vi(n+1, 0);
    FOR(i, 1, n) scan(a[i]);
    FOR(i, 1, n) scan(b[i]);
}

//Subtask 1: Try all configurations as possible
void Parse(vi &smp)
{
    FORl(i, 1, smp.size())
    {
        if(__abs(smp[i] - smp[i-1]) > delt) return;
    }
    int ptr = 0;
    FORl(i, 0, smp.size())
    {
        while(ptr < n && smp[i] != b[ptr]) ++ptr;
        if(ptr >= n) return;
        if(smp[i] == b[ptr]) ++ptr;
    }

    if(smp.size() > res.size()) res = smp;
    else if(smp.size() == res.size())
    {
        if(res < smp) res = smp;
    }
}
void Subtask1()
{
    FORl(i, 0, n) a[i] = a[i+1]; a.pop_back();
    FORl(i, 0, n) b[i] = b[i+1]; b.pop_back();

    FORl(state, 0, (1 << n))
    {
        vi smp;
        FORl(i, 0, n) if(getBit(state, i))
        {
            smp.push_back(a[i]);
        }
        Parse(smp);
    }

    cout << res.size() << el;
    for(int x: res) cout << x << sp;
}


//All the rest of the problem: n <= 4000: LCS X LIS
void SubtaskAll()
{
    vvi dp(n+1, vi(n+1, 0));
    vi smp;

    FOR(i, 1, n)
    {
        if(a[i] == b[1]) dp[i][1] = 1;
        if(a[1] == b[i]) dp[1][i] = 1;
    }

    FOR(i, 2, n)
    {
        FOR(j, 2, n)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }

    int i = n, j = n;
    while(i && j)
    {
        if(a[i] == b[j])
        {
            smp.push_back(a[i]);
            --i, --j;
        }
        else if(dp[i][j-1] == dp[i][j]) --j;
        else if(dp[i-1][j] == dp[i][j]) --i;
    }
    smp.push_back(0);
    reverse(whole(smp));

//    for(int x: smp) cerr << x << sp; cerr << el;

    vi trce(smp.size(), 0);
    vi dp2(smp.size(), 0);
    dp2[1] = 1;

    FORl(i, 1, smp.size())
    {
        dp2[i] = 1;
        FORl(j, 1, i) if(__abs(smp[i] - smp[j]) <= delt)
        {
            if(dp2[i] <= dp2[j] + 1)
            {
                dp2[i] = dp2[j] + 1;
                trce[i] = j;
            }
        }
    }

    int xx = max_element(whole(dp2)) - dp2.begin();
    print(dp2[xx]); putchar(el);

    while(xx)
    {
        res.push_back(smp[xx]);
        xx = trce[xx];
    }

    reverse(whole(res));
    for(int x: res) print(x), putchar(sp);
}

//Output
void Solve()
{
    if(n <= 20) Subtask1();
    else SubtaskAll();
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
