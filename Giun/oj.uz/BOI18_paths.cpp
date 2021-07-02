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

cll mxn = 3e5 + 7, mxk = 5;
ll n, m, k, a[mxn], dp[mxn][1 << mxk] = {{0}}, ans = 0;
vec(ll) g[mxn], state[6];

inline ll cntbit(ll x){
    if(!x) return 0;
    return cntbit(x >> 1) + (x & 1);
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> k;
    lp(i, 1, n) a[i] = read() - 1, dp[i][1 << a[i]] = 1;
    lp(i, 1, m){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    lp(i, 1, (1 << mxk) - 1) if(i < (1 << k)) state[cntbit(i)].push_back(i);
    lp(i, 2, k){
        lp(u, 1, n){
            for(ll stt : state[i]){ 
                if(stt & (1 << a[u]))
                    for(ll v : g[u]) 
                        dp[u][stt] += dp[v][stt ^ (1 << a[u])];
                ans += dp[u][stt];
            }
        }
    }
    cout << ans;
}