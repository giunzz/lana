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

cll mxn = 1e6 + 7;
ll n, a, b, c, sum[mxn] = {0}, dp[mxn] = {0};
vec(pp(ll, ll)) convex;

void input(){
    convex.clear();
    cin >> n >> a >> b >> c;
    lp(i, 1, n) sum[i] = sum[i - 1] + read();
}

ll pt(ll x){
    return a * x * x + b * x + c;
}

void push_line(pp(ll, ll) line){
    if(convex.size() < 2) convex.push_back(line);
    else{
        while(convex.size() > 1){
            pp(ll, ll) line1 = convex[convex.size() - 2], line2 = convex.back();
            if(line1.first - line2.first <= )
        }

    }
}

void sol(){
    ll j = 0;
    dp[1] = pt(sum[1]);
    convex.push_back({-2 * a * sum[1], dp[1] + a * sum[1] * sum[1] - b * sum[1]});
    lp(i, 2, n){
        while(j + 1 < convex.size() && convex[j].first - convex[j + 1].first <= sum[i] * (convex[j + 1].second - convex[j].second))
            ++j;
        dp[i] = pt(sum[i]) + convex[j].first * sum[i] + convex[j].second;
        push_line({-2 * a * sum[i], dp[i] + a * sum[i] * sum[i] - b * sum[i]});
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE{input(); sol();}
}