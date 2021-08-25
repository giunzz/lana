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
    scanf("%lld", &tmp);
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

ll sum[100] = {0}, dp[11][82][2][2], a, b;
vec(ll) d_a, d_b;

void init(){
    lp(i, 0, 99){
        if(i < 10) sum[i] = i;
        else{
            ll s = 0, j = i;
            while(j) s += (j % 10), j /= 10;
            sum[i] = sum[s];
        }
    } 
}

inline ll sol(ll pos, ll s, bool ok1, bool ok2){
    if(~dp[pos][s][ok1][ok2]) return dp[pos][s][ok1][ok2];
    ll &cur = dp[pos][s][ok1][ok2], npos = pos - 1, ns;
    bool nok1, nok2;
    if(!pos) return cur = (sum[s] == 9);
    cur = 0;
    lp(i, 0, 9){
        nok1 = ok1, nok2 = ok2;
        if(ok1){
            if(i == d_a[npos]) nok1 = 1;
            else if(i > d_a[npos]) nok1 = 0;
            else continue;
        } 
        if(ok2){
            if(i == d_b[npos]) nok2 = 1;
            else if(i < d_b[npos]) nok2 = 0;
            else continue;
        }
        cur += sol(npos, s + i, nok1, nok2);
    }
    return cur;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    init();
    EACHCASE{
        memset(dp, -1, sizeof dp);
        scanf("%lld %lld", &a, &b);
        d_a.clear();
        while(a) d_a.push_back(a % 10), a /= 10;
        while(d_a.size() < 11) d_a.push_back(0);
        d_b.clear();
        while(b) d_b.push_back(b % 10), b /= 10;
        while(d_b.size() < 11) d_b.push_back(0);
        printf("%lld\n", sol(10, 0, 1, 1));
    }
}