#include <stdio.h>
#include <queue>
#include <string.h>
#include <cmath>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define pb push_back

using namespace std;

const int N = 5002;
int n, A[N], cha[N], x, y, cnt[N], dem, cnt1, c[N], res = 1e9, f[N][N], demcon[N];
bool inqueue[N];
vector <int> b, a[N];
queue <int> hd;

void fr()
{
    freopen("TREE.inp", "r", stdin);
    freopen("TREE.out", "w", stdout);
}

void DFS(int u)
{
    fti(i, 0, int(a[u].size() - 1)) {
        if(a[u][i] == cha[u]) continue;
        cha[a[u][i]] = u;
        ++ cnt[u];
        DFS(a[u][i]);
        demcon[u] += demcon[a[u][i]];
    }
    if(!cnt[u]) demcon[u] = 1;
}

void inp()
{
    scanf("%d", &n);
    fti(i, 1, n) scanf("%d", &A[i]);
    fti(i, 1, n - 1) scanf("%d %d", &x, &y), a[x].pb(y), a[y].pb(x);
    DFS(1);
    fti(i, 1, n) if(!cnt[i]) ++ dem, b.pb(i);
}

void proc1()
{
    int X;
    fti(p, 0, (1 << dem) - 1) {
        cnt1 = 0;
        memset(inqueue, false, sizeof(inqueue));
        fti(i, 0, dem - 1) c[b[i]] = (p >> i) & 1;
        fti(i, 0, dem - 1) hd.push(b[i]);
        while(!hd.empty()) {
            X = hd.front();
            hd.pop();
            cnt1 += abs(c[X] - A[X]);
            if(!cha[X]) break;
            if(!inqueue[cha[X]]) hd.push(cha[X]), inqueue[cha[X]] = true, c[cha[X]] = 0;
            c[cha[X]] += c[X];
        }
        res = min(res, cnt1);
    }
    printf("%d\n", res);
}

void DFS2(int u)
{
    int m1 = 0, m2 = 0;
    if(!cnt[u]) {
        f[u][1] = abs(A[u] - 1);
        f[u][0] = A[u];
        return;
    }
    fti(i, 0, int(a[u].size() - 1)) {
        if(a[u][i] == cha[u]) continue;
        if(!m1) m1 = a[u][i];
        else m2 = a[u][i];
        DFS2(a[u][i]);
    }
    fti(i, 0, demcon[u])
        fti(j, i - demcon[m2], demcon[m1])
            f[u][i] = min(f[u][i], f[m1][j] + f[m2][i - j]);
    fti(i, 0, demcon[u]) f[u][i] += abs(A[u] - i);

}

void proc2()
{
    fti(i, 0, n) fti(j, 0, dem) f[i][j] = 1e9;
    DFS2(1);
    fti(i, 0, dem) res = min(res, f[1][i]);
    printf("%d\n", res);
}

int main()
{
    fr();
    inp();
    if(dem <= 13) proc1();
    else proc2();
    return 0;
}
