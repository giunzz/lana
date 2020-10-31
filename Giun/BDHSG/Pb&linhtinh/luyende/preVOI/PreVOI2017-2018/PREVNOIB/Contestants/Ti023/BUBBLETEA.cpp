#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
const int nmax = 50000 + 10;
ll n,k,dd[nmax],a[nmax],x[nmax],minn = 1e15 + 50,kq = 1e15 - 50;
pii vet[nmax];
vector <pii> adj[nmax];
vector <ll> dg;
map <pii,ll> ma;

ll truyvet(int xp,int kt,int id)
{
    ll s = 0;
    int ok = 1;
    for(int i=kt; i!=xp; i = vet[i].fi)
    {
        if(id == 1)
        {
            if(ma[mp(i,vet[i].fi)] == 1)ok = 0;
            ma[mp(i,vet[i].fi)]++;
            ma[mp(vet[i].fi,i)]++;
            s += vet[i].se;
        }
        else
        {
            ma[mp(i,vet[i].fi)]--;
            ma[mp(vet[i].fi,i)]--;
            s -= vet[i].se;
        }
    }
    if(id == 1)dg.push_back(s);
    else dg.pop_back();
    return ok;
}

ll tinh(int xp,int kt,int id)
{
    memset(vet,0,sizeof(vet));
    queue <int> Q;
    Q.push(xp);
    vet[xp].fi = xp;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if(u == kt)
        {
            return truyvet(xp,kt,id);
        }
        for(int i=0; i<adj[u].size(); i++)
        {
            int v  = adj[u][i].fi;
            if(vet[v].fi == 0)
            {
                vet[v].fi = u;
                vet[v].se = adj[u][i].se;
                Q.push(v);
            }
        }
    }
}

void BT(int u)
{
    if(u == k+1)
    {
        ll maxx = -1e15 - 50;
        for(int i=0; i<dg.size(); i++)
            maxx = max(maxx,dg[i]);
        minn = min(minn,maxx);
    }
    for(int i=1; i<=k; i++)
    {
        if(dd[a[i]] == 0)
        {
            x[u] = a[i];
            dd[a[i]] = 1;
            if(u % 2 == 0)
            {
                int k1 = tinh(a[i],x[u-1],1);
                if(k1 == 0)
                {
                    tinh(a[i],x[u-1],0);
                    x[u] = 0;
                    dd[a[i]] = 0;
                    return;
                }
            }
            BT(u+1);
            if(u % 2 == 0)tinh(a[i],x[u-1],0);
            x[u] = 0;
            dd[a[i]]  = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BUBBLETEA.inp","r",stdin);
    freopen("BUBBLETEA.out","w",stdout);
    cin >> n >> k;
    for(int i=1; i<=k; i++)
        cin >> a[i];
    for(int i=1; i<n; i++)
    {
        ll u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back(mp(v,c));
        adj[v].push_back(mp(u,c));
    }
    if(k <= 20)
    {
        BT(1);
        if(minn >= 1e15)cout << -1;
        else cout << minn;
    }
    else cout << -1;

    return 0;
}
