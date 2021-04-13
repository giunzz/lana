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

const int N = 300000000;
bool lp[N+3] = {0};

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    lp[1] = 1;
    for (int i=2; i * i<=N; ++i) {
        if(!lp[i]){
            for(int j = i * i; j <= N; j += i) lp[j] = 1;
        }
    }
    ll l, r, ans = 0;
    cin >> l >> r;
    for(int i = 1; i * i <= r / 2; ++i){
        for(int j = i; j * j + i * i <= r; ++j){
            if(i * i + j * j >= l) ans += !lp[i * i + j * j];
        }
    }
    cout << ans;
}