#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 1e5+7;
string s ;

struct Zun
{
    ll pair , open , close;
} st[4*maxn];

ll n , m , x , y ;

void build (ll id , ll l , ll r)
{
    if (l == r) 
    {
        if (s[id] == '(') st[id].pair = 0 , st[id].open = 1 , st[id].close = 0;
        else  st[id].pair = 0 , st[id].open = 0 , st[id].close = 1;
        return ;
    }
    ll mid = (l+r) >> 1;
    build(id*2 , l ,mid);
    build(id*2 + 1 , mid+1 , r);
    ll tmp = min(st[id*2].open , st[id*2+1].close);
    st[id].pair = st[id*2].pair + st[id*2+1].pair + tmp ;
    st[id].open = st[id*2].open + st[id*2+1].open - tmp ;
    st[id].close = st[id*2].close + st[id*2+1].close - tmp ;
}
Zun Get (ll id , ll l , ll r , ll u , ll v)
{
    if (u > r || v < l ) return {0,0,0};
    if (u <= l && r <= v) return st[id];
    ll mid = (l+r) >> 1;
    Zun left = Get(id*2 , l , mid , u , v) , right = Get(id*2+1 , mid+1 , r , u , v);
    ll tmp = left.open+right.close;
    return {left.pair+right.pair+tmp , left.open+right.open-tmp , left.close+right.close-tmp };
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> s ;
    n = s.length();
    build(1,0,n-1);
    cin >> m ;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> x >> y ;
        Zun ans = Get (1 , 0 , n-1 , x , y);
        cout << ans.pair * 2 << endl;
    }
}