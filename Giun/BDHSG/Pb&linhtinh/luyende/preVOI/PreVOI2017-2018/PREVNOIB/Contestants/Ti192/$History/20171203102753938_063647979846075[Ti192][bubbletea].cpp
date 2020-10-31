#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i<b; i++)
typedef long long ll;
const int N=5e4+5;
const ll base=1e16;
typedef pair<int,ll>ii;
typedef pair<ii,int>iii;
int n,k,x[N],u,v,dx[N],kt;
ll c,kq,f[N],s;
vector<iii>ke[N];
ll bfs(int u, int s)
{
    queue <int> q;
    q.push(u);
    f[u]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        FORD(i,0,ke[u].size())
        {
            int v=ke[u][i].first.first;
            ll w=ke[u][i].first.second;
            int t=ke[u][i].second;
            if (!dx[t])
            {
                dx[t]=1;
                f[v]=f[u]+w;
                if (v==s) return f[v];
                q.push(v);
            }
        }
    }
    return base;
}
int main()
{
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    FOR(i,1,k) cin >> x[i];
    FOR(i,1,n-1)
    {
        cin >> u >> v >> c;
        ke[u].push_back(iii(ii(v,c),i));
        ke[v].push_back(iii(ii(u,c),i));
        kq=max(kq,c);
    }
    if (k==n)
    {
        cout << kq;
        return 0;
    }
    if (k<=10)
    {
        for (int i=1; i<=k; i+=2)
            s=max(s,bfs(x[i],x[i+1]));
        kq=s;
        while(next_permutation(x+1,x+k+1))
        {
            FOR(i,1,n-1) dx[i]=0;
            s=0;
            for (int i=1; i<=k; i+=2)
                s=max(s,bfs(x[i],x[i+1]));
            kq=min(kq,s);
        }
        if (kq==base) cout << -1;
        else cout << kq;
        return 0;
    }
    cout << -1;
}
