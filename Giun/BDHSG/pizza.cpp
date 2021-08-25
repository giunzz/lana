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
ll tot, r, m, n, ans = 0, trace[mxtot] = {0};
pp(ll, ll) food[mxm];
pp(pp(ll, ll), ll) house[mxn];
bitset<mxn> status[mxm];

ll dis(pp(ll, ll) &a, pp(ll, ll) &b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void ql(ll pos){
    if(pos > tot){
        ll cnt = 0;
        bitset<mxn> total;
        lp(i, 1, tot) total |= status[trace[i]];
        lp(i, 1, n) if(total[i]) cnt += house[i].second;
        ans = max(cnt, ans); 
    } else{
        lp(i, trace[pos - 1] + 1, m - (tot - pos)){
            trace[pos] = i;
            ql(pos + 1);
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
    lp(i, 1, m) lp(j, 1, n) if(dis(food[i], house[j].first) <= r) status[i][j] = 1;
    lp(i, 1, m) cerr << status[i] << '\n';
    ql(1);
    cout << ans;
}