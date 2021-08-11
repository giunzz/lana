#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define ppl pair<pl,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e6 + 7;
using namespace std;
ll n , m,  u , v , w ;
vector<pl> g[maxn] , a , b ;

void DIJKSTRA (ll startnode , vector<pl> &c)
{
    priority_queue<ppl, vector<ppl> , greater<ppl>> pq;
    for (int i = 1 ; i <= n ; i++) c[i] = {MOD , MOD} ;
    c[startnode] = {0 , 1};
    pq.push({c[startnode],startnode});
    while (!pq.empty())
    {
        u = pq.top().second ; 
        pl su = pq.top().first; 
        pq.pop();
        if(c[u] != su) continue;
        for (pl v : g[u])
        {
            ll uv = v.second , suv = su.first  + uv , i = v.first;
            if (suv < c[i].first)  c[i] = {suv , su.second} , pq.push({c[i] , i});
            else if (suv == c[i].first)
            {
                c[i] = {suv , c[i].second + su.second};
                pq.push({c[i] , i});
            }
        }
    }
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    for (int i = 1; i <= m ;  i++)
    {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    a.resize(n + 3);
    b.resize(n + 3);
    DIJKSTRA(1 , a);
    DIJKSTRA(n , b);

    vector<ll> res;
    for (int i = 1 ; i <= n ; i++) 
    {
        //cerr << a[i].fi << " " << a[i].se << endl;
        if(a[i].first + b[i].first != a[n].first || a[i].second * b[i].second < a[n].second) 
            res.push_back(i);
    }
    cout << res.size() << endl;
    for (int i = 0 ; i < (int) res.size() ; i++) cout << res[i] << endl;
}
