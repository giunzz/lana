#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "ac6";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
ll qr, n, m, k, d, g[5], tt[maxn];
char tmp;

struct stc{
    ll kt, vl;
}dp[maxn];

bool operator>(const stc a1, const stc a2){
    return(a1.vl > a2.vl || (a1.vl == a2.vl && a1.kt > a2.kt));
}

bool operator==(const stc a1, const stc a2){
    return(a1.vl == a2.vl && a1.kt == a2.kt);
}

bool operator<(const stc a1, const stc a2){
    return(a1.vl < a2.vl || (a1.vl == a2.vl && a1.kt < a2.kt));
}

bool operator>=(const stc a1, const stc a2){
    return(a1 > a2 || a1 == a2);
}

void init(){
    stc tmp1 = {k, INT_MIN}, tmp2 = {k, INT_MIN};
    if(tt[1]) dp[1] = {k, -d};
    else dp[1] = {k - 1, g[1]};
    if(tt[2]){
        dp[2] = {dp[1].kt, dp[1].vl - d};
    }
    else{
        if(tt[1]){
            dp[2] = {dp[1].kt, dp[1].vl - d};
        }
        else {
            tmp1 = {dp[1].kt - 1, dp[1].vl + g[1]};
            tmp2 = {dp[0].kt, dp[0].vl + g[2]};
            dp[2] = max(tmp1, max(tmp2, dp[1]));
        }
    }
}

void sol(){
    stc tmp1, tmp2, tmp3;
    lp(i, 3, n){
        if(tt[i]) {
            dp[i] = {dp[i - 1].kt, dp[i - 1].vl - d};
        }
        else{
            if(dp[i - 1].kt > 0) tmp1 = {dp[i - 1].kt - 1, dp[i - 1].vl + g[1]};
            if(tt[i - 1] && !tt[i - 2]){
                tmp2 = {dp[i - 3].kt, dp[i - 3].vl + g[3] - d};
            }
            if(!tt[i - 1]) tmp3 = {dp[i - 2].kt, dp[i - 2].vl + g[2]};
            dp[i] = max(tmp1, max(tmp2, max(tmp3, dp[i - 1])));
        }
    }
}

int main(){
    opt;
    file;
    cin >> qr;
    while(qr--){
        cin >> n >> m >> k >> d >> g[1] >> g[2] >> g[3];
        lp(i, 0, n + 2) dp[i] = {k, 0};
        lp(i, 1, n){
            cin >> tmp;
            if(tmp == '#') tt[i] = -d;
            else tt[i] = 0;
        } 
        init();
        sol();
        cout << dp[n].vl << endl;
    }
}
