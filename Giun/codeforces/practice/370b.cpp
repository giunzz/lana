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

cll mxn = 103;
ll n, cnt[mxn] = {0};
vec(ll) a[mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        ll tmp;
        cin >> tmp;
        lp(j, 1, tmp){
            a[i].push_back(read());
            ++cnt[a[i].back()];
        }
    }
    // lp(i, 1, 13) cerr << i << ' ' << cnt[i] << '\n';
    lp(i, 1, n){
        bool ok = 1;
        for(ll j : a[i]) cnt[j] = -cnt[j];
        lp(j, 1, n) if(i != j){
            bool okk = 0;
            for(ll k : a[j]) if(cnt[k] > 0) okk = 1;
            if(!okk) ok = 0;
        // if(i == 1 && j == 3) cerr << cnt[10];
        }
        for(ll j : a[i]) cnt[j] = -cnt[j];
        cout << (ok ? "YES\n" : "NO\n");
    }
}