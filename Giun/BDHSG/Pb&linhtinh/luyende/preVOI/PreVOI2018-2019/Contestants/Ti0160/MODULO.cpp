#include<bits/stdc++.h>

using namespace std;
#define brokenheart "MODULO"
#define pb	push_back
typedef long double ld;
typedef long long ll;
const int maxn = 1e6;

int a , b , n;
ll k;

ll Mod(ll x)
{
    return x & ((1ll << n) - 1);
}

vector<pair<ll,ll>> v , v1;

void P(int i , ll mod , ll bit)
{
    if(i == n / 2){
        v.pb({mod,bit});
        return;
    }
    P(i + 1 , Mod(mod * 10 +a),bit);
    P(i + 1 , Mod(mod * 10 +b),bit | (1ll << i));
}

void P1(int i , ll mod , ll bit)
{
    if(i == n){
        v1.pb({mod,bit});
        return;
    }
    P1(i + 1 , Mod(Mod(Mod(mod * 5) * 2)+a),bit);
    P1(i + 1 , Mod(Mod(Mod(mod * 5) * 2)+b),bit | (1ll << i));
}

ll Mul(ll x,ll y , ll m)
{
    x %= m; y %= m;
    ll q = (long double) x * y / m;
    ll r = ll(x * y - q * m) % (ll)m;
    if (r < 0) r += m;
    return r;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if(fopen(brokenheart".INP","r"))
        freopen(brokenheart".INP", "r",stdin) ,
        freopen(brokenheart".OUT", "w",stdout);
//    cerr << 777 % 8;
    cin >> a >> b >> n >> k;
    if(n == 1)
    {
        if(a % 2 == k)return cout << a , 0;
        if(b % 2 == k)return cout << b , 0;
        return cout << -1 , 0;
    }
    P(0,0,0);
    P1(n / 2 , 0 , 0);
    ll P = 1;
    for(int i = n / 2 ; i < n ; ++i)P = Mul(P,10,(1ll<<n));
//    cout << mmap[n / 2].size() << endl;
    sort(v1.begin(),v1.end());
    for(auto & c : v)
    {
        ll need = k - Mul(c.first,P,(1ll << n));
        if(need < 0)need += (1ll << n);
//        cout << c.first << " ";
//        cout << need << endl;
        auto it = lower_bound(v1.begin(),v1.end(),make_pair(need,0ll));
        if(it != v1.end() && (*it).first == need)
        {
            ll res = c.second | (*it).second;
            for(int i = 0 ; i < n ; ++i)
                if((res >> i) & 1)cout << b;
                else cout << a;
                return 0;
        }
    }
    cout << -1;
}
