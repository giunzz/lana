#include<bits/stdc++.h>
#define taskname "sequence"
#define sz(a) static_cast<int>(a.size())
using namespace std;

const int maxn = 6e3 + 10;

int tt, nT = 1;
int a[maxn], b[maxn], pa[maxn], pb[maxn];
int nxa[maxn][maxn], nxb[maxn][maxn];
int n, m, L;
unordered_map<int, int> mm;

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
    Read(n);    Read(m);    Read(L);
    vector<int> V;
    for (int i = 1; i <= n; ++i)
    {
        Read(a[i]);
        V.emplace_back(a[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        Read(b[i]);
        V.emplace_back(b[i]);
    }
    sort(V.begin(), V.end());
    for (int i = 1; i <= n; ++i)
    {
        int x = upper_bound(V.begin(), V.end(), a[i]) - V.begin();
        mm[x] = a[i];
        a[i] = x;
    }
    for (int i = 1; i <= m; ++i)
    {
        int x = upper_bound(V.begin(), V.end(), b[i]) - V.begin();
        mm[x] = b[i];
        b[i] = x;
    }
    fill(&pa[1], &pa[n + m] + 1, n + 1);
    for (int i = n; i >= 0; --i)
    {
        for (int j = 1; j <= n + m; ++j) nxa[i][j] = pa[j];
        if (i) pa[a[i]] = i;
    }
    fill(&pb[1], &pb[n + m] + 1, m + 1);
    for (int i = m; i >= 0; --i)
    {
        for (int j = 1; j <= n + m; ++j) nxb[i][j] = pb[j];
        if (i) pb[b[i]] = i;
    }
    V.clear();
    for (int k = 0, x = 0, y = 0; k < L;)
    {
        for (int j = 1; j <= n + m; ++j)
        {
            int u = nxa[x][j];
            int v = nxb[y][j];
            if (n - u + m - y >= L - k - 1 && n - x + m - v >= L - k - 1 && u <= n && v <= m)
            {
                if (u - x <= v - y)
                {
                    V.emplace_back(mm[a[u]]);
                    x = u;  ++k;
                    break;
                }
                V.emplace_back(mm[b[v]]);
                y = v;  ++k;
                break;
            }
            if (n - u + m - y >= L - k - 1 && u <= n)
            {
                V.emplace_back(mm[a[u]]);
                x = u;  ++k;
                break;
            }
            if (n - x + m - v >= L - k - 1 && v <= m)
            {
                V.emplace_back(mm[b[v]]);
                y = v;  ++k;
                break;
            }
        }
    }
    for (int i = 0; i < min(sz(V), L); ++i)
    {
        Write(V[i]);    putchar(' ');
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
