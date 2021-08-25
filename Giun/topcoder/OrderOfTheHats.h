#include <bits/stdc++.h>
#define ll int
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

cll mxmask = 1 << 21, mxn = 23;
ll dp[mxmask];

class OrderOfTheHats{
private:
    vec(string) a;
    inline ll sol(ll mask){
        if(~dp[mask]) return dp[mask];
        ll &cur = dp[mask];
        if(!mask) return cur = 0;
        cur = 1e9;
        // vec(ll) bi;
        // lp(i, 0, n - 1) if((mask >> i) & 1) bi.push_back(i); 
        ll tmp;
        // for(ll &i : bi){
        //     tmp = 0;
        //     for(ll &j : bi) tmp += (a[j][i] == 'Y');
        //     cur = min(cur, sol(~(~mask | (1 << i))) + tmp);
        // }
        lp(i, 0, n - 1) if((mask >> i) & 1){
            tmp = 0;
            lp(j, 0, n - 1) if((mask >> j) & 1) tmp += (a[j][i] == 'Y');
            cur = min(cur, sol(~(~mask | (1 << i))) + tmp);
        }
        return cur;
    }

public:
    ll n;
    ll minChanged(vector<string> spellChart){
        n = spellChart.size(), a = spellChart;
        lp(i, 0, (1 << n) - 1) dp[i] = -1;
        return sol((1 << n) - 1);
    }
};