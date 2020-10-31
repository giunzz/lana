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
#define task "MODULO"
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
    template<class T> T __abs(T &x)
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
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ll a, b, n, k;
vvi vect;
vi pow2;


mt19937_64 prng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> die;

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
	scan(a);
	scan(b);
	scan(n);
	scan(k);

	vect = vvi(2, vi(65, 1LL));      //vect[0] = (a * 10^i) % 2^n
	pow2 = vi(65, 1LL);             //vect[1] = (b * 10^i) % 2^n
}

//Check
void Preps()
{
    vect[0][0] = a * 1LL;
    vect[1][0] = b * 1LL;

	FOR(i, 0, 63) pow2[i] = (1LL << i);
	FOR(i, 1, 63)
	{
	    FOR(j, 0, 1)
	    {
	        vect[j][i] = (vect[j][i-1] * 10LL) % pow2[n];
	    }
	}

//	FOR(i, 0, 1)
//	{
//	    FOR(j, 0, 40) cerr << vect[i][j] << sp;
//	    cerr << el;
//	}
}


//Process
void Subtask1()
{
    FORl(state, 1, (1 << n))
    {
        ll prx = 0LL;
        FORl(i, 0, n) prx = (prx + vect[getBit(state, i)][i]) % pow2[n];
        if(prx == k)
        {
            FORb(i, n-1, 0) putchar(vect[getBit(state, i)][0]+'0');
            return;
        }
    }
    cout << -1 << el;
}


//Subtask???: Casinoization
void Random()
{
    FOR(iRD, 1, 500000)
    {
        ll prx = 0LL;
        int rd = die(prng);
        FORl(i, 0, n) prx = (prx + vect[rd][i]) % pow2[n];
        if(prx == k)
        {
            FORb(i, n-1, 0) putchar(vect[rd][0]+'0');
            return;
        }
    }
    cout << -1 << el;
}


//Output
void Solve()
{
    if(n <= 22) Subtask1();
    else
    {
        die = uniform_int_distribution<> (0, 1);
        if(die(prng)) Random();
        else cout << -1 << el;
    }
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Preps();
    Solve();
    return 0;
}
