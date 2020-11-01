#define taskname "ARRANGE"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <functional>
using namespace std;
typedef long long lli;
const int maxA = 1e6;
const int maxN = 1e5 + 1;
const lli infty = (lli)maxN * maxA;
int n, r;
lli a[maxN], b[maxN];
int L[4 * maxN], H[4 * maxN], leaf[maxN];

inline int ReadInt()
{
    char b;
    for (b = getchar(); b < '0' || b > '9'; b = getchar());
    int res = b - '0';
    for (b = getchar(); b >= '0' && b <= '9'; b = getchar())
        res = res * 10 + b - '0';
    return res;
}

void WriteInt(lli x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

class TSegmentTree
{
public:
    bool Disabled[4 * maxN];
    lli MM[4 * maxN], Sum[4 * maxN];
    inline virtual void Update(int x)
    {
        Sum[x] = Sum[2 * x] + Sum[2 * x + 1];
        Disabled[x] = Disabled[2 * x] && Disabled[2 * x + 1];
    }
    function<int(int)> GetA;
    function<bool(int)> GetD;
    void Build(int x)
    {
        if (L[x] == H[x])
        {
            Sum[x] = MM[x] = GetA(L[x]);
            Disabled[x] = GetD(L[x]);
        }
        else
        {
            Build(2 * x); Build(2 * x + 1);
            Update(x);
        }
    }
    void InitTree(function<int(int)> a, function<bool(int)> d)
    {
        GetA = a; GetD = d;
        Build(1);
    }
    inline void Dec(int i, int Delta)
    {
        int x = leaf[i];
        Sum[x] -= Delta;
        MM[x] -= Delta;
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
    inline virtual int FindPos() = 0;
};

class TValueManager: public TSegmentTree
{
public:
    inline void Update(int x)
    {
        TSegmentTree::Update(x);
        if (!Disabled[x])
            MM[x] = min(
                        Disabled[2 * x] ? infty : MM[2 * x],
                        Disabled[2 * x + 1] ? infty : Sum[2 * x] + MM[2 * x + 1]
                    );
    }
    inline int FindPos()
    {
        int x = 1;
        while (L[x] < H[x])
            if (!Disabled[2 * x] && MM[2 * x] == MM[x]) x *= 2;
            else x = x * 2 + 1;
        return L[x];
    }
} ValMan;

class TFindBest: public TSegmentTree
{
public:
    inline void Update(int x)
    {
        TSegmentTree::Update(x);
        if (!Disabled[x])
            MM[x] =  max(
                         Disabled[2 * x + 1] ? -infty : MM[2 * x + 1],
                         Disabled[2 * x] ? -infty : Sum[2 * x + 1] + MM[2 * x]
                     );
    }
    inline int FindPos()
    {
        int x = 1;
        while (L[x] < H[x])
            if (!Disabled[2 * x + 1] && MM[2 * x + 1] == MM[x]) x = x * 2 + 1;
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
    r = sum % n;
    b[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        a[i] -= aver;
        b[i] = b[i - 1] + a[i];
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
    ValMan.InitTree(
    [](int i) {return a[i];},
    [](int i) {return b[i] <= 0;}
    );
    FindBest.InitTree(
    [](int i) {return b[i] > 0 ? 1 : -1;},
    [](int i) {return false;}
    );
}

void Solve()
{
    lli res = 0;
    for (int i = 1; i <= n; ++i) res += abs(b[i]);
    for (int loop = r; loop > 0; --loop)
    {
        int p = FindBest.FindPos();
        res -= FindBest.MM[1];
        FindBest.SetDisabled(p);
        ValMan.Dec(p, 1);
        while (!ValMan.Disabled[1] && ValMan.MM[1] <= 0)
        {
            int q = ValMan.FindPos();
            ValMan.SetDisabled(q);
            FindBest.Dec(q, 2);
        }
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
