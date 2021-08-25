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

vec(pp(ll, ll)) a;
ll u, v, ans = 0, cnt = 0;

int main(){
    giuncute();
    lp(i, 0, 1){
        cin >> u >> v;
        if(u > v) swap(u, v);
        a.push_back({u, -1}), a.push_back({v, 1});
    }
    sort(a.begin(), a.end());
    for(pp(ll, ll) i : a){
        if(cnt == 0) ans -= i.first;
        cnt += i.second;
        if(cnt == 0) ans += i.first;
    }
    cout << ans;
}