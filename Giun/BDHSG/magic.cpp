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

cll mxn = 105;
ll n, m, a[mxn][mxn];

int main(){
    giuncute();
    cin >> n >> m;
    lp(i, 1, n) lp(j, 1, m){
        char c;
        cin >> c;
        a[i][j] = (c == '.');
    }
    lp(i, 1, n) lp(j, m + 1, 2 * m) a[i][j] = a[i][2 * m - j + 1];
    lp(i, n + 1, 2 * n) lp(j, 1, 2 * m) a[i][j] = a[2 * n - i + 1][j];
    ll x, y;
    cin >> x >> y;
    a[x][y] = !a[x][y];
    lp(i, 1, 2 * n){
        lp(j, 1, 2 * m) 
            if(a[i][j]) cout << '.';
            else cout << '#';
        cout << '\n';
    }
}