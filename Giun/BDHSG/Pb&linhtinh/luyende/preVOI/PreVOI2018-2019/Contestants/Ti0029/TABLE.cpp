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
#define task "TABLE"
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
const int nextx[2] = {1, 0};
const int nexty[2] = {0, 1};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef complex<int> pt;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<pt> vpt;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vpt> vvpt;
vvi a, dp, dp2;
int m, n, k;

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

#define x real()
#define y imag()


//Enter
void Enter()
{
    scan(m);
    scan(n);
    scan(k);

    a = dp = vvi(m+1, vi(n+1, 0LL));
    FOR(i, 1, m)
    {
        FOR(j, 1, n) scan(a[i][j]);
    }

//    FOR(i, 1, m)
//    {
//        FOR(j, 1, n) cerr << (a[i][j]) << sp;
//        cerr << el;
//    }


}

//Subtask 1 - m, n, k < 30: Try all possible cases
ll ST1BFS(pt start, pt dest)
{
    dp = vvi(m+1, vi(n+1, 0LL));
    queue<pt> que;
    pt cur, tmp;

    que.push(start);
    dp[start.x][start.y] = a[start.x][start.y];
//    cerr << dp[start.x][start.y] << el;
//    cerr << a[start.x][start.y] << el;
//    cerr << a[1][1] << el;
    while(!que.empty())
    {
        cur = que.front();
        que.pop();

        FOR(i, 0, 1)
        {
            tmp = cur + pt(nextx[i], nexty[i]);
            if(tmp.x <= m && tmp.y <= n)
            {
                if(dp[tmp.x][tmp.y] == 0) que.push(tmp);
                maximize(dp[tmp.x][tmp.y], dp[cur.x][cur.y] + a[tmp.x][tmp.y]);
            }
        }


//        FOR(i, 1, m)
//        {
//            FOR(j, 1, n) cerr << dp[i][j] << sp;
//            cerr << el;
//        }
//        getchar();

    }

    return dp[dest.x][dest.y];
}
void Subtask1()
{
    int srcx, srcy, dstx, dsty;
    ll res, tp;

    FOR(iQuery, 1, k)
    {
        res = 100000000000000LL;
        tp = 0LL;

        scan(srcx);
        scan(srcy);
        scan(dstx);
        scan(dsty);

        FOR(i, srcx, dstx)
        {
            FOR(j, srcy, dsty)
            {
                if((i != srcx || j != srcy) && (i != dstx || j != dsty))
                {
                    swap(a[i][j], tp);
                    minimize(res, ST1BFS(pt(srcx, srcy), pt(dstx, dsty)));
                    swap(a[i][j], tp);
                }
            }
        }

        print(res);
        putchar(el);
    }
}

//All the rest of the problem: BFS + 2nd maximum path.
ll ST2BFS(pt start, pt dest)
{
    dp = dp2 = vvi(m+1, vi(n+1, 0LL));
    queue<pt> que;
    pt cur, tmp;

    que.push(start);
    dp[start.x][start.y] = dp2[start.x][start.y] = a[start.x][start.y];

    while(!que.empty())
    {
        cur = que.front();
        que.pop();

        FOR(i, 0, 1)
        {
            tmp = cur + pt(nextx[i], nexty[i]);
            if(tmp.x <= m && tmp.y <= n)
            {
                if(dp[tmp.x][tmp.y] == 0) que.push(tmp);
                if(dp[tmp.x][tmp.y] < dp[cur.x][cur.y] + a[tmp.x][tmp.y])
                {
                    dp2[tmp.x][tmp.y] = dp[tmp.x][tmp.y];
                    dp[tmp.x][tmp.y] = dp[cur.x][cur.y] + a[tmp.x][tmp.y];
                }
                else maximize(dp2[tmp.x][tmp.y], dp[cur.x][cur.y] + a[tmp.x][tmp.y]);
            }
        }

//        FOR(i, 1, m)
//        {
//            FOR(j, 1, n) cerr << dp2[i][j] << sp;
//            cerr << el;
//        }
//        getchar();

    }

    return dp2[dest.x][dest.y];
}
void SubtaskAll()
{
    ll res;
    int srcx, srcy, dstx, dsty;
    FOR(iQuery, 1, k)
    {
        scan(srcx);
        scan(srcy);
        scan(dstx);
        scan(dsty);

        res = ST2BFS(pt(srcx, srcy), pt(dstx, dsty));
        print(res);
        putchar(el);
    }
}


//Output
void Solve()
{
    if(m <= 30 && n <= 30 && k <= 30) Subtask1();
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
