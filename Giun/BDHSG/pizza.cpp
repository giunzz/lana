#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "pizza"
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

cll mxm = 22, mxn = 102, mxtot = 12;
ll tot, r, m, n, ans = 0, trace[mxtot] = {0}, check_house[mxn] = {0}, res = 0;
pp(ll, ll) food[mxm];
pp(pp(ll, ll), ll) house[mxn];

ll dis(pp(ll, ll) &a, pp(ll, ll) &b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void ql(ll pos){
    ll cnt;
    if(pos > tot){
        ans = max(ans, res);
    } else{
        lp(i, trace[pos - 1] + 1, m - (tot - pos)){
            cnt = 0, trace[pos] = i;
            lp(j, 1, n) if(!check_house[j] && dis(food[i], house[j].first) <= r) 
                cnt += house[j].second, check_house[j] = pos;
            res += cnt;
            ql(pos + 1);
            lp(j, 1, n) if(check_house[j] == pos) check_house[j] = 0;
            res -= cnt;
        }
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> tot >> r >> m;
    r *= r;
    lp(i, 1, m) cin >> food[i].first >> food[i].second;
    cin >> n;
    lp(i, 1, n) cin >> house[i].first.first >> house[i].first.second >> house[i].second;
    ql(1);
    cout << ans;
}