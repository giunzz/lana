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

cll mxdg = 33;
ll dp[mxdg][2][2][2][2][3], l, r;
vec(ll) dgl, dgr;

ll solve(ll pos, bool ok1, bool ok2, bool ok3, bool ok4, ll tt){
    ll &cur = dp[pos][ok1][ok2][ok3][ok4][tt];
    if(cur != -1) return cur;
    if(pos == mxdg - 1)
        return cur = 1;
    ll newpos = pos + 1;
    cur = 0;
    lp(nextMsk, 0, 2){
        ll first = nextMsk & 1, second = (nextMsk >> 1) & 1;
        bool newok1, newok2, newok3, newok4;
        if(ok1){
            if(first == dgr[newpos]) newok1 = ok1;
            else if(first > dgr[newpos]) continue;
            else newok1 = 0;
        } else newok1 = 0;
        if(ok2){
            if(second == dgr[newpos]) newok2 = ok2;
            else if(second > dgr[newpos]) continue;
            else newok2 = 0;
        } else newok2 = 0;
        if(ok3){
            if(first == dgl[newpos]) newok3 = ok3;
            else if(first < dgl[newpos]) continue;
            else newok3 = 0;
        } else newok3 = 0;
        if(ok4){
            if(second == dgl[newpos]) newok4 = ok4;
            else if(second < dgl[newpos]) continue;
            else newok4 = 0;
        } else newok4 = 0;
        cur += solve(newpos, newok1, newok2, newok3, newok4, nextMsk);
    }
    return cur;
}

void init(ll n, vec(ll) &dg){  
    dg.clear();
    while(n){
        dg.push_back(n & 1);
        n >>= 1;
    }
    while(dg.size() != mxdg) dg.push_back(0);
    reverse(dg.begin(), dg.end());
}

void sol(){
    ll ans;
    cin >> l >> r;
    init(l, dgl);
    init(r, dgr);
    memset(dp, -1, sizeof dp);
    cout << solve(0, 1, 1, 1, 1, 0) << '\n';
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}