#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include<iostream>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "daotau"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxk = 1e5 + 7, upright[] = {4, -2, 1}, upleft[] = {4, 0, 1}, downleft[] = {4, -2, 1}, downright[] = {4, -4, 2};
ll n, k, b[mxk], nt[mxk] = {0};
vec(pp(ll, ll)) e;
unordered_map<ll, ll> dp, hs;

inline ll cnp(cll *eq, ll l, ll r, ll d, ll val){
    ll res = 0;
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

ll sol(){
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    q.push({-1, n});
    dp[n] = -1, dp[1] = 1e16;
    while(q.size()){
        ll u = q.top().second, cu = q.top().first;
        q.pop();
        if(dp[u] != cu) continue;
        // fprintf(stderr, "%lld %lld\n", cu, u);
        if(u == 1) break;
        if(cu == -1) cu = 0;
        ll pos = nt[hs[u]];
        if(dp[1] > cu + u - 1){
            dp[1] = cu + u - 1;
            q.push({dp[1], 1});
        }
        if(pos != -1 && e[pos].first == u){
            if(!dp[e[pos].second] || dp[e[pos].second] > cu + 1){
                dp[e[pos].second] = cu + 1;
                q.push({dp[e[pos].second], e[pos].second});
            }
        } else{
            ll v1, v2;
            if(pos != -1){
                v1 = e[pos].first, v2 = e[pos].second;
                if(!dp[v2] || dp[v2] > cu + u - v1 + 1){
                    dp[v2] = cu + u - v1 + 1;
                    q.push({dp[v2], v2});
                }
            }
            if(pos != e.size() - 1){
                v1 = e[pos + 1].first, v2 = e[pos + 1].second;
                if(!dp[v2] || dp[v2] > cu + v1 - u + 1){
                    dp[v2] = cu + v1 - u + 1;
                    q.push({dp[v2], v2});
                }
            }
        }
    }
    return dp[1];
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
    ll j = e.size() - 1;
    lpd(i, e.size() - 1, 0){
        hs[e[i].second] = i;
        while(j != -1 && e[j].first > e[i].second) --j;
        nt[i] = j;
    }
    if(!hs[n]){
        hs[n] = e.size();
        nt[e.size()] = Find(n);
    }
    printf("%lld", sol());
    // cerr << clock();
}