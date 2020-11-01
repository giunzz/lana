#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e4 + 7;
const int maxn = 1e4 + 7;
const int inf = 1e18 + 7;
typedef pair<int,int> ii;
int cnt = 0, KQ = 0 , n, k, num[MAXN], tail[MAXN], f[MAXN], d[maxn][maxn], one[MAXN], kt[MAXN], used[MAXN], x[MAXN], vt[MAXN] , value = 0;
vector<ii> a[MAXN];
ii pa[MAXN];
void dfs(int u, int p)
{
    num[u] = ++cnt;
    for(int i = 0 ; i < a[u].size() ; i++)
    {
        int v = a[u][i].second;
        int w = a[u][i].first;
        if (v != p)
        {
            //res += w;
            pa[v].first = u;
            pa[v].second = w;
            dfs(v, u);
        }
        //res -= w;
    }
    tail[u] = ++cnt;
}

int solve(int u, int v)
{
    int han, vt;
    if (num[u] > num[v]) swap(u, v);
    if (num[u] < num[v] && num[v] < tail[v] && tail[v] < tail[u])
    {
        int res = 0, temp = v;
        while(1)
        {
            if (temp == u) break;
            res += pa[temp].second;
            temp = pa[temp].first;
        }
        return res;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        one[i] = 0;
    }
    int cur = u, dem = 0;
    while(1)
    {
        if (cur == 1) break;
        dem += pa[cur].second;
        cur = pa[cur].first;
        one[cur] = dem;
    }
    cur = v;
    dem = 0;
    while(1)
    {
        if (cur == 1) break;
        dem += pa[cur].second;
        cur = pa[cur].first;
        if (one[cur])
        {
            return one[cur] + dem;
            vt = cur;
        }
    }
}

void init()
{
    int dem = inf;
    memset(vt, 0, sizeof vt);
    for(int ii = 1 ; ii <= k ; ii++)
        vt[x[ii]] = ii;
    for(int ii = 1 ; ii <= k / 2 ; ii++)
    {
        if (x[ii] <= k / 2)
        {
            dem = min(dem, d[ii][vt[x[ii] + k / 2]]);
        }
        else
        {
            dem = min(dem, d[ii][vt[x[ii] - k / 2]]);
        }
    }
    KQ = max(KQ, dem);
}

void Try(int pos)
{
    int i;
    if (pos==k+1)
    {
        init();
        return ;
    }
    for (i=1; i<=k; i++)
        if (used[i] == false)
        {
            x[pos]=i;
            used[i]=true;
            Try(pos+1);
            used[i]=false;
        }
}

main()
{
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1 ; i <= k ; i++)
        {
            cin >> f[i];
            kt[f[i]] = 1;
        }
    for(int i = 1 ; i < n ; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            value = max(value , w);
            a[u].push_back(ii(w, v));
        }
    if (k <= 6)
    {
        dfs(1, 0);
        for(int i = 1 ; i <= k ; i++)
            for(int j = i + 1 ; j <= k ; j++)
            {
                d[i][j] = solve(f[i], f[j]);
                d[j][i] = d[i][j];
                //cout << d[i][j] << "\n";
            }
        Try(1);
        cout << KQ;
        return 0;
    }
    cout << value;
    return 0;
}
