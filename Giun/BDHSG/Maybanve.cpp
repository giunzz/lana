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

const string table[] = {
    "***ABCDE",
    "FGHIJKLM",
    "NOPQRSTU",
    "VWXYZ***"
};

cll mxn = 55;
ll n;
string s, a[mxn];
bool d[300] = {0};

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    cin >> s;
    lp(i, 1, n)
        if(a[i].substr(0, s.size()) == s)
            if(s.size() < a[i].size()) d[a[i][s.size()]] = 1;
    lp(i, 0, 3){
        lp(j, 0, 7) cout << (d[table[i][j]] ? table[i][j] : '*');
        cout << '\n';
    }
}