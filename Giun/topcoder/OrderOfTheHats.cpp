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

/**
 * dp[mask][i] la so phep bien doi it nhat de di qua dc cac dinh trong mask va ket thuc tai i
 * for tung trang thai trong mask vs vi tri se dung trc i nen status[j][i] = 'Y' va status[i][j] = 'N'
*/
cll mxmask = 1 << 21, mxn = 23;
ll dp[mxmask][mxn];

void errmask(ll mask, ll n){
    lpd(i, n - 1, 0) cerr << ((mask >> i) & 1);
}

class OrderOfTheHats{

private:
    vec(string) a;
    ll sol(ll mask, ll pos){
        if(~dp[mask][pos]) return dp[mask][pos];
        ll &cur = dp[mask][pos], nmask = ~(~mask | (1 << pos));
        if(!nmask) return cur = 0;
        cur = 1e9;
        vec(ll) bi, bo;
        lp(i, 0, n - 1) if((nmask >> i) & 1) bi.push_back(i); else if(i != pos) bo.push_back(i);
        ll tmp;
        for(ll &i : bi){
            tmp = (a[i][pos] != 'Y') + (a[pos][i] != 'N');
            // if(mask == ((1 << n) - 1) && pos == 2) cerr << tmp << ' ' << i << '\n';
            for(ll &j : bi) if(i != j) tmp += (a[pos][j] != 'N') + (a[j][pos] != 'N');
            cur = min(cur, sol(nmask, i) + tmp);
        } 
        return cur;
    }

public:
    ll n;
    ll minChanged(vector<string> spellChart){
        n = spellChart.size(), a = spellChart;
        lp(i, 0, (1 << n) - 1) lp(j, 0, n - 1) dp[i][j] = -1;
        ll ans = 1e9;
        lp(i, 0, n - 1) ans = min(sol((1 << n) - 1, i), ans);
        lp(i, 0, n - 1) ans += (a[i][i] != 'N');
        return ans;
    }

};

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

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    OrderOfTheHats test;
    cout << test.minChanged({"NYYYYYY", "YNYYYYY", "YYNYYYY", "YYYNYYY", "YYYYNYY", "YYYYYNY", "YYYYYYN"});
    // lp(i, 0, (1 << test.n) - 1){
    //     errmask(i, test.n);
    //     cerr << '\n';
    //     lp(j, 0, test.n - 1) cerr << j << ' ' << dp[i][j] << '\n';
    // }
}
