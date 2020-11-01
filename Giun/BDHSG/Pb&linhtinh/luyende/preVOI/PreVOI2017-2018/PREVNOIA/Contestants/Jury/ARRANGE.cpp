#define taskname "ARRANGE"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;
typedef long long lli;
const int maxA = 1e6;
const int maxN = 1e5 + 1;
const lli infty = (lli)maxN * maxA;
int n, m;
lli a[maxN], b[maxN], c[maxN];
int L[4 * maxN], H[4 * maxN], leaf[maxN];

template <typename T>
inline void Minimize(T& Target, T Value)
{
    if (Target > Value) Target = Value;
}

template <typename T>
inline void Maximize(T& Target, T Value)
{
    if (Target < Value) Target = Value;
}

inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int res = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        res = res * 10 + c - '0';
    return res;
}

void WriteInt(lli x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

struct TValueManager
{
    bool Disabled[4 * maxN];
    lli Min[4 * maxN], Sum[4 * maxN];
    inline void Update(int x)
    {
        Sum[x] = Sum[2 * x] + Sum[2 * x + 1];
        Disabled[x] = Disabled[2 * x] && Disabled[2 * x + 1];
        if (Disabled[x]) return;
        Min[x] = Disabled[2 * x] ? infty : Min[2 * x];
        if (!Disabled[2 * x + 1]) Minimize(Min[x], Sum[2 * x] + Min[2 * x + 1]);
    }
    void Build(int x)
    {
        if (L[x] == H[x])
        {
            Sum[x] = Min[x] = a[L[x]];
            Disabled[x] = c[L[x]] <= 0;
        }
        else
        {
            Build(2 * x); Build(2 * x + 1);
            Update(x);
        }
    }
    inline void Dec(int i)
    {
        int x = leaf[i];
        --Sum[x];
        --Min[x];
        for (x /= 2; x > 0; x /= 2)
            Update(x);
    }
    inline void SetDisabled(int i)
    {
        int x = leaf[i];
        Disabled[x] = true;
        for (x /= 2; x > 0; x /= 2)
            Update(x);
    }
    inline int FindMin()
    {
        int x = 1;
        while (L[x] < H[x])
            if (!Disabled[2 * x] && Min[2 * x] == Min[x]) x *= 2;
            else x = x * 2 + 1;
        return L[x];
    }
} ValMan;

struct TFindBest
{
    bool Disabled[4 * maxN];
    int Max[4 * maxN], Sum[4 * maxN];
    inline void Update(int x)
    {
        Sum[x] = Sum[2 * x] + Sum[2 * x + 1];
        Disabled[x] = Disabled[2 * x] && Disabled[2 * x + 1];
        if (Disabled[x]) return;
        Max[x] = Disabled[2 * x + 1] ? -maxN : Max[2 * x + 1];
        if (!Disabled[2 * x]) Maximize(Max[x], Sum[2 * x + 1] + Max[2 * x]);
    }
    void Build(int x)
    {
        Disabled[x] = false;
        if (L[x] == H[x])
            Sum[x] = Max[x] = c[L[x]] > 0 ? 1 : -1;
        else
        {
            Build(2 * x);
            Build(2 * x + 1);
            Update(x);
        }
    }
    inline void Dec2(int i)
    {
        int x = leaf[i];
        Sum[x] -= 2;
        Max[x] -= 2;
        for (x /= 2; x > 0; x /= 2)
            Update(x);
    }
    inline void SetDisabled(int i)
    {
        int x = leaf[i];
        Disabled[x] = true;
        for (x /= 2; x > 0; x /= 2)
            Update(x);
    }
    inline int FindMax()
    {
        int x = 1;
        while (L[x] < H[x])
            if (!Disabled[2 * x + 1] && Max[2 * x + 1] == Max[x]) x = x * 2 + 1;
            else x *= 2;
        return L[x];
    }
} FindBest;

void Enter()
{
    n = ReadInt();
    lli sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = ReadInt();
        sum += a[i];
    }
    lli aver = sum / n;
    m = sum % n;
    c[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        a[i] -= aver;
        c[i] = c[i - 1] + a[i];
    }
}

void BuildRange(int x, int low, int high)
{
    L[x] = low; H[x] = high;
    if (low == high)
        leaf[low] = x;
    else
    {
        int middle = (low + high) / 2;
        BuildRange(x * 2, low, middle);
        BuildRange(x * 2 + 1, middle + 1, high);
    }
}

void Init()
{
    BuildRange(1, 1, n);
    ValMan.Build(1);
    FindBest.Build(1);
}

void Solve()
{
    fill_n(&b[1], n, 0);
    for (int loop = m; loop > 0; --loop)
    {
        int p = FindBest.FindMax();
        ++b[p];
        FindBest.SetDisabled(p);
        ValMan.Dec(p);
        while (!ValMan.Disabled[1] && ValMan.Min[1] <= 0)
        {
            int q = ValMan.FindMin();
            ValMan.SetDisabled(q);
            FindBest.Dec2(q);
        }
    }
    lli res = 0;
    for (int i = 1; i <= n; ++i)
    {
        res += abs(a[i] - b[i]);
        if (i < n) a[i + 1] += a[i] - b[i];
    }
    WriteInt(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Init();
    Solve();
}
