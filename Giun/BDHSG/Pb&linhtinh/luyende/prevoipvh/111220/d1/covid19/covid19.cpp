#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

cll MOD = 998244353, maxn = 5e5 + 7;
ll n, k, q, a[maxn], d[maxn];

ll poww(ll u, ll v){
    if(v == 0) return 1;
    ll tmp = poww(u, v >> 1);
    if(v & 1) return ((tmp * tmp) % MOD * u) % MOD;
    else return (tmp * tmp) % MOD;
}

void sub0(){
    ll ans = 0;
    lp(i, 1, n) (ans += -1 * poww((n + 1), i) + MOD) %= MOD;
    cout << ans << '\n';
    lp(i, 1, q) cout << ans << '\n';
}

void sub1(){
    ll ans = 0;
    lp(i, 1, n) (ans += d[i] * poww((n + 1), i) + MOD) %= MOD;
    cout << ans << '\n';
    // cerr << ans;
    lp(i, 1, q){
        char c;
        ll u, v;
        cin >> c >> u >> v;
        // cerr << c << ' ' << u << ' ' << v << '\n';
        // ll tmp = u;
        if(d[u] == d[v]) cout << ans << '\n';
        else{
            if(d[u] == -1 || (d[u] > d[v] && d[v] != -1)) swap(u, v);
            // cerr << u << ' ' << v << ' ' << d[u] << ' ' << d[v] << '\n'; 
            ((ans -= d[v] * poww(n + 1, v)) += MOD) %= MOD;
            d[v] = d[u] + 1;
            ((ans += d[v] * poww(n + 1, v)) += MOD) %= MOD;
            cout << ans << '\n';
        }
    }
}

void sub(){
    ll ans = 0;
    lp(i, 1, n) (ans += d[i] * poww((n + 1), i) + MOD) %= MOD;
    cout << ans << '\n';
    // cerr << ans;
    lp(i, 1, q){
        char c;
        ll u, v;
        cin >> c >> u >> v;
        // cerr << c << ' ' << u << ' ' << v << '\n';
        // ll tmp = u;
        if(c == 'D'){
            if(d[u] == d[v]) cout << ans << '\n';
            else{
                if(d[u] == -1 || (d[u] > d[v] && d[v] != -1)) swap(u, v);
                // cerr << u << ' ' << v << ' ' << d[u] << ' ' << d[v] << '\n'; 
                ((ans -= d[v] * poww(n + 1, v)) += MOD) %= MOD;
                d[v] = d[u] + 1;
                ((ans += d[v] * poww(n + 1, v)) += MOD) %= MOD;
                cout << ans << '\n';
            }
        }
        else{
            ll t = LLONG_MAX;
            lp(i, u, v){
                if(d[i] != -1) t = min(d[i], t);
            }
            if(t == LLONG_MAX){
                cout << ans << '\n';
            }
            else{
                lp(i, u, v) if(d[i] != t){
                    // cerr << u << ' ' << v << ' ' << d[u] << ' ' << d[v] << '\n'; 
                    ((ans -= d[i] * poww(n + 1, i)) += MOD) %= MOD;
                    d[i] = t + 1;
                    ((ans += d[i] * poww(n + 1, i)) += MOD) %= MOD;
                }
                cout << ans << '\n';
            }
        }
    }
}

int main(){
    file("covid19");
    ll cs;
    memset(d, -1, sizeof(d));
    cin >> cs >> n >> k >> q;
    lp(i, 1, k){
        cin >> a[i];
        d[a[i]] = 0;
    }
    // lp(i, 1, n) cerr << d[i] <<  ' ';
    if(cs == 0) sub0();
    else if(cs == 1) sub1();
    else sub();
}