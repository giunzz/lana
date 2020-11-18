#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 5005;

vector <int> adj[N];

int n,m;
int c[N];
int d[N];
int dp[N];

bool a[N][N];

void buildadj(int s)
{
    vector <int> dis(n + 1, -1);
    queue <int> q;
    q.push(s);
    dis[s] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        if (dis[u] == d[s]) break;
        for (int v : adj[u]) if (dis[v] < 0)
        {
            dis[v] = dis[u] + 1;
            q.push(v);
            a[s][v] = true;
        }
    }
}

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
    priority_queue <pair <int ,int>> heap;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (int) 1e9;
    }
    heap.push(mp(0, 1));
    while (heap.size())
    {
        pair <int, int> res = heap.top();
        heap.pop();
        int u = res.se;
        if (-res.fi != dp[u]) continue;
        if (u == n)
        {
            cout << dp[n];
            return;
        }
        queue <int> q;
        q.push(u);
        vector <int> dis(n + 1, - 1);
        dis[u] = 0;
        while (q.size())
        {
            int cur = q.front();
            q.pop();
            if (dis[cur] == d[u]) break;
            for (int nxt : adj[cur]) if (dis[nxt] < 0)
            {
                dis[nxt] = dis[cur] + 1;
                q.push(nxt);
                if (minimize(dp[nxt], dp[u] + c[u]))
                {
                    heap.push(mp(-dp[nxt], nxt));
                }
            }
        }
    }
    cout << dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> d[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dijkstra();
    return 0;
}
