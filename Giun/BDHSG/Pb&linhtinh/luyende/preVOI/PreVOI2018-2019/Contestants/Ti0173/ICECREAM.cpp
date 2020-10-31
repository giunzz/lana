#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;
typedef tuple<int,int,int> tp;
int mod = 1e9 + 9;
map<tp, int> dp[305];
int n, Mx, M50, M1, M2, ans;
#define pl pair<tp, int>
inline void add( int &x, int &y ) {
    x += y;
    x %= mod;
}
int sl;
int main() {
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
    cin >> n >> Mx >> M50 >> M1 >> M2;
    dp[0][ mt(M50,M1,M2) ] = 1;
    for(int i = 1; i <= n; ++ i) {
        for(pl p: dp[i-1]) {
            tie(M50,M1,M2) = p.first;
            sl = n - i + 1;
            if( M50 >= 3*sl && M1 >= sl && M50 + sl <= Mx && M1 + sl <= Mx && M2 + sl <= Mx ) {
            long long res = 1;
            for(int i = 1; i <= sl; ++ i) {
                res = (res * 3) % mod;
            }
            ans += res;
            ans %= mod;
            continue;
            }
            if( M50 + 1 <= Mx ) {
                add(dp[i][ mt(M50 + 1, M1, M2) ], p.second );
            }
            if( M1 + 1 <= Mx && M50 >= 1 ) {
                add(dp[i][ mt(M50 - 1, M1 + 1, M2) ], p.second);
            }
            if( M1 >= 1 && M50 >= 1 && M2 + 1 <= Mx ) {
                add( dp[i][ mt( M50 - 1, M1 - 1, M2 + 1 ) ], p.second ); continue;
            }
            if( M50 >= 3 && M2 + 1 <= Mx ) {
                add( dp[i][ mt( M50 - 3, M1, M2 + 1 ) ], p.second );
            }
        }
    }

    for(pl p: dp[n]) {
        add( ans, p.second );
    }
    cout << ans;

    return 0;
}
