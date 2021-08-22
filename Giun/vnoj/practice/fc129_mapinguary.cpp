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

cll mxn = 2e5 + 6;
ll n, dp[mxn][10];
vec(ll) card[mxn][4];

void inp(){
    ll tmp, c, d;
    vec(ll) tmp_card[4];
    cin >> n;
    lp(i, 1, n){
        cin >> tmp;
        lp(j, 1, tmp){
            cin >> c >> d;
            tmp_card[c].push_back(d);
        }
        lp(j, 1, 3) sort(tmp_card[j].begin(), tmp_card[j].end(), greater<ll>());
        lp(j, 0, 2) if(j < tmp_card[1].size()) card[i][1].push_back(tmp_card[1][j]);
        if(tmp_card[2].size() != 0) card[i][2].push_back(tmp_card[2][0]);
        if(tmp_card[3].size() != 0) card[i][3].push_back(tmp_card[3][0]);
        lp(i, 1, 3) tmp_card[i].clear();
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    inp();
    
}