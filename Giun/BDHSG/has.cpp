#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

ll k;
vec(ll) ans;

void solve(){
    ll a, b, x, alf;
    for(ll i = 1; i * i <= k; i++){
        if(!(k % i)){
            a = i, b = k / i;
            if(!((b - a) & 1)){
                x = (b - a) / 2; alf = a;
                ans.push_back(x*x);
                ans.push_back(-(x + alf)*(x + alf));
            } 
        }
    }
    ll tmp = k / 2;
    for(ll i = 1; i * i <= tmp; i++){
        a = i * i, b = k - a, x = sqrt(b);
        if(x * x == b){
            ans.push_back(-a); ans.push_back(-b);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> k;
    solve();
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(ll v : ans){
        cout << v << ' ';
    }
}