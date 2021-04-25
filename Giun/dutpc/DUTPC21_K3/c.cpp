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

cll mxn = 1e6 + 7, mxv = 1e9 + 7;
ll n, a[mxn], tot = 0;
bool d[mxv] = {0};
unordered_map<ll, ll> cnt;

#define ONLINE_JUDGE
int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
        if(!d[a[i]]) ++tot, d[a[i]] = 1;
    }
    ll i = 1, ans = n, cnt_type = 1;
    ++cnt[a[1]];
    lp(j, 2, n){
        ++cnt[a[j]];
        if(cnt[a[j]] == 1) ++cnt_type;
        if(cnt_type == tot){
            while(cnt[a[i]] > 1) --cnt[a[i++]];
            ans = min(ans, j - i + 1);
            --cnt[a[i++]];
            --cnt_type;
        } 
    }
    cout << ans;
}