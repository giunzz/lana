#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "telephone"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    ll n, m;
    string name, s;
    cin >> n;
    auto process = [&](){
        cin >> m >> name;
        vec(string) a(m);
        for(auto &s : a) cin >> s;
        sort(s.begin(), s.end());
        ll it = unique(s.begin(), s.end()) - s.begin();
        a.resize(it);
        for(auto s : a) cerr << s << '\n';
    };
    while(n--){
        process();
    }
}