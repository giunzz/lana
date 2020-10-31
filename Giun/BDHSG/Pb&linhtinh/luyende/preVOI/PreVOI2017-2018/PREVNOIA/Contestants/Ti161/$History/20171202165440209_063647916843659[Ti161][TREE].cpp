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
#define task "TREE"
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
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi val, par, leaf, new_val;
int n, res;
vb IsLeaf;
vvi adj;

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

    int u, v;
    adj = vvi(n+1);
    par = val = new_val = vi(n+1, 0);

    FOR(i, 1, n) scanf("%d", &val[i]);

    FOR(i, 1, n-1)
    {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        par[v] = u;
    }

    FOR(i, 1, n) if(adj[i].size() == 0) leaf.push_back(i);
}

//Subtask 1  --    Dynamic Programming using Bitmask
int GetBit(int __x, int __k)   // Retrieve the __k-th bit of __x, 0-indexed
{
    return ((__x >> __k) & 1);
}
void DFS(int u)
{
    for(int v: adj[u])
    {
        new_val[u] += new_val[v];
        DFS(v);
    }
}
void Sub1()
{
    int nLeaf = leaf.size();



//    puts("==========DEBUG==========");
//    cout << nLeaf << "\n\n";
//    for(int x: leaf) printf("%d ", x);
//    puts("");
//    puts("=========================");




    res = 1000000007;
    FOR(mask, 0, (1 << nLeaf) - 1)
    {
        new_val = vi(n+1, 0);
        FORl(i, 0, nLeaf) new_val[leaf[i]] = GetBit(mask, i);

        DFS(1);

        int tmp1 = 0, tmp2 = 0;
        FOR(i, 1, n)
        {
            tmp1 += val[i];
            tmp2 += new_val[i];
        }

        res = min(res, abs(tmp1 - tmp2));


//        puts("==========DEBUG==========");
//
//        FORb(i, nLeaf-1, 0) printf("%d", GetBit(mask, i));
//        puts("");
//        for(int x: new_val) printf("%d ", x);
//        puts("");
//        cout << res << "\n";
//
//        puts("=========================");


    }
    cout << res;
}



//Subtask 2   --
void DFS_S2(int u)
{
    int r;
    if(adj[u].size() == 1)       //
    {
        int v = adj[u][0];
        if(IsLeaf[v])
        {
            res += min( abs(val[u] - 1), abs(val[u] - 0)  );
        }
        else
        {
            res += abs(val[v] - val[u]);
        }
    }
    if(adj[u].size() == 2)       //
    {
        int v1 = adj[u][0];
        int v2 = adj[u][1];
        if(IsLeaf[v1] && IsLeaf[v2])
        {
            int x1 = abs(val[u] + val[v1] + val[v2]);
            int x2 = abs(val[u] + val[v1] + val[v2] - 1 - 1);
            int x3 = abs(val[u] + val[v1] + val[v2] - 2 - 2);

            if(x1 < x2)
            {
                new_val[v1] = new_val[v2] = new_val[u] = 0;
                if(x1 > x3) new_val[v1] = new_val[v2] = 1, new_val[u] = 2;
            }
            else
            {
                new_val[v1] = 0, new_val[v2] = new_val[u] = 1;
                if(x2 > x3) new_val[v1] = new_val[v2] = 1, new_val[u] = 2;
            }

            res += min(min(x2, x3), x1);

        }
        else if(IsLeaf[v1] && (!IsLeaf[v2]))
        {
            DFS(v2);
            int x1 = abs(val[u] + val[v1] + val[v2]);

        }
    }

}
void Sub2()
{
    new_val = val;
    IsLeaf = vb(n+1, false);
    for(int x: leaf) IsLeaf[x] = true;

}


//Subtask 3   --
void Sub3()
{

}





//Process
void Solve()
{
    Sub1();
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
