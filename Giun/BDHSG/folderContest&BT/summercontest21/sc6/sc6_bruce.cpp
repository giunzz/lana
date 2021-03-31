#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "sc6"
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
    freopen(Fname".ans", "w", stdout);
}

#define type second
#define deep first

cll mxn = 17;
ll n, k, m, ans = 0;
pp(ll, ll) a[mxn];
vec(ll) tmp;
bool d[mxn];

void ql(ll pos, ll cnt){
    if (pos == n){
        if(cnt != k) return;
        set<ll> s;
        for(ll i : tmp){
            if(s.size() == m) break;
            s.insert(i);
        }
        for(auto i : s) if(!d[i]) return;
        ++ans;
        return;
    }
    ll npos = pos + 1;
    if(n - npos + cnt >= k) ql(npos, cnt);
    tmp.push_back(a[npos].type);
    ql(npos, cnt + 1);
    tmp.pop_back();
}

void sol(){
    ans = 0;
    lp(i, 1, 15) d[i] = 0;
    tmp.clear();
    cin >> n >> k >> m;
    lp(i, 1, n) cin >> a[i].type;
    lp(i, 1, n) cin >> a[i].deep;
    lp(i, 1, m) d[read()] = 1;
    sort(a + 1, a + 1 + n);
    lp(i, 1, n) cerr << a[i].first << ' ' << a[i].second << '\n';
    ql(0, 0);
    cout << ans << '\n';
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}