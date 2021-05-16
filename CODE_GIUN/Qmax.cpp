#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 5e4+7;
ll n , m , q , u , v , k , a[maxn] = {0} , tr[4*maxn];

void build (ll id , ll l , ll r)
{
    if (l == r) 
    {
        tr[id] = a[l];
        return ;
    }
    ll mid = (l+r) >> 1 ;
    build(id * 2 , l , mid);
    build(id * 2 + 1 , mid+1 , r);
    tr[id] = max(tr[id*2] , tr[id*2+1]);
}
ll  Get (ll id , ll l , ll r , ll u , ll v)
{
    if (u > r || v < l) return 0 ;
    if ( u <= l && v >= r ) return tr[id];
    ll mid = (l+r) >> 1;
    return max (Get(id*2,l,mid,u,v) , Get(id*2+1,mid+1,r,u,v));

}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ; 
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> k;
        a[u] += k , a[v+1] -= k;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        a[i] += a[i-1];
       // cerr << a[i] << " ";
    }
    build(1,1,n);
    cin >> q;
    for (int i = 1 ; i <= q ; i++)
    {
        cin >> u >> v ;
        ll ans = Get (1 , 1 , n , u , v);
        cout << ans << endl;
    }
}