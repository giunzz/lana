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

cll mxn = 5e4 + 3;
ll n, m, k, a[mxn], b[mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> k;
    lp(i, 1, n) cin >> a[i];
    lp(i, 1, m) cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    set<pp(ll, pp(ll, ll))> q;
    q.insert({a[1] + b[1], {1, 1}});
    ll cnt = 0;
    while(q.size() && cnt != k){
        ll sum = (*q.begin()).first, u = (*q.begin()).second.first, v = (*q.begin()).second.second;
        q.erase(q.begin());
        cout << sum << '\n';
        ++cnt;
        q.insert({a[u + 1] + b[v], {u + 1, v}});
        q.insert({a[u] + b[v + 1], {u, v + 1}});
    }
}