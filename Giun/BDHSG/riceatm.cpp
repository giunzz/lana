#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "riceatm"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, f[maxn] = {0}, trace[maxn] = {0};
pp(ll, ll) a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    a[0] = {0, 0};
    lp(i, 1, n)
        cin >> a[i].first >> a[i].second;
    f[1] = a[1].first;
    lp(i, 2, n){
        f[i] = min(f[i - 1] + a[i].first, f[i - 2] + a[i - 1].second);
    }
    cout << f[n] << '\n';
    ll i = n;
    while(i){
        if(i == 1){
            trace[i] = 1;
            break;
        }
        if(f[i] == f[i - 1] + a[i].first){
            trace[i--] = 1;
        } else if(f[i] == f[i - 2] + a[i - 1].second){
            trace[i] = 0, trace[i - 1] = 2, i -= 2;
        }
    }
    lp(i, 1, n) cout << trace[i] << ' ';
}