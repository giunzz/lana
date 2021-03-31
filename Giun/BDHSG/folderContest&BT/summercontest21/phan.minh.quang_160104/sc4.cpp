#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "sc4"
using namespace std;

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
ll n, k, c, cost[mxn], type[mxn];
pp(ll, ll) mitype[57], cs[mxn];
bool d[mxn];

void sol(){
    cin >> n >> k >> c;
    lp(i, 1, n) d[i] = 0;
    lp(i, 1, n) cin >> type[i];
    lp(i, 1, n){cin >> cost[i]; cs[i] = {cost[i], i};}
    lp(i, 1, 50) mitype[i] = {INT_MAX, INT_MAX};
    lp(i, 1, n) if(mitype[type[i]].first > cost[i]) mitype[type[i]] = {cost[i], i};
    sort(mitype + 1, mitype + 51);
    lp(i, 1, k){
        c -= mitype[i].first;
        if(c < 0){
            cout << "FRIENDSHIP\n";
            return;
        }
        d[mitype[i].second] = 1;
    }
    bool res = 0;
    lp(i, 1, n) if(!d[cs[i].second]) if(c - cs[i].first >= 0) res = 1;
    if(res) cout << "LOVE\n";
    else cout << "NOT FRIENDSHIP BUT NOT LOVE\n";
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}