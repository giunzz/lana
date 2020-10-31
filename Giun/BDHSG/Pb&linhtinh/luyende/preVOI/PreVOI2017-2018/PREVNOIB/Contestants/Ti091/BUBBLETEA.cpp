#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int n,m;
const int nmax=5003;
int cl[nmax],a[nmax];
ll d[nmax];
ll cnt[nmax];
typedef pair<ll,int> li;
vector<li> g[nmax];
priority_queue<li,vector<li>,greater<li> > q;

void dijkstra()
{
    for (int i=1;i<=n;i++)
    {
        cl[i]=0;
        d[i]=LLONG_MAX;
    }
    d[1]=0;
    q.push(li(d[1],1));
    while (!q.empty())
    {
        int u=q.top().se;
        q.pop();
        if (cl[u]==1) continue;
        cl[u]=1;
        for (int i=0;i<g[u].size();++i)
        {
            int v=g[u][i].se;
            ll c=g[u][i].fi;
            if (cl[v]==0 && d[v]>d[u]+c)
            {
                d[v]=d[u]+c;
                q.push(li(d[v],v));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("BUBBLETEA.inp","r",stdin);
    freopen("BUBBLETEA.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for (int i=1;i<=n-1;i++)
    {
        int u,v; ll c;
        cin>>u>>v>>c;
        g[u].pb(li(c,v));
    }
    dijkstra();
    cout<<d[a[m]];
    return 0;
}

