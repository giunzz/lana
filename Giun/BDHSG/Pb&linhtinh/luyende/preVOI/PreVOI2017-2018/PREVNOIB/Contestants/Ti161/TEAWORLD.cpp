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
#define task "TEAWORLD"
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
struct P3D
{
    int x, y, z, value;
    P3D(int __x, int __y, int __z)
    {
        x = __x, y = __y, z = __z;
    }
    P3D(int __x, int __y, int __z, int __val)
    {
        x = __x, y = __y, z = __z, value = __val;
    }
    P3D()
    {
        x = y = z = value = 0;
    }
};
struct P2D
{
    int x, y, value;
    P2D(int __x, int __y)
    {
        x = __x, y = __y;
    }
    P2D(int __x, int __y, int __val)
    {
        x = __x, y = __y, value = __val;
    }
    P2D(P3D __k)
    {
        if(__k.y == 0 && __k.z == 0) x = __k.x;
        if(__k.y != 0 && __k.z == 0) x = __k.x, y = __k.y;
        value = __k.value;
    }
    P2D()
    {
        x = y = value = 0;
    }

    bool IsCollinear(const P2D &b, const P2D &c)
    {
        int ax = this->x, ay = this->y;
        return ( (c.x - ax)*(b.y - ax) == (b.x - ax)*(c.y - ay) );
    }
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<P2D> vp2d;
typedef vector<P3D> vp3d;
int m, n, k, check_y, check_z;
vp3d shop, ball;
P3D initial;

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
    int u, v, w, c;
    scanf("%d%d%d", &m, &n, &k);

    check_y = check_z = 0;
    shop = vp3d(n+1);
    ball = vp3d(m+1);


    FOR(i, 1, m)
    {
        scanf("%d%d%d%d", &u, &v, &w, &c);
        check_y += v, check_z += w;
        ball[i] = P3D(u, v, w, c);
    }

    FOR(i, 1, n)
    {
        scanf("%d%d%d%d", &u, &v, &w, &c);
        check_y += v, check_z += w;
        shop[i] = P3D(u, v, w, c);
    }

    scanf("%d%d%d", &initial.x, &initial.y, &initial.z);

}

//Subtask 1   --  One-dimension
void Sub1()
{
    vii vect, vect2;
    FOR(i, 1, m) vect.push_back(ii(ball[i].x, ball[i].value));
    FOR(i, 1, n) vect2.push_back(ii(shop[i].x, shop[i].value));


}

//Subtask 2   --  Two-dimension
void Sub2()
{
    //
}

//Subtask 3   --  Three-dimension
void Sub3()
{
    //
}

//Output
void Solve()
{
    if(check_y == 0 && check_z == 0) Sub1();
    else cout << -1;
}

//Main Procedure
int main()
{
//    Enter();
//    Solve();

    FileInit();
    cout << -1;
    FileClose();
    return 0;
}
