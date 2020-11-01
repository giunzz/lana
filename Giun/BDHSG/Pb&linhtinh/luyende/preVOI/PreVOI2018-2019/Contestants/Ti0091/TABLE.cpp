// He always smiles :)
#include <bits/stdc++.h>
#define maxn 305
#define mod 1000000007
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define task "TABLE"
#define ll long long
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
int m, n, k, a[maxn][maxn], sum[maxn][maxn], d[maxn][maxn];
pii par[maxn][maxn];
queue<pii> qu;
void loang(int u, int v, int p, int q)
{
    qu.push({u, v});
    reset(sum);
    reset(par);
    sum[u][v] = a[u][v];
    while(!qu.empty())
    {
        pii x = qu.front();
        qu.pop();
        if(x.f < p){
        if(sum[x.f][x.s] + a[x.f+1][x.s] > sum[x.f+1][x.s] && d[x.f +1][x.s]==0)
            sum[x.f+1][x.s] = sum[x.f][x.s] + a[x.f+1][x.s], par[x.f+1][x.s] = x;
             qu.push({x.f+1, x.s});
        }
        if(x.s < q){
        if(sum[x.f][x.s] + a[x.f][x.s+1] > sum[x.f][x.s+1] && d[x.f][x.s+1]==0)
            sum[x.f][x.s+1] = sum[x.f][x.s] + a[x.f][x.s+1], par[x.f][x.s+1] = x;
        qu.push({x.f, x.s+1});
        }
    }
}
pii cam(int u, int v, int p, int q)
{
    pii ochon;
    int x, y, ma = 0;
    while(par[p][q].f != u && par[p][q].s != v)
    {
        x = par[p][q].f, y = par[p][q].s;
        if(a[x][y] > ma) ma = a[x][y], ochon = {x, y};
        p = x, q = y;
    }
    if(a[p][q] > ma) ma = a[p][q], ochon = {p, q};
    return ochon;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> m >> n >> k;
    for (int i = 1 ; i <= m ; i ++ )
        for (int j = 1 ; j <= n ; j ++ ) cin >> a[i][j];
    for (int u, v, p, q, i = 1 ; i <= k ; i ++ )
    {
        cin >> u >> v >> p >> q;
        loang(u, v, p, q);
        pii ca = cam(u, v, p, q);
        d[ca.f][ca.s] = 1;
        loang(u, v, p, q);
        d[ca.f][ca.s] = 0;
        cout << sum[p][q] << endl;
    }
    return 0;
}
