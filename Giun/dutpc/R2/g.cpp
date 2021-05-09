#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e5 + 7;
ll n, x, y, a[mxn];
unordered_map<ll, ll> mp;
pp(bool, bool) f[mxn];
ll res[mxn] = {0};
bool ok  = 1;

void gan(ll i){
    if(!(f[i].first | f[i].second)){
        ok = 0;
        return;
    }
    if(f[i].first == 1 && f[i].second == 0){
        if(res[mp[x - a[i]]] == -1){
            res[i] = res[mp[x - a[i]]] = 0;
            if(mp[y - (x - a[i])]){
                f[mp[y - (x - a[i])]].second = 0;
                gan(mp[y - (x - a[i])]);
            }
        }
        else {
            ok = 0;
        }
    }
    if(f[i].first == 0 && f[i].second == 1){ 
        if(res[mp[y - a[i]]] == -1){
            res[i] = res[mp[y - a[i]]] = 1;
            if(mp[x - (y - a[i])]){
                f[mp[x - (y - a[i])]].first = 0;
                gan(mp[x - (y - a[i])]);
            }
        }
        else{
            ok  = 0;
        }
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> x >> y;
    lp(i, 1, n){
        cin >> a[i];
        mp[a[i]] = i;
        res[i] = -1;
        f[i] = {0, 0};
    }
    lp(i, 1, n){
        if(mp[x - a[i]]){
            f[i].first = 1;
        }
        if(mp[y - a[i]]){
            f[i].second = 1;
        }
        if(!(f[i].first | f[i].second)){
            ok = 0;
        }
    }
    lp(i, 1, n){
        if(res[i] != -1) continue;
        gan(i);
    }
    lp(i, 1, n){
        if((f[i].first & f[i].second) && res[i] == -1) res[i] = 0;
        if(res[i] == -1){
            ok = 0;
        }
    }
    if(!ok){
        cout << "-1";
        return 0;
    }
    cout << "YES\n";
    lp(i, 1, n) cout << res[i] << ' ';
}