#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, f[maxn], q, tt[3] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("balls");
    cin >> n >> q;
    ll tmp;
    lp(i, 1, n) {
        cin >> tmp;
        ++tt[tmp - 1];
        tt[1] += tt[0] / 2;
        tt[0] %= 2;
        tt[2] += tt[1] / 2;
        tt[1] %= 2;
        f[i] = tt[0] + tt[1] + tt[2];
    }
    lp(i, 1, q){
        cin >> tmp;
        cout << f[tmp] << ' ';
    }
}