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

cll maxn = 5e3 + 7, MOD = 1e9 + 7;
ll n, a[maxn], dp[maxn][maxn] = {{0}}, numNode[maxn] = {0};

#define ONLINE_JUDGE
int main(){
    srand((int)time(0));
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    vec(ll) a{1, 2, 3, 4, 5, 6, 7};
    random_shuffle(a.begin(), a.end());
    for(ll i : a) cerr << i << ' ';
}