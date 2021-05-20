#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 1e5+7;
ll n , q , x , y , a[maxn];
char c ;
struct segment1{
    ll st[4*maxn] = {0};
    void update (ll id , ll l , ll r , ll u )
    {
        if (l > u || r < u) return ;
        if (l == r)
        {
            st[id] = 1;
            return ;
        }
        ll mid = (l+r) >> 1;
        update(id*2 , l , mid , u);
        update(id*2+1 , mid+1, r , u);
        st[id] = st[id*2] + st[id*2+1];
    }
    ll get (ll id , ll l , ll r , ll u , ll v)
    {
        if ( u > r || v < l) return 0 ;
        if (l <= u && r <= v) return st[id];
        ll mid = (l+r) >> 1 ;
        return get(id*2 , l , mid , u , v) + get (id*2+1 , mid+1, r , u , v);
    }
    void update (ll u)
    {
        update(1,1,n,u);
    }
    ll get (ll v)
    {
        return get(1,1,n,1,v);
    }
    ll get_left( ll group)
    {
        ll l = 1 , r = n ,  ans;
        while ( l <= r)
        {
            ll mid = (l+r) >> 1;
            if (get(mid) >= group) ans = mid , r = mid - 1 ;
            else l = mid + 1;
        }
        return ans;
    }
    ll get_right(ll group)
    {
        ll l = 1 , r = n ,  ans ;
        while (l <= r)
        {
            ll mid = (l+r) >> 1;
            if (get(mid) <= group) ans = mid , l = mid+1;
            else r = mid-1;
        }
        return ans;
    }
};

struct node 
{
    ll size , max ;
};
struct segment2
{
    node st[maxn*4];
    void build (ll id , ll l , ll r )
    {
        if (l == r)
        {
            st[id].size = 1 ; 
            st[id].max = a[l];
            return;
        }
        ll mid = (l+r) >> 1;
        build(id *2 , l , mid );
        build(id *2 + 1 , mid+1 , r);
        st[id].max = max (st[id*2].max , st[id*2+1].max);
        st[id].size = st[id*2].size + st[id*2+1].size;
    }
    ll erase ( ll id , ll l , ll r , ll h)
    {
        if (l == r)
        {
            st[id].size = 0 ;
            st[id].max = -1;
            return l ;
        }
        ll mid = (l+r) >> 1 , pos;
        if ( st[id * 2].size < h) pos = erase(id*2+1 , mid+1 , r , h - st[id*2].size);
        else pos = erase(id*2 , l , mid , h);
        st[id].size = st[id*2].size + st[id*2+1].size;
        st[id].max = max (st[id*2].max, st[id*2+1].max);
        return pos;
    }
    ll get_max(ll id , ll l , ll r , ll u , ll v)
    {
        if (v < l || r < u) return -1;
        if (u <= l &&  v >= r) return st[id].max;
        ll mid = (l+r) >> 1 ;
        return st[id].max = max (get_max(id * 2 , l , mid , u , v) , get_max(id*2 , mid+1, r , u , v));
    }
    void build ()
    { 
        build(1 , 1 , n);
    }
    ll get_max(ll u , ll v)
    {
        return get_max(1,1,n,u,v);
    }
    ll erase(ll h)
    {
        return erase(1, 1, n , h);
    }
};
int main()
{
    // giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cerr << "ok";
    segment1 tr1;
    // segment2 tr2;
    //tr2.build();
    // cerr << 1;
    // cin >> n ;
    // for (int i = 1  ; i <= n ; i++) cin >> a[i];
    // cin >> q;
    // ll tmp = 0 ;
    // while (q--)
    // {
    //     cin >> c;
    //     cerr << 1;
    //     if (c == 'S')
    //     {
    //         cerr << 1;
    //         cin >> x ;
    //         tr1.update(tr2.erase(x));
    //         tmp++;
    //     }
    //     else 
    //     {
    //         cin >> x >> y ;
    //         if (x > tmp || y < 0) cout << "NONE" << endl;
    //         else 
    //         {
    //             if (x < 0) x = 0 ;
    //             if ( y > tmp) y = tmp ;
    //             ll ans = tr2.get_max(tr1.get_left(x) , tr1.get_right(y));
    //             if (ans == -1) cout << "NONE" << endl;
    //             else cout << ans << endl;
    //         }
    //     }
    // }
}
