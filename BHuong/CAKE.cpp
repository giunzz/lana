#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;
ll n , x, y;
vector<pair<ll,ll>> a;
inline ll dientich(ll xa , ll ya , ll xb , ll yb , ll xc , ll yc)
{
    ll s = abs ( ((yc+ya)*(xc-xa)+(ya+yb)*(xa-xb)+(yb+yc)*(xb-xc))  );
    return s ;
}
// b = (a / 2) * 10 = a * 5 => b/10 + '.' + b%10
/// cout << (a>>1) << '.' + (a&1)
int main()
{
    giuncute;
    freopen("cake.inp","r",stdin);
    freopen("cake.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> x >> y ;
        a.push_back( make_pair(x,y) );
    }
    while ((int)a.size() != 4)
    {
        ll ma = INT64_MAX , vt = 0;
        for (int i = 0 ; i < (int) a.size() ; i++)
        {
            ll k = dientich(
                a[(i-1+a.size()) % a.size()].first,
                a[(i-1+a.size()) % a.size()].second,
                a[i].first,
                a[i].second,
                a[(i+1) % a.size()].first,
                a[(i+1) % a.size()].second
            );
            if (ma > k) ma = k , vt = i;   
        }
        a.erase(a.begin()+vt);
      //  cerr << a.size() << " ";
    }
    ll ans = 0;
    for (int i = 1 ; i < (int) a.size() ; i++)  ans += dientich(
        a[0].first,
        a[0].second,
        a[i].first,
        a[i].second,
        a[i+1].first,
        a[i+1].second
    );     
    cout << (ans >> 1) << '.' << (ans & 1) * 5;
}
