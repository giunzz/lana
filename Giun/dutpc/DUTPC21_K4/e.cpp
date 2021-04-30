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

cll mxn = 1e3 + 7;
ll MOD, n, k, dp[mxn][mxn] = {{0}};
//dp[i][j]

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> k >> MOD;
    lp(i, 1, n) dp[i][1] = 1;
    lp(i, 2, n) lp(j, 2, i){
        lp(k, j, i / 2) 
    }
}

// #include <bits/stdc++.h>
// #define ll long long
// #define cll const ll
// #define lp(a, b, c) for(ll a = b; a <= c; ++a)
// #define lpd(a, b, c) for(ll a = b; a >= c; --a)
// #define vec(a) vector<a>
// #define pp(a, b) pair<a, b>
// #define EACHCASE lpd(cs, read(), 1)
// #define Fname "f"
// using namespace std;

// template <typename T> inline void Read(T &x){
//     x = 0; char c;
//     while(!isdigit(c = getchar()));
//     do
//     {
//         x = x * 10 + c - '0';
//     } while (isdigit(c = getchar()));
// }

// ll read(){
//     ll tmp;
//     cin >> tmp;
//     return tmp;
// }

// void giuncute(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
// }

// void OF(){
//     freopen(Fname".inp", "r", stdin);
//     freopen(Fname".out", "w", stdout);
// }

// cll mxn = 1e3 + 7;
// ll n, m, MOD, dp[mxn][mxn] = {{0}}, sum[mxn][mxn] = {{0}};

// int main(){
//     giuncute();
//     OF();
//     cin >> n >> m >> MOD;
//     dp[0][0] = sum[0][0] = 1;
//     lp(i, 1, n) sum[i][0] = 1;
//     lp(i, 1, n) lp(j, 1, m){
//         if(j > i) sum[i][j] = sum[i - 1][j];
//         else{
//             dp[i][j] = sum[i - 1][j - 1];
//             if(j - 2 >= 0) (((dp[i][j] -= sum[j - 2][j - 1]) %= MOD) += MOD) %= MOD;
//             (sum[i][j] = sum[i - 1][j] + dp[i][j]) %= MOD;
//         }
//     }
//     cerr << dp[3][2];
//     cout << sum[n][m];
// } 