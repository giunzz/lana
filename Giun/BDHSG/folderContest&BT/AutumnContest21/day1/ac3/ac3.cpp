#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "ac3"

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}
#define EACHCASE lpd(cs, read(), 1)

ll a[5][5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    EACHCASE{
        ll cnt = 0, ma = 0;
        lp(i, 1, 3) cin >> a[1][i];
        cin >> a[2][1] >> a[2][3];
        lp(i, 1, 3) cin >> a[3][i];
        cnt += (a[1][1] + a[1][3] == a[1][2] * 2);
        cnt += (a[1][1] + a[3][1] == a[2][1] * 2);
        cnt += (a[3][3] + a[1][3] == a[2][3] * 2);
        cnt += (a[3][3] + a[3][1] == a[3][2] * 2);
        lp(i, -10, 10){
            ll tmp = 0;
            tmp += (a[1][1] + a[3][3] == i * 2);
            tmp += (a[1][3] + a[3][1] == i * 2);
            tmp += (a[1][2] + a[3][2] == i * 2);
            tmp += (a[2][1] + a[2][3] == i * 2);
            ma = max(ma, tmp);
        }
        cout << cnt + ma << '\n';
    }
}
