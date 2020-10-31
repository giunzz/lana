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
#include <sstream>  //erwadefwqwdfsaew4rtgrwqewaefr   --  bu1th4nh
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "BUBBLETEA"
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

const long long inf = 1000000000037;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
vvii adj;
int n, k;
vi shop;
ll res;
vvll d;


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
    int u, v, c;
	scanf("%d%d", &n, &k);

	d = vvll(n+1, vll(n+1, inf));
	adj = vvii(n+1);
	shop = vi(k);

	FOR(i, 0, k-1) scanf("%d", &shop[i]);

	FOR(i, 1, n-1)
	{
	    scanf("%d%d%d", &u, &v, &c);
	    adj[u].pb(ii(c, v));
	    adj[v].pb(ii(c, u));
	}
}

//Dijkstra
void Dijkstra(int start)
{
    priority_queue<ii, vii, greater<ii>> pq;
    ll du, uv;
    int u, v;

    pq.push(ii(0, start));
    d[start][start] = 0;

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(du != d[start][u]) continue;

        for(ii x: adj[u])
        {
            v = x.second;
            uv = x.first;

            if(d[start][v] > du + uv) pq.push(ii((d[start][v] = du + uv), v));
        }
    }
}

//Process
void Solve()
{
    FOR(i, 0, k-1) Dijkstra(shop[i]);
    sort(whole(shop));
    vb mark(n+1, true);

    res = inf;
    ll tmp;
    while(next_permutation(whole(shop)))          // ?? :D ?? Really, nigga???? vloz :v
    {
        tmp = 0;
        FOR(i, 1, k/2)
        {
            tmp = max(tmp, d[shop[i*2-1]][shop[i*2-2]]);
        }
        tmp = min(tmp, res);
    }

    cout << tmp;
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
