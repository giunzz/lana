#define taskname "TREE"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;
typedef long long lli;

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

const int maxN = 1e5 + 1;
typedef int TArrayN[maxN];
int n, nleaves;
TArrayN a, parent, treesize, LeafArr, HLDArr, HLDIdx, head, LB, RB;
vector<int> adj[maxN];

class TMinSegmentTree
{
public:
    int maxrange;
    int L[4 * maxN], H[4 * maxN], Sum[4 * maxN], MM[4 * maxN];
    bool Disabled[4 * maxN];
    int leaf[maxN];
    void Build(int x, int low, int high)
    {
        L[x] = low; H[x] = high;
        Sum[x] = MM[x] = 0;
        Disabled[x] = false;
        if (low == high)
            leaf[low] = x;
        else
        {
            int mid = (low + high) / 2;
            Build(x * 2, low, mid);
            Build(x * 2 + 1, mid + 1, high);
        }
    }
    void Init(int leafcount)
    {
        maxrange = leafcount;
        Build(1, 1, maxrange);
    }
    virtual void Update(int x)
    {
        Sum[x] = Sum[2 * x] + Sum[2 * x + 1];
        Disabled[x] = Disabled[2 * x] && Disabled[2 * x + 1];
        if (Disabled[x]) return;
        if (Disabled[2 * x])
            MM[x] = Sum[2 * x] + MM[2 * x + 1];
        else
            MM[x] = Disabled[2 * x + 1] ? MM[2 * x] : min(MM[2 * x], Sum[2 * x] + MM[2 * x + 1]);
    }
    inline void IncRange(int i, int Delta) //Inc i...n
    {
        if (i > maxrange) return;
        int x = leaf[i];
        Sum[x] += Delta;
        MM[x] = Sum[x];
        for (x /= 2; x > 0; x /= 2)
            Update(x);
    }
    inline void IncRange(int i, int j, int Delta) //Inc i...j
    {
        if (i > j) return;
        IncRange(i, Delta);
        IncRange(j + 1, -Delta);
    }
    inline void SetDisabled(int i)
    {
        int x = leaf[i];
        Disabled[x] = true;
        for (x /= 2; x > 0; x /= 2)
            Update(x);
    }
    inline int QueryBestPos()
    {
        int x = 1;
        while (L[x] < H[x])
            if (!Disabled[2 * x] && MM[2 * x] == MM[x]) x *= 2;
            else x = x * 2 + 1;
        return L[x];
    }
};

class TMaxSegmentTree: public TMinSegmentTree
{
public:
    virtual void Update(int x)
    {
        Sum[x] = Sum[2 * x] + Sum[2 * x + 1];
        Disabled[x] = Disabled[2 * x] && Disabled[2 * x + 1];
        if (Disabled[x]) return;
        if (Disabled[2 * x])
            MM[x] = Sum[2 * x] + MM[2 * x + 1];
        else
            MM[x] = Disabled[2 * x + 1] ? MM[2 * x] : max(MM[2 * x], Sum[2 * x] + MM[2 * x + 1]);
    }
};

TMinSegmentTree NodeMng;
TMaxSegmentTree LeafMng;

void Enter()
{
    n = ReadInt();
    for (int i = 1; i <= n; ++i)
        a[i] = ReadInt();
    for (int i = n - 1; i > 0; --i)
    {
        int x = ReadInt();
        int y = ReadInt();
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void GetParentChild(int u)
{
    for (int i = 0; i < (int)adj[u].size(); ++i)
        if (adj[u][i] == parent[u])
        {
            adj[u][i] = adj[u].back();
            adj[u].pop_back();
            break;
        }
    treesize[u] = 1;
    LB[u] = nleaves + 1;
    for (int v: adj[u])
    {
        parent[v] = u;
        GetParentChild(v);
        treesize[u] += treesize[v];
    }
    if (adj[u].empty())
    {
        ++nleaves;
        LeafArr[nleaves] = u;
    }
    RB[u] = nleaves;
}

void HLD(int u)
{
    static int HLDCnt = 0;
    ++HLDCnt;
    HLDIdx[u] = HLDCnt;
    HLDArr[HLDCnt] = u;
    int hv = -1;
    for (int v: adj[u])
        if (hv == -1 || treesize[v] > treesize[hv]) hv = v;
    if (hv != -1)
    {
        head[hv] = head[u];
        HLD(hv);
    }
    for (int v: adj[u])
        if (v != hv)
        {
            head[v] = v;
            HLD(v);
        }
}

void Init()
{
    nleaves = 0;
    parent[1] = -1;
    GetParentChild(1);

    head[1] = 1;
    HLD(1);

    LeafMng.Init(nleaves);
    for (int i = 1; i <= n; ++i)
        LeafMng.IncRange(LB[i], RB[i], 1);
    NodeMng.Init(n);
    for (int i = 1; i <= n; ++i)
    {
        int val;
        if (i == 1) val = a[HLDArr[i]];
        else val = a[HLDArr[i]] - a[HLDArr[i - 1]];
        NodeMng.IncRange(i, val);
    }
}

void ScanNegNodes()
{
    while (true)
    {
        if (NodeMng.Disabled[1] || NodeMng.MM[1] > 0) break;
        int k = NodeMng.QueryBestPos();
        NodeMng.SetDisabled(k);
        int u = HLDArr[k];
        LeafMng.IncRange(LB[u], RB[u], -2);
    }
}

void Solve()
{
    lli res = 0;
    for (int i = 1; i <= n; ++i) res += a[i];
    while (true)
    {
        ScanNegNodes();
        if (LeafMng.Disabled[1] || LeafMng.MM[1] <= 0) break;
        res -= LeafMng.MM[1];
        int i = LeafMng.QueryBestPos();
        LeafMng.SetDisabled(i);
        int u = LeafArr[i];
        while (u != -1)
        {
            int v = head[u];
            NodeMng.IncRange(HLDIdx[v], HLDIdx[u], -1);
            u = parent[v];
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
