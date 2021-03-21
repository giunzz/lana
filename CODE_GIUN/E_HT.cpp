#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pl pair<ll,ll>
const int MAXN = 2e4+7;
const ll oo = 2e9 + 7;
ll N,M,u1[MAXN],v[MAXN],w[MAXN] ,S, T , K , L;
ll FST [MAXN],  FLK[MAXN] ;
vector<pl>G[MAXN] , G1[MAXN];
void sol(vector<pl> *g , ll startnode , ll *f )
{
    for (int i = 1 ; i <= N ; i++) f[i] = oo;
    priority_queue< pl , vector<pl> , greater<pl> > p;
    f[startnode] = 0 ;
    p.push(pl(0, startnode));
    while (!p.empty())
    {
        int u = p.top().second;
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
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> N >> M >> S >> T >> L >> K;
            for (int i = 1 ; i <= M ; i++)
            {
                cin >> u1[i] >> v[i] >> w[i];
                G[u1[i]].push_back({w[i],v[i]});
            }
            for (int i = S ; i <= T ; i++)
            {
                G1[u1[i]].push_back({w[i],v[i]});
            }
    sol (G,S , FST);
    sol (G1,L , FLK);
    cerr << FST[T] << " ";
}