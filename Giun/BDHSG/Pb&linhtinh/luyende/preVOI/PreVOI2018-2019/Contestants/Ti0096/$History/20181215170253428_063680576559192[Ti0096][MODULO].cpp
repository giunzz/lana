#include <bits/stdc++.h>

using namespace std;

int A, B, N;
int64_t K;
uint64_t mod;
void zEnter()
{
    scanf("%d%d%d%I64d", &A, &B, &N, &K);
    mod = (1LL << N);
}

uint64_t zMulti(int64_t a, int64_t b)
{
    a %= mod; b %= mod;
    int64_t q = (long double)(a*b)/mod;
    int64_t r = a*b - mod*q;
    if (r < 0) r += mod;
    return r;
}

const int maxn = 5e6 + 5;
int dist[maxn], pd[maxn], pe[maxn], q[maxn], L, R;
int64_t d[maxn];
map<int64_t, int> mem;
int n;

int zFindPoint(int64_t x)
{
    if (mem[x]) return mem[x];
    mem[x] = ++n;
    d[n] = x;
    return n;
}

void zBFS()
{
    n = 0;
    L = 1; R = 0;
    int xp = zFindPoint(0);
    q[++R] = xp;
    dist[xp] = 1;
    while (L <= R)
    {
        if (n > 5e6) return;
        int u = q[L++], v;
        int64_t Vu = d[u], Vv;
        Vv = (zMulti(Vu, 10) + A)%mod;
        v = zFindPoint(Vv);
        if (dist[v] == 0)
        {
            dist[v] = dist[u] + 1;
            pd[v] = u; pe[v] = A;
            if (Vv == K) return;
            q[++R] = v;
        }
        Vv = (zMulti(Vu, 10) + B)%mod;
        v = zFindPoint(Vv);
        if (dist[v] == 0)
        {
            dist[v] = dist[u] + 1;
            pd[v] = u; pe[v] = B;
            if (Vv == K) return;
            q[++R] = v;
        }
    }
}

int ans[maxn];
void zSolve()
{
    zBFS();
    int T = zFindPoint(K);
    if (dist[T] == 0)
    {
        puts("-1");
        return;
    }
    int u = T;
    while (dist[u] != 1)
    {
        ans[dist[u] - 1] = pe[u];
        u = pd[u];
    }
    for (int i = 1; i <= dist[T] - 1; ++i) putchar(ans[i] + '0');
}

#define task "MODULO"
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    zEnter();
    zSolve();
}
