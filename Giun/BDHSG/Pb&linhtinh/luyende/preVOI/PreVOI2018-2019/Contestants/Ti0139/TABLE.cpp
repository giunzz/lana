//POTK29 :)
#include <bits/stdc++.h>
#define maxn 505
#define mod 1000000007
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define task "TABLE"
#define fo(i, a, b) for(int i = a; i <= b; i++)
using namespace std;

int m, n, k, a[maxn][maxn], c[maxn][maxn], b[maxn*maxn], mn, trc[maxn*maxn];
vector <int> d[maxn*maxn];

int doi(int i, int j)
{
    return (i-1)*n + j;
}

void bfss(int x, int y)
{
    memset(trc, 0, sizeof trc);
    memset(b, -60, sizeof b);
    b[x] = 0;
    queue <int> q;
    q.push(x);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : d[u])
        {
            if(b[v] < b[u] + c[u][v])
            {
                b[v] = b[u] + c[u][v];
                trc[v] = u;
            }
            if(v < y) q.push(v);
        }
    }
}

void bfs(int x, int y, int z)
{
    fo(i, 1, m*n)
        b[i] = -1e12;
    b[x] = 0;
    queue <int> q;
    q.push(x);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : d[u])
        {
             b[v] = max(b[v], b[u] + c[u][v]);
             if(v < y && v != z) q.push(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d%d", &m, &n, &k);
    fo(i, 1, m)
        fo(j, 1, n)
        {
            scanf("%d", &a[i][j]);
            int x = doi(i, j), y = doi(i+1, j), z = doi(i, j+1);
            if(i < m) d[x].pb(y);
            if(j < n) d[x].pb(z);
            c[x][y] = c[x][z] = a[i][j];
        }

    while(k--)
    {
        int u, v, p, q, y, res;
        scanf("%d%d%d%d", &u, &v, &p, &q);
        y = doi(p, q);
        res = y;
        mn = 1e9;
        bfss(doi(u, v), y);
        while(trc[res] != doi(u, v))
        {
            res = trc[res];
            bfs(doi(u, v), y, res);
            mn = min(b[y], mn);
        }
        cout << mn + a[p][q] << '\n';
    }
    return 0;
}
