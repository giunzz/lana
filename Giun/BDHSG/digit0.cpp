#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "digit0"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

string s;
vec(ll) cnt(300, 0);

void cntU(ll u, ll cs, ll &c){
    ll tmp = cs;
    while(u / tmp){
        c += u / tmp;
        tmp *= cs;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    //test
    cin >> s;
    for(char c : s){
        ++cnt[c];
    }
    ll tot = 0;
    vec(ll) a;
    lp(i, 0, 299) if(cnt[i]) tot += cnt[i], a.push_back(cnt[i]);
    ll cnt5top = 0, cnt2top = 0;
    cntU(tot, 2, cnt2top);
    cntU(tot, 5, cnt5top);
    ll cnt5down = 0, cnt2down = 0;
    for(ll i : a) cntU(i, 2, cnt2down), cntU(i, 5, cnt5down);
    ll cnt2 = cnt2top - cnt2down, cnt5 = cnt5top - cnt5down;
    cout << min(cnt2, cnt5);
}