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

cll mxn = 1e5 + 7;
ll n, a[mxn], cntneg = 0, ans = 0, cntpos = 0;
bool ok = 0;

void sol(){
    ll j = 0;
    cntneg = ok = 0;
    lp(i, 1, n){
        if(!a[i]){
            j = i;
            cntneg = 0, ok = 0;
        }
        if(a[i] % 2 == 0) ok = 1;
        if(a[i] < 0) ++cntneg;
        if(cntneg % 2 == 0 && ok) ans = max(ans, i - j);
        // cerr << cntneg <<  ' ';
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    sol();
    reverse(a + 1, a + 1 + n);
    sol();
    cout << ans;
}