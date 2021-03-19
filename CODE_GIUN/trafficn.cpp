#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pl pair<ll,ll>
const int MAXN = 1e4+7;
const ll oo = 2e9 + 7;
ll N,M,u,v,w ,S, T , K , l;
ll Fsu [MAXN],  Ftu[MAXN] ;
vector<pl>G[MAXN] , G1[MAXN];

void sol(vector<pl> *g , ll startnode , ll *f )
{
    for (int i = 1 ; i <= N ; i++) f[i] = oo;
    priority_queue< pl , vector<pl> , greater<pl> > p;
    f[startnode] = 0 ;
    p.push(pl(0, startnode));
    while (!p.empty())
    {
        u = p.top().second;
        int dis_u = p.top().first;
        p.pop();
        if (f[u] != dis_u ) continue;
        for (pl v : g[u])
        {
            if (f[v.second] > dis_u + v.first)
            {
                f[v.second] = dis_u+v.first;
                p.push({f[v.second], v.second});
            }
        }
    }
}   

int main()
{
    giuncute;
   // freopen("giun.inp","r",stdin);
   // freopen("giun.out","w",stdout);
    cin >> l;
    while (l--)
    {
        cin >> N >> M >> K >> S >> T;
        for (int i = 1 ; i <= N ; i++ )
        {
            G[i].clear();
            G1[i].clear();
        }
        for (int i = 1 ; i <= M ; i++)
        {
            cin >> u >> v >> w;
            G[u].push_back({w,v});
            G1[v].push_back({w,u});
        }
        sol(G,S,Fsu);
        sol(G1,T,Ftu);
        ll ans = oo;
        for (int i = 1 ; i <= K ; i++)
        {
            cin >> u >> v >> w;
            ans = min({ans,Fsu[u] + w + Ftu[v] , Fsu[v] + w + Ftu[u]  });
        }
        if (ans == oo ) cout<< -1 << endl;
        else cout << min(ans, Fsu[T]) << endl;
    }
}
// dpt ((n * logm * 2 +k ) *20 )