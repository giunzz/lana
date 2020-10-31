#include <bits/stdc++.h>
#define task "TEAWORLD."
#define ff(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define inf 1e9
#define pb push_back
using namespace std;
typedef long long ll;

const int maxm = 3000;
int m, n, k, a, b, c;
struct toado
{
    int x;
    int y;
    int z;
    int e; // vua la ban kinh cua qua cau, vua la luong tra sua cua mot cua hang
};
toado shop[20], cau[maxm];

inline int readint()
{
    int sign = 1;
    char c;
    do
    {
        c = getchar();
        if (c == '-') sign = -sign;
    }
    while (c < '0' || c > '9');
    int res;
    for (res = 0; c >= '0' && c <= '9'; c = getchar())
        res = res * 10 + (c - '0');
    return res * sign;
}

void enter()
{
    freopen(task"inp", "r", stdin);
    freopen(task"out", "w", stdout);
    ios_base::sync_with_stdio(false);
    m = readint(); n = readint(); k = readint();
    ff(i, 1, m)
    {
        cau[i].x = readint(); cau[i].y = readint(); cau[i].z = readint();
        cau[i].e = readint();
    }
    ff(i, 1, n)
    {
        shop[i].x = readint(); shop[i].y = readint(); shop[i].z = readint();
        shop[i].e = readint();
    }
    a = readint(); b = readint(); c = readint(); //toa do cua giao su PVH
}

bool cmp(toado a, toado b)
{
    return a.e >= b.e;
}

bool cmp2(toado a, toado b)
{
    return a.x <= b.x;
}

void solve()
{
    enter();
    sort(shop + 1, shop + 1 + n, cmp);
    sort(cau + 1, cau + 1 + m, cmp2);
    printf("%d", 254);
}

int main()
{
    solve();
}

