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

string s;
ll cnt[30], k, ans;

void sol(){
    ans = 0;
    memset(cnt, 0, sizeof cnt);
    cin >> s >> k;
    ll j = 0;
    cnt[s[0] - 'a'] = 1;
    lp(i, 0, s.size() - 1){
        while(j < s.size() - 1 && cnt[s[j + 1] - 'a'] < k)
            ++cnt[s[++j] - 'a'];
        ans += j - i + 1;
        --cnt[s[i] - 'a'];
    }
    cout << ans << '\n';
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}