#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
const ll maxn = 1e4+7 ;
ll n , m , s , u , v , cnt[maxn] = {0} , len[maxn] ={0} , ans = 0;
vector <ll> G[maxn];
map <pl , bool > dd;
void sol_bfs ()
{
    queue<ll> q;
    q.push(s);
    cnt[s] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        //cerr << u << " ";
        for (int v : G[u])
        {
            if (cnt[v] == 0) len[v] = len[u] + 1 , cnt[v] = cnt[u] , q.push(v);
            else 
                if (len[v] == len[u] + 1 )
                {
                    if (cnt[v] == 1) cnt[v] = 2;
         //           cerr << v << " ";
                }
        }
    }
    for (int i = 1 ; i <= n ;i++)
        if (cnt[i] == 2) ans++;
    cout << ans;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m >> s ;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v;
        if (dd[{u,v}] ) continue;
        dd[{u,v}] = true;
        G[u].push_back(v);
    }
    sol_bfs();
}
