#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "sample"
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

cll mxm = (1 << 12) + 3;
ll n, m, k, cnt[mxm] = {0}, ma = 0, ans = 0;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> k;
    lp(i, 1, n){
        string s;
        cin >> s;
        ll num = bitset<64>(s).to_ullong();
        ++cnt[num];
        ma = max(ma, num);
    }
    lp(i, 0, ma){
        lp(j, 0, i){
            if(bitset<64>(i ^ j).count() == k) ans += cnt[i] * cnt[j];
        }
    }
    cout << ans;
}