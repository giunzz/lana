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

cll mxn = 5e3 + 7;
string s;
ll dpL[mxn] = {0}, dpR[mxn] = {0};
pp(ll, ll) dp[mxn][mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> s;
    s = '.' + s;
    lp(i, 1, s.size() - 1){
        if(dpL[i - 1] == 1e17) dpL[i] = dpL[i - 1];
        else if(s[i] == '(') dpL[i] = dpL[i - 1] + 1;
        else if(dpL[i - 1]) dpL[i] = dpL[i - 1] - 1;
        else dpL[i] = 1e17;
    }
    lpd(i, s.size() - 1, 1){
        if(dpR[i + 1] == 1e17) dpR[i] = dpR[i + 1];
        else if(s[i] == ')') dpR[i] = dpR[i + 1] + 1;
        else if(dpR[i + 1]) dpR[i] = dpR[i + 1] - 1;
        else dpR[i] = 1e17;
    }
    if(!dpL[s.size() - 1]){
        cout << "possible";
        return 0;
    }
    lp(i, 1, s.size() - 1){
        dp[i][i - 1].first = dpL[i - 1];
        lp(j, i, s.size() - 1){
            dp[i][j] = dp[i][j - 1];
            if(s[j] == ')') dp[i][j].first = dp[i][j - 1].first + 1;
            else if(dp[i][j - 1].first) dp[i][j].first = dp[i][j - 1].first - 1;
            else dp[i][j].second = dp[i][j - 1].second + 1;
            if(dp[i][j].first == dpR[j + 1] && !dp[i][j].second && dpR[j + 1] <= s.size()){ 
                cout << "possible";
                return 0;
            }
        }
    }
    cout << "impossible";
}