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


//=====================================
//Macros
#define task "ARRANGE"
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
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ll sum, res;
int n;
vll a;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
	scanf("%d", &n);
	a = vll(n+1, 0LL);

	FOR(i, 1, n)
	{
	    scanf("%lld", &a[i]);
	    sum += a[i];
	}
}

//Subtask 1
void Subtask1()
{
    res = 0;
    ll bal = sum / ll(n);
    FOR(i, 1, n)
    {
        if(a[i] >= bal) res += a[i] - bal;
    }
    cout << res;
}

//Subtask 2
void Subtask2()
{
    //
}

//Subtask 3
void Subtask3()
{
    //
}


//Process
void Solve()
{
    if(n <= 1)
    {
        cout << 0;
        return;
    }
    else  Subtask1();
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
