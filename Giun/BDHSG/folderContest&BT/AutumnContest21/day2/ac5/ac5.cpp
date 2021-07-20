#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "ac5"

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}
#define EACHCASE lpd(cs, read(), 1)

ll mimov[100][100] = {{0}}, cnt[100] = {0}, dp[100][100];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    lp(i, 'a', 'z') lp(j, 'a', 'z') mimov[i][j] = min({abs(i - j), 'z' - i + j - 'a', 'z' - j + i - 'a'});
    EACHCASE{
        memset(cnt, 0, sizeof cnt);
        memset(dp, 0, sizeof dp);
        cin >> s;
        for(char c : s) cnt[c] = !cnt[c];

    }
}