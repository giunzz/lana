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

cll maxn = 1e3 + 7, maxmask = (1LL << 10) + 7;
ll a[maxn][maxn], n, m, dp[maxn][maxmask] = {{0}};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m;
    lp(i, 1, n){
        lp(i, 0, m - 1){
            char c;
            cin >> c;
            if(c == '#') a[i][j] = 1;
            else a[i][j] = 0;
        }
    } nm 
    lp(i, 0, n) lp(mask, 0, (1LL << m))
    lp(i, 1, n){
        lp(mask, 0, )
    }
}