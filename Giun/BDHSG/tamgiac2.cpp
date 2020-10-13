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
    ll a, b, c;
    void dau(){
        a *= -1, b *= -1, c *= -1;
    }
    void rg(){
        ll tmp = __gcd(__gcd(abs(a), abs(b)), abs(c));
        if(!tmp) tmp = 1;
        a /= tmp, b /= tmp, c /= tmp;
    }
};

bool operator<(quang const &x, quang const &y){
    if(x.a < y.a) return 1;
    if(x.a == y.a && x.b < y.b) return 1;
    if(x.a == y.a && x.b == y.b && x.c < y.c) return 1;
    return 0;
}

bool operator==(quang const &x, quang const &y){
    if(x.a == y.a && x.b == y.b && x.c == y.c) return 1;
    return 0;
}

ll n;
vec(quang) l, o;
map<quang, ll> cnt;
map<quang, bool> d;

void init(){
    lp(i, 1, n){
        cin >> l[i].a >> l[i].b >> l[i].c;
        if(l[i].b < 0) l[i].dau(); 
        l[i].rg();
        if(!d[l[i]]){
            d[l[i]] = 1;
            quang tmp = {l[i].a, l[i].b, 0};
            if(!cnt[tmp]++) o.push_back(tmp);
            // cerr << tmp.a << ' ' << tmp.b << ' ' << tmp.c << ' ' << cnt[tmp] << '\n';
        }
    }
    // cerr <<'\n';
}

// bool cpr(quang &x, quang &y){
//     return -x.a * y.b > -y.a * x.b;
// }

// ll solve(){
    
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    l.resize(n + 1);
    init();
    lp(i, 0, o.size() - 1){
        
    }
}