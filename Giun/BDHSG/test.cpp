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

int main(){
    giuncute();
    // #ifndef ONLINE_JUDGE
    // OF();
    // #endif
    // lp(i, 1, 8){
    //     cerr << i << ' ';
    //     ll sum = i * 15;
    //     lp(j, 1, 8) if(i != j) sum += j * 20;
    //     cerr << sum << '\n';
    // }
    double ans = 1;
    lp(i, 1, 6) ans = ans * 2 + 0.5;
    double test = 0, t = 96;
    lp(j, 1, 1000) {t = j; lp(i, 1, 6) t = t / 2- 0.5; if(t == 1.0){cout << j << ' ' << t; break;}}
    // cout << t;
}