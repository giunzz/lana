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

cll mxn = 5e4 + 7;
string s;
ll odd[mxn], even[mxn], ans = 0, l, r;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> s;
    l = 0, r = -1;
    lp(i, 0, s.size() - 1){
        ll k = (i > r) ? 1 : min(odd[r - i + l], r - i + 1);
        while(0 <= i - k - 1 && i + k + 1 < s.size() && s[i - k - 1] == s[i + k + 1]) ++k;
        ans = max(ans, (odd[i] = k) * 2 - 1);
        ll nl = i - k + 1, nr = i + k - 1;
        if(nr > r) r = nr, l = nr;
    }
}
