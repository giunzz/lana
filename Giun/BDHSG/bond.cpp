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

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 22, maxstate = 2e6 + 7;
ll n;
double f[maxn][maxstate], a[maxn][maxn];
bool d[maxstate] = {0};

// #define ONLINE_JUDGE
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) lp(j, 1, n){cin >> a[i][j]; a[i][j] /= (double)100;}
    ll state = 0;
    f[0][0] = 1;
    vector<ll> st[2];
    bool Old = 0, New = 1;
    st[Old].push_back(0);
    lp(i, 1, n){
        while(st[Old].size()){
            ll stt = st[Old].back();
            st[Old].pop_back();
            f[i][stt] = 0;
            ll p = 1;
            lp(j, 1, n){
                ll nstt = p | stt;
                if(!d[nstt]) st[New].push_back(nstt), d[nstt] = 1;
                if(!(p & stt)) f[i][nstt] = max(f[i - 1][stt] * a[i][j], f[i][nstt]);
                p <<= 1;
            }
        }
        Old = !Old, New = !New;
    }
    cout << fixed << setprecision(12) << (f[n][(1LL << n) - 1] * (double)100);
}