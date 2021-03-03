#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
const ll maxn = 1e6+7;
ll dsu[maxn]  , m ,n , size[maxn] ;
struct giun
{
    int u , v , w , vt;
} a[maxn];

bool cmp (giun &x , giun &y)
{
    return (x.w > y.w);
}
ll get(int u)
{
    if (dsu[u] == u) return u;
    return dsu[u] = get(dsu[u]);
}
bool ghep(giun& a)
{
    ll x = get(a.u), y = get(a.v);
    if(x == y) return 0;
    if( size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    dsu[y] = x;
    return 1;
}
int main()
{
    giuncute;
    freopen("ELECTRIC.INP","r",stdin);
    freopen("ELECTRIC.OUT","w",stdout);
    cin >> n >> m ;
    for (int i = 1 ; i <= m ; i++) cin >> a[i].u >> a[i].v >> a[i].w , a[i].vt = i;
    for (int i = 1 ; i <= m ; i++) dsu[i] = i , size[i] = 1;
    sort (a+1 , a+1+m , cmp);
    ll ans = 0  , cnt = 0 ;
    vector<ll> mini;
    for (int i = 1 ; i <= m ; i++ )
    {
        if(ghep(a[i]) && cnt != n - 1)
        {
            ++cnt;
            ans += a[i].w;
            mini.push_back(a[i].vt);
        }
    }
    cout << ans << endl;
    sort (mini.begin(),mini.end());
    for (int i = 0 ; i < (int) mini.size() ; i++) cout << mini[i] << endl;
}
