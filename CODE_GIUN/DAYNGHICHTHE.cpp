#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 6e4 + 7;
ll n , a[maxn] , st[4 * maxn] = {0} ,  ans = 0 ;

void update(ll id , ll l , ll r , ll u)
{
    if (u < l || u > r) return ;
    if ( l == r)
    {
        st[id]++;
        return ;
    }
    ll mid = (l+r) / 2;
    update(id*2, l , mid , u);
    update(id*2 + 1, mid+1 , r , u);
    st[id] = st[id*2] + st[id*2+1];
}
ll get ( ll id , ll l , ll r , ll u , ll v)
{
    if (l > v || r < u ) return 0 ;
    if(u <= l && r <= v) return st[id];
    ll mid = (l+r) / 2;
    return get(id*2, l , mid ,u,v) + get(id*2 + 1, mid+1 , r , u , v);
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ; 
    ll ma = 0 ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        
        if (ma > a[i] ) ans += get(1, 1, (int) 6e4 , a[i] + 1, ma);
        update(1,1,(int)6e4,a[i]);
        ma = max(ma,a[i] );
    }
    cout << ans;
}
