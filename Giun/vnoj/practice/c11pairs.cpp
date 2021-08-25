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

cll mxn = 5e5 + 3;
ll n, a[mxn], ans = 0;
vector<pp(ll, ll)> dq;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
        ll tot = 1;
        while(dq.size() && dq.back().first <= a[i]){
            if(dq.back().first == a[i]) tot += dq.back().second;
            dq.pop_back();
        }
        ans += tot - 1;
        if(dq.size()) ++ans;
        dq.push_back({a[i], tot});
    }
    dq.clear();
    lpd(i, n, 1){
        while(dq.size() && dq.back().first <= a[i]) dq.pop_back();
        if(dq.size()) ++ans;
        dq.push_back({a[i], 1});
    }
    cout << ans;
}