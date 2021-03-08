#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxk = 1e5 + 7, upright[] = {4, -2, 1}, upleft[] = {4, 0, 1}, downleft[] = {4, -2, 1}, downright[] = {4, -4, 2};
ll n, k, b[mxk];
vec(pp(ll, ll)) e;
unordered_map<ll, ll> dp;

inline ll cnp(cll *eq, ll l, ll r, ll d, ll val){
    ll res;
    while(l * d <= r * d){
        ll mid = (l + r) / 2;
        if(eq[0] * mid * mid + eq[1] * mid + eq[2] < val) res = mid, l = mid + d;
        else r = mid - d;
    }
    return res;
}

inline ll Find(ll t){
    ll l = 0, r = e.size() - 1, res = -1;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(e[mid].first <= t) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    return res;
}

ll sol(ll t){
    if(dp[t] || t == 1) return dp[t];
    ll pos = Find(t);
    if(pos == -1)
        return dp[t] = t - 1;
    if(e[pos].first == t)
        return dp[t] = sol(e[pos].second) + 1;
    ll res = sol(e[pos].second) + t - e[pos].first + 1;
    if(pos != e.size() - 1 && t - e[pos + 1].second > e[pos + 1].first - t + 1)
        res = min(res, sol(e[pos + 1].second) + e[pos + 1].first - t + 1);
    return dp[t] = res;
}

int main(){
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    scanf("%lld %lld", &n, &k);
    lp(i, 1, k){
        scanf("%lld", &b[i]);
        ll num1, tmp, last, ke;

        tmp = cnp(upright, 0, 16e6, 1, b[i]);
        num1 = upleft[0] * tmp * tmp + upleft[1] * tmp + upleft[2];
        if(b[i] < num1){
            last = tmp - 1, ke = upleft[0] * last * last + upleft[1] * last + upleft[2] - (num1 - b[i] - 1);
            e.push_back({b[i], ke});
            continue;
        }

        tmp = -cnp(upleft, 0, 16e6, 1, b[i]);
        num1 = downleft[0] * tmp * tmp + downleft[1] * tmp + downleft[2];
        if(b[i] < num1){
            last = tmp + 1, ke = downleft[0] * last * last + downleft[1] * last + downleft[2] - (num1 - b[i] - 1);
            e.push_back({b[i], ke});
            continue;
        }
        
        tmp = cnp(downleft, 0, -16e6, -1, b[i]);
        num1 = downright[0] * tmp * tmp + downright[1] * tmp + downright[2];
        if(b[i] < num1){
            last = tmp + 1, ke = downright[0] * last * last + downright[1] * last + downright[2] - (num1 - b[i] - 1);
            e.push_back({b[i], ke});
            continue;
        }

        tmp = 1 - cnp(downright, 0, -16e6, -1, b[i]);
        num1 = upright[0] * tmp * tmp + upright[1] * tmp + upright[2];
        if(b[i] < num1){
            last = tmp - 1, ke = upright[0] * last * last + upright[1] * last + upright[2] - (num1 - b[i] - 1);
            e.push_back({b[i], ke});
            continue;
        }
    }
    sort(e.begin(), e.end());
    printf("%lld", sol(n));
    // cerr << clock();
}