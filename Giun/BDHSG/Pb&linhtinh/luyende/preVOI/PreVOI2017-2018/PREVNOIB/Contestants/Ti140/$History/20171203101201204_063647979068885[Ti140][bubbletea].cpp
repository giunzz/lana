#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int maxn = 5e4+2;
typedef pair<int,int> ii;
int n,k,a[maxn],len[maxn],h[maxn],l;
int s[100],x[100];
long long ans = 1e16;
vector<ii> d[maxn];
int p[maxn][20];
void Enter()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= k; i++) scanf("%d",&a[i]);
    for (int j = 1; j <= n; j++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        d[u].push_back(ii(w,v));
        d[v].push_back(ii(w,u));
    }
}
void BFS()
{
    queue<int> q;
    q.push(1); len[1] = 1;
    h[1] = 0;
    while (q.size() > 0)
    {
        int u = q.front(); q.pop();
        for (int i = 0; i < d[u].size(); i++)
        {
            int v = d[u][i].se;
            if (len[v] > 0) continue;
            p[v][0] = u;
            h[v] = h[u]+1;
            len[v] = d[u][i].fi + len[u];
            q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) len[i]--;
}
void Init()
{
    l = log2(n);
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= n; j++)
        p[j][i] = p[p[j][i-1]][i-1];
}
int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u,v);
    for (int i = l; i >= 0; --i)
        if (h[p[u][i]] >= h[v]) u = p[u][i];
    if (u == v) return v;
    for (int i = l; i >= 0; --i)
        if (p[u][i] != p[v][i])
    {
        u = p[u][i];
        v = p[v][i];
    }
    return p[u][0];
}
void upd_ans()
{
    long long tmp = 0;
    for (int i = 1; i < k; i++)
        for (int j = i + 1;j <= k; j++)
        if (x[i] == x[j])
        {
            long long h = len[a[i]] + len[a[j]] - 2*len[LCA(a[i],a[j])];
            if (tmp < h) tmp = h;
        }
    ans = min(ans,tmp);
    /*if (tmp == 4)
    {
        for (int i = 1; i <= k; i++) cout<<x[i]<<' ';
        cout<<endl;
    }*/
}
void Try(int i)
{
    for (int j = 1; j <= k/2; j++)
    {
        if (s[j] == 2) continue;
        x[i] = j;
        s[j]++;
        if (i == k) upd_ans();
        else Try(i+1);
        s[j]--;
    }
}
int main()
{
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    Enter();
    BFS();
    Init();
    Try(1);
    cout<<ans<<endl;
}
