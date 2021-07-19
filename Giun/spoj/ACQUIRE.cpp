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

cll mxn = 5e4 + 7;
ll n, dp[mxn];
pp(ll, ll) recr[mxn];
vec(pp(ll, ll)) rec, convex;

#define w first
#define h second

void init(){
    ll ma = -1;
    lp(i, 1, n) if(recr[i].h > ma) ma = recr[i].h, rec.push_back(recr[i]);
    n = rec.size() - 1;
}

ll cnp(ll val){
    ll l = 0, r = convex.size();
    while(l < r - 1){
        ll mid = l + r >> 1;
        if(mid && convex[mid].second - convex[mid - 1].second <= val * (convex[mid - 1].first - convex[mid].first))
            l = mid;
        if(mid != convex.size() - 1 && convex[mid + 1].second - convex[mid].second >= val * (convex[mid].first - convex[mid + 1].first))
            r = mid;
    }
    return l;
}

void next_pos(ll &pos, ll val){
    while(pos + 1 < convex.size() && convex[pos + 1].second - convex[pos].second <= val * (convex[pos].first - convex[pos + 1].first))
        ++pos;
}

pp(ll, ll) inter(pp(ll, ll) &l1, pp(ll, ll) &l2){
    pp(ll, ll) frac = {l1.second - l2.second, l2.first - l1.first};
    if(frac.second < 0) frac.first = -frac.first, frac.second = -frac.second;
    return frac;
}

void push_line(pp(ll, ll) line){
    if(convex.size() < 2) convex.push_back(line);
    else{
        while(convex.size() > 1){
            pp(ll, ll) line1 = convex[convex.size() - 2], line2 = convex.back(), in12 = inter(line1, line2), in13 = inter(line1, line);
            if(in12.first * in13.second >= in13.first * in12.second) convex.pop_back();
            else break;
        } 
        convex.push_back(line);
    }
}

void sol(){
    convex.emplace_back(rec[0].w, 0);
    ll pos = 0;
    lp(i, 0, n){
        next_pos(pos, rec[i].h);
        dp[i] = rec[i].h * convex[pos].first + convex[pos].second;
        if(i != n) push_line({rec[i + 1].w, dp[i]});
        pos = min(pos, (ll)convex.size() - 1);
    }
    cout << dp[n];
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> recr[i].w >> recr[i].h;
    sort(recr + 1, recr + 1 + n, greater<pp(ll, ll)>());
    init();
    sol();
}

/*

    dp[i] = min{dp[j] +  rec[j + 1].w * rec[i].h} vs j < i

    b = dp[j], a = rec[j + 1].w

    y = a * x + b

    a' * x + b' = a * x + b
    x = (b - b') / (a' - a) = (b' - b) / (a - a') <= val

*/