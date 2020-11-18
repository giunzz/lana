#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
struct state
{
    int u,num,len;
    state(){}
    state (int _u, int _num, int _len)
    {
        u = _u;
        num = _num;
        len = _len;
    }
};

const int N = 2e6 + 5;
const int oo = 2e9;

vector <pair <int, int>> adj[N];

state st[N];

int dp[N];
int id[20005][15][15];
int n,m,p,l,k,cnt_state;

bool minimize(int &a, int b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

void dijkstra()
{
    for (int i = 1; i <= cnt_state; i++)
    {
        dp[i] = oo;
    }
    priority_queue <pair <int, int>> heap;
    dp[id[1][0][0]] = 0;
    heap.push(mp(0, id[1][0][0]));
    while (heap.size())
    {
        pair <int, int> res = heap.top();
        heap.pop();
        int cur = res.se;
        if (-res.fi != dp[cur]) continue;
        int u = st[cur].u;
        int num = st[cur].num;
        int len = st[cur].len;
        for (pair <int, int> e : adj[u])
        {
            int v = e.fi;
            int w = e.se;
            int nxt = id[v][num][0];
            if (minimize(dp[nxt], dp[cur] + w))
            {
                heap.push(mp(-dp[nxt], nxt));
            }
            if (num + !len <= k)
            {
                int nxt = id[v][num + !len][(len + 1) % l];
                if (minimize(dp[nxt], dp[cur] + !len * p))
                {
                    heap.push(mp(-dp[nxt], nxt));
                }
            }
        }
    }
    int ans = oo;
    for (int i = 0; i <= k; i++)
    for (int j = 0; j < l; j++)
    {
        int cur = id[n][i][j];
        ans = min(ans, dp[cur]);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n >> m >> p >> l >> k;
    for (int i = 1; i <= m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(mp(v, w));
        adj[v].push_back(mp(u, w));
    }
    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++)
    for (int kk = 0; kk < l; kk++)
    {
        cnt_state++;
        id[i][j][kk] = cnt_state;
        st[cnt_state] = state(i, j, kk);
    }
    dijkstra();
    return 0;
}
