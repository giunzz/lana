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
#define task "GIFTS"
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
int pos_l, pos_r, k, n;
vll psum;
vi vect;
ll res;

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
	scanf("%d%d", &n, &k);

	psum = vll(n+1, 0LL);
	vect = vi(n+1, 0);
	pos_l = pos_r = 0;

	FOR(i, 1, n) scanf("%d", &vect[i]);

	FOR(i, 1, n) psum[i] = psum[i-1] + vect[i];
}

//Process
void Solve()
{
    ll max_val = -1;
    FOR(i, k, n)
    {
        ll tmp = psum[i] - psum[i-k];
        if(max_val < tmp)
        {
            max_val = tmp;
            pos_l = i - k + 1;
            pos_r = i;
        }
    }

    psum = vll(n+1, 0LL);
    FOR(i, pos_l, pos_r) vect[i] = 0;
	FOR(i, 1, n) psum[i] = psum[i-1] + vect[i];

    max_val = -1;
    FOR(i, k, n)
    {
        ll tmp = psum[i] - psum[i-k];
        if(max_val < tmp)
        {
            max_val = tmp;
            pos_l = i - k + 1;
            pos_r = i;
        }
    }

    cout << max_val;
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    FileClose();
    return 0;
}
