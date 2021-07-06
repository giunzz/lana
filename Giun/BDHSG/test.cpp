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

cll N = 5e5;
ll l[N + 3][18] = {{0}}, r[N + 3][18] = {{0}};

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    lp(i, 1, N) lp(j, 1, 15) if(j <= i) l[i][j] = l[i][j - 1] + (__gcd(i - j, i) == 1);
    lpd(i, N, 1) lp(j, 1, 15) if(j <= i) r[i][j] = r[i][j - 1] + (__gcd(i + j, i) == 1);
    lp(i, 1, N) lp(j, 0, 15) if(l[i][j] + r[i][15 - j] != 15) cerr << i - j << ' ' << i << ' ' << i + 15 - j << ' ' << j << '\n';  
}