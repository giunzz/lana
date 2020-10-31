#include<bits/stdc++.h>
#define taskname "liondance"
#define sz(a) static_cast<int>(a.size())
using namespace std;

const int maxn = 4e3;

int tt, nT = 1;
int n, delta;
int a[maxn + 10], b[maxn + 10];
vector<int> v, ans;

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

int getbit(int k, int x)
{
    return (x >> (k - 1)) & 1;
}

void Enter()
{
    Read(n);    Read(delta);
    for (int i = 1; i <= n; ++i) Read(a[i]);
    for (int i = 1; i <= n; ++i) Read(b[i]);
    for (int i = 0; i < 1 << n; ++i)
    {
        v.clear();
        for (int j = 1; j <= n; ++j)
            if (getbit(j, i)) v.emplace_back(a[j]);
        bool ok = true;
        for (int i = 1; i < sz(v); ++i)
            if (abs(v[i] - v[i - 1]) > delta)
            {
                ok = false;
                break;
            }
        if (!ok) continue;
        for (int i = 0, j = 1; i < sz(v); ++i, ++j)
        {
            while (j <= n && v[i] != b[j]) ++j;
            if (j > n)
            {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        if (sz(v) > sz(ans)) ans = v;
        else if (sz(v) == sz(ans))
        {
            for (int i = 0; i < sz(v); ++i)
                if (v[i] < ans[i])
                {
                    ok = false;
                    break;
                }
            if (ok) ans = v;
        }
    }
    Write(sz(ans)); putchar('\n');
    for (int i = 0; i < sz(ans); ++i)
    {
        Write(ans[i]);  putchar(' ');
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
