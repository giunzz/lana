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

cll mxx = 7e4;
ll x, a, b, dp[2][2][13][mxx];
bool al[10] = {0};
vec(ll) dg, dg_n;
string s;

void inp(){
    cin >> s;
    for(char i : s) dg.push_back(i - '0'), al[i - '0'] = 1;
}

ll sol_dp(bool equal, bool first0, int pos, ll div){
    ll &cur = dp[equal][first0][pos][div], npos = pos - 1, div10 = (div * 10) % x;
    bool nequal = equal;
    if(~cur) return cur;
    if(!pos) return cur = ((!div && !first0) || (first0 && al[0]));
    cur = 0;
    if(first0) cur += sol_dp(0, first0, npos, 0);
    for(int ndig : dg){
        if(first0 && !ndig) continue;
        if(equal){
            if(ndig > dg_n[npos]) break;
            if(ndig < dg_n[npos]) nequal = 0;
            else nequal = 1;
        }
        cur += sol_dp(nequal, 0, npos, (div10 + ndig) % x);
    }   
    return cur;
}

ll pre_dp(ll num){
    dg_n.clear();
    s = to_string(num);
    reverse(s.begin(), s.end());
    for(char i : s) dg_n.push_back(i - '0');
    memset(dp, -1, sizeof dp);
    return sol_dp(1, 1, dg_n.size(), 0);
}

void case_dp(){
    cout << pre_dp(b) - pre_dp(a - 1);
}

inline bool check(ll num){
    while(num){
        if(!al[num % 10]) return 0;
        num /= 10;
    }
    return 1;
}

void case_bruce(){
    ll l = (a + x - 1) / x, r = b / x, cnt = 0;
    lp(i, l, r)
        if(check(i * x)) ++cnt;
    cout << cnt;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> x >> a >> b;
    inp();
    if(x <= mxx) case_dp();
    else case_bruce();
}