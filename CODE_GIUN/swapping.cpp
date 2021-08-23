#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll k , m , n , x;
multiset <ll> a ;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> k >> m >> n;
    ll x ;
    for (int i = 1 ; i <= n ; i++) cin >> x , a.insert(x);
    //multiset <ll> :: iterator itr;
    // for (itr = a.begin(); itr!= a.end(); ++itr) //cerr << *itr << " ";
    // //cerr << endl;
    multiset<ll>::iterator l = a.begin(), r = a.end();
    r--;
    //cerr << *l << " " << *r << endl;
    ll ans = *r - *l;
    for (int i = 1 ; i <= m ; i++)
    {
        l = a.begin(), r = a.end() , r--;
        //cerr << *l << " " << *r << endl;
        ll al = *l , ar = *r;
        if (ar < k ) break;
        a.erase(l) , a.erase(r);
        al += k , ar -= k;
        a.insert(al) , a.insert(ar);
        r = a.end() , l = a.begin();
        //cerr << *l << " " << *r << endl;
        r--;
        ans = min (ans , *r - *l);
    }
    cout << ans;
}