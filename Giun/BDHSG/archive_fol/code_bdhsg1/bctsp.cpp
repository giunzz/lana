#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 25;
ll n, a[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 0, n - 1) lp(j, 0, n - 1) cin >> a[i][j];
    ll ans = LLONG_MAX;
    if(n == 2){
        cout << (a[0][1] + a[1][0]);
        return 0;
    }
    ll stt = (1LL << n) - 1;
    lp(i, 1, n - 1){
        lp(j, 1, n - 1){
            if(i == j) continue;
            ans = min(dp(stt ^ (1LL << i), j) + )
        }
    }
}