#include<bits/stdc++.h>
#define taskname "table"
using namespace std;

const int maxn = 3e2;
const int oo = 1e9 + 7;

int tt, nT = 1;
int n, m, Q;
typedef int Matrix[maxn + 10][maxn + 10];
Matrix a, s, t, f, g;

template<typename T>
void Read(T &x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); !isdigit(c); c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); isdigit(c); c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template<typename T>
void Write(T x)
{
    if (x < 0)
    {
        putchar('-');
        Write(-x);
        return;
    }
    if (x > 9) Write(x / 10);
    putchar(x % 10 + '0');
}

void Enter()
{
    Read(n);    Read(m);    Read(Q);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) Read(a[i][j]);
    while (Q--)
    {
        int sx, sy, tx, ty;
        Read(sx);   Read(sy);   Read(tx);   Read(ty);
        for (int i = sx; i <= tx; ++i)
            for (int j = sy; j <= ty; ++j)
                if (i == sx && j == sy) s[i][j] = a[i][j];
                else
                {
                    s[i][j] = -oo;
                    if (i > sx) s[i][j] = max(s[i][j], s[i - 1][j] + a[i][j]);
                    if (j > sy) s[i][j] = max(s[i][j], s[i][j - 1] + a[i][j]);

                }
        for (int i = tx; i >= sx; --i)
            for (int j = ty; j >= sy; --j)
                if (i == tx && j == ty) t[i][j] = a[i][j];
                else
                {
                    t[i][j] = -oo;
                    if (i < tx) t[i][j] = max(t[i][j], t[i + 1][j] + a[i][j]);
                    if (j < ty) t[i][j] = max(t[i][j], t[i][j + 1] + a[i][j]);
                }
        for (int i = sx; i <= tx; ++i)
            for (int j = sy; j <= ty; ++j)
            {
                if (j > sy) f[i][j] = max(f[i][j - 1], s[i][j] + t[i][j] - a[i][j]);
                else f[i][j] = s[i][j] + t[i][j] - a[i][j];
                if (i > sx) g[i][j] = max(g[i - 1][j], s[i][j] + t[i][j] - a[i][j]);
                else g[i][j] = s[i][j] + t[i][j] - a[i][j];
            }
        int ans = oo;
        for (int i = sx; i <= tx; ++i)
            for (int j = sy; j <= ty; ++j)
            {
                if (i == sx && j == sy) continue;
                if (i == tx && j == ty) continue;
                int hold = -oo;
                if (i > sx && j < ty) hold = max(hold, g[i - 1][j + 1]);
                if (i < tx && j > sy) hold = max(hold, f[i + 1][j - 1]);
                ans = min(ans, hold);
            }
        Write(ans); putchar('\n');
    }
}

void Init()
{

}

void Solve()
{

}

void PrintRes()
{

}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);
    if (ifstream("test.inp"))
    {
        freopen("test.inp", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else if (ifstream(taskname".inp"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    //Read(nT);
    for (tt = 1; tt <= nT; ++tt)
    {
        Enter();
        Init();
        Solve();
        PrintRes();
    }
}
