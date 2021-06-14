#include "felltrees.h"
#include <bits/stdc++.h>
#define ll int
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

vec(ll) dp, trace, mx;
vec(vec(ll)) res;
vec(bool) done;
ll tot = -1;

bool check(ll &n, vec(ll) &a, vec(ll) &h, ll pos, ll id_next){
    ll next = (id_next < n ? a[id_next] : a.back());
    if(pos == 0) return a[pos] + h[pos] <= next; 
    ll last = (trace.empty() ? a[0] : a[trace.back()]);
    if(pos == n - 1) return a[pos] - h[pos] >= last;
    return a[pos] + h[pos] <= next or a[pos] - h[pos] >= last;
}

vector<int> fell_trees(int n, int q, vector<int> a, vector<int> h, vector<int> l, vector<int> r) {
    vector<int> answer(q);
    dp.assign(n, 0); done.assign(n, 0); mx.resize(n);
    mx[0] = -1;
    lp(i, 0, n - 1){
        if(i) mx[i] = mx[i - 1];
        if(check(n, a, h, i, i + 1)){
            res.push_back(vec(ll){i});
            done[i] = dp[i] = 1;
            mx[i] = ++tot;
            if(trace.empty()){
                ll j = trace.back();
                trace.pop_back();
                while(j != -1 && check(n, a, h, j, i + 1)){
                    res.back().push_back(j);
                    done[j] = 1, ++dp[i];
                    if(trace.empty()) j = -1;
                    else j = trace.back(), trace.pop_back();
                }
                if(j != -1) trace.push_back(j); 
            }
        } else trace.push_back(i);
        if(i) dp[i] += dp[i - 1];
    }
    for (int i = 0; i < q; ++i) {
        ll x = l[i], y = r[i], pre, cnt = dp[y];
        if(x == 0) pre = -1;
        else pre = mx[x - 1], cnt -= dp[x - 1];
        lp(j, pre + 1, mx[y]){
            ll tmp = res[j].size() - (upper_bound(res[j].begin(), res[j].end(), x, greater<int>()) - res[j].begin());
            if(tmp) cnt -= tmp;
        }
        answer[i] = cnt;
    }
    // for(auto i : res){
    //     for(auto j : i) cerr << j << ' ';
    //     cerr << endl;
    // }
    // cerr << dp[4]  << endl;
    return answer;
}
