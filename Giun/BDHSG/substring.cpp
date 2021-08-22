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

ll n, k, cnt[200] = {0}, ans = 0;
string s;

int main(){
    giuncute();
    cin >> n >> k >> s;
    ll j = 0, cnt_type = 0;
    lp(i, 0, s.size() - 1){
        if(!cnt[s[i]]++) ++cnt_type;
        while(cnt_type > k)
            if(!(--cnt[s[j++]])) --cnt_type;
        if(cnt_type == k) ans = max(ans, i - j + 1);
    }
    cout << ans;
}
