//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <vector>
#include <utility>
using namespace std;


//=====================================                ---bu1th4nh
//Macros
#define task "MINSUM"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ll a, b;
int tc;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Math. Stuff
ll GCD(ll _a, ll _b)
{
    while(_b > 0)
    {
        _a %= _b;
        swap(_a, _b);
    }
    return _a;
}
vii Factorization(ll n)
{
    vii res;
    FOR(i, 2, trunc(sqrt(n)))
    {
        if(n % i == 0) res.push_back(ii(i, 0));
        while(n % i == 0) ++res.back().second, n /= i;
    }
    if(n > 1) res.push_back(ii(n, 1));
    return res;
}
bool IsPrime(ll n)
{
    if(n == 1) return true;
    FOR(i, 2, trunc(sqrt(n)))
    {
        if(n % i == 0) return false;
    }
    return true;
}

//Process
void Solve()
{
    scanf("%lld%lld", &a, &b);

    ll g = GCD(a, b);
    a /= g, b /= g;

    if(IsPrime(a) && IsPrime(b))
    {
        printf("%lld %lld\n", a, b);
        return;
    }

    vii f_a = Factorization(a), f_b = Factorization(b);

//    puts("=====================");
//    for(ii x: f_a) printf("%lld %lld\n", x.first, x.second);
//    puts("=====================");
//    for(ii x: f_b) printf("%lld %lld\n", x.first, x.second);
//    puts("=====================");

    for(ii x: f_a)
    {
        if(x.second == 1) continue;
        else if(x.second % 2 == 0)
        {
            while(a % x.first == 0) a /= x.first, --x.second;
        }
        else
        {
            while(x.second > 1 && a % x.first == 0) a /= x.first, --x.second;
        }
    }

    for(ii x: f_b)
    {
        if(x.second == 1) continue;
        else if(x.second % 2 == 0)
        {
            while(b % x.first == 0) b /= x.first, --x.second;
        }
        else
        {
            while(x.second > 1 && b % x.first == 0) b /= x.first, --x.second;
        }
    }


    printf("%lld %lld\n", a, b);

//    puts("=====================");
//    cout << a << " " << b << "\n";
//    puts("=====================");
//    for(ii x: f_a) if(x.second) printf("%lld %lld\n", x.first, x.second);
//    puts("=====================");
//    for(ii x: f_b) if(x.second) printf("%lld %lld\n", x.first, x.second);
//    puts("=====================");


}

//Multi-testdata processing
void Multitest()
{
    scanf("%d", &tc);
    while(tc--)
    {
        Solve();
    }
}

//Main Procedure
int main()
{
    FileInit();
    Multitest();
    FileClose();
    return 0;
}
