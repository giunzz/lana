#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("f.inp", "r", stdin);
    freopen("f.out", "w", stdout);
}

struct ps{
    ll tu, mau;
};

ps dao(ps &a){
    ps tmp = {a.mau, a.tu};
    return tmp;
}

bool operator<(const ps &a, const ps &b){
    return a.tu*b.mau < b.tu*a.mau;
}

cll maxn = 1e5 + 7;
bool w;
ps a[maxn];
vector<ps> b;
pp(ll, ll) f[maxn*2][2] = {{{0, 0}}};

struct fenwick{
    ll n;
    fenwick(ll n) : n(n) {}
    void set(ll x, ll i, ll tt){
        for(; i <= 2 * n; i += (i & -i)) f[i][tt].first = max(f[i][tt].first, x), f[i][tt].second = i; 
    }
    pp(ll, ll) get(ll i, ll tt) const{
        pp(ll, ll) r = {0, 0};
        for(; i >= 1; i -= (i & -i)) r = max(r, f[i][tt]); 
        return r;
    }
};

ll n;

vector<ps> nen(vec(ps) x){
    set<ps> y(x.begin(), x.end());
    vec(ps) tmp(y.begin(), y.end());
    return tmp;
}

int main(){
    File();
    cin >> n >> w;
    lp(i, 1, n) {cin >> a[i].tu >> a[i].mau; b.push_back(a[i]); b.push_back(dao(a[i]));}
    b = nen(b);
    reverse(b.begin(), b.end());
    b.push_back({0, 1});
    reverse(b.begin(), b.end());
    // for(ps v : b){
    //     cerr << v.tu << ' ' << v.mau << endl;
    // }
    // cerr << endl;
    fenwick bit(n);
    lp(i, 1, n){
        // cerr << 1;
        ll tmp = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ll tmp1 = lower_bound(b.begin(), b.end(), dao(a[i])) - b.begin();
        // bit.set(bit.get(tmp - 1, 0) + 1, tmp, 0);
        cerr << tmp << ' ' << tmp1 << endl; 
        pp(ll, ll) get = bit.get(tmp - 1, 0), get1 = bit.get(tmp1 - 1, 1);
        cerr << get.first << ' ' << get.second << endl;
        cerr << get1.first << ' ' << get1.second << endl;
        cerr << endl;
        if(get.second <= tmp && get1.second <= tmp) bit.set(max(get.first, get1.first) + 1, tmp, 0);
        else bit.set(get.first + 1, tmp, 0);
        if(get.second <= tmp1 && get1.second <= tmp1) bit.set(max(get.first, get1.first) + 1, tmp1, 1);
        else bit.set(get1.first + 1, tmp1, 1);
    }
    cout << max(bit.get(lower_bound(b.begin(), b.end(), a[n]) - b.begin(), 0).first, bit.get(lower_bound(b.begin(), b.end(), dao(a[n])) - b.begin(), 1).first);
}