#include <bits/stdc++.h>
#define ll long long
#define cll long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define fname "dannhan"
using namespace std;

ll n;
bool f[(ll)1e7 + 7] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(fname".inp", "r", stdin);
    freopen(fname".out", "w", stdout);
    cin >> n;
    ll cnt = 0, cnts = 0, tmp;
    lp(i, 1, n){
        cin >> tmp;
        if(!f[tmp]) {++cnts;}
        ++cnt, f[tmp] = 1;
    }
    cout << (cnt - cnts);
}
