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

ll n, k, m, ans;
multiset<ll> a;

int main(){
    giuncute();
    OF();
    cin >> k >> m >> n;
    lp(i, 1, n)
        a.insert(read());
    if(n == 1){
        cout << *(a.begin());
        return 0;
    }
    multiset<ll>::iterator b = a.begin(), e = a.end();
    --e;
    ans = *e - *b;
    lp(i, 1, m){
        b = a.begin(), e = a.end();
        --e;
        ll valb = *b, vale = *e;
        if(vale < k) break;
        a.erase(b); a.erase(e);
        valb += k, vale -= k;
        a.insert(valb), a.insert(vale);
        e = a.end();
        --e;
        ans = min(ans, *e - *(a.begin()));
    }
    cout << ans;
}