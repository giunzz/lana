#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "catch"
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

cll mxn = 2e3 + 6, dx[] = {-1, -1, -1, 0, 1, 1, 1, 0, 0}, dy[] = {1, 0, -1, -1, -1, 0, 1, 1, 0};
ll a, b, x, y;
string s;
vec(ll) ans;

inline bool check(){
    lp(i, 0, 8) if(x + dx[i] == a && y + dy[i] == b) return 1;
    return 0;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> x >> y >> s;
    s = '.' + s, a = b = 0;
    if(check()) ans.push_back(0);
    lp(i, 1, s.size() - 1){
        if(s[i] == 'U') ++b;
        else if(s[i] == 'D') --b;
        else if(s[i] == 'R') ++a;
        else --a;
        if(check()) ans.push_back(i);
    }
    if(ans.empty()) cout << -1;
    else for(ll i : ans) cout << i << '\n';
}
