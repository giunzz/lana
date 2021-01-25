#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

struct quang{
    ll a, b;
    void dau(){
        a *= -1, b *= -1;
    }
    void rg(){
        ll tmp = __gcd(abs(a), abs(b));
        if(!tmp) tmp = 1;
        if(!a || !b) tmp = max(abs(a), abs(b));
        a /= tmp, b /= tmp;
    }
};

bool operator<(quang const &x, quang const &y){
    if(x.a < y.a) return 1;
    if(x.a == y.a && x.b < y.b) return 1;
    return 0;
}

bool operator==(quang const &x, quang const &y){
    if(x.a == y.a && x.b == y.b) return 1;
    return 0;
}

ll n;
vec(ll) r, sum[3];
vec(quang) l, o;
map<quang, ll> cnt;

void init(){
    ll c;
    lp(i, 1, n){
        cin >> l[i].a >> l[i].b >> c;
        if(l[i].b < 0) l[i].dau(); 
        l[i].rg();
        quang tmp = {l[i].a, l[i].b};
        if(!cnt[tmp]++) o.push_back(tmp);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    l.resize(n + 1);
    init();
    ll res = 0, s = 0;
    lp(i, 0, o.size() - 1){
        res = cnt[o[i]];
        r.push_back(res);
        sum[0].push_back(s += res);
    }
    res = 0;
    lp(i, 0, r.size() - 1){
        lp(j, i + 1, r.size() - 2){
            res += r[i] * r[j] * (sum[0].back() - sum[0][j]);
        } 
    }
    cout << res;
}