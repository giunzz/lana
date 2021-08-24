#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "dienso"
using namespace std;

cll mxn = 1e6 + 6;
ll n;
vec(pp(ll, char)) a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    lp(i, 1, n){
        char c;
        cin >> c;
        if(a.empty() || a.back().second != c) a.push_back({1, c});
        else ++a.back().first;
    }
    ll ans = 0;
    if(a[0].second == '>') ans = a[0].first;
    lp(i, 0, a.size() - 1){
        if(a[i].second == '<'){
            ans += (a[i].first - 1) * a[i].first / 2;
            if(i < a.size() - 1) ans += max(a[i].first, a[i + 1].first);
            else ans += a[i].first;
        } else{
            ans += a[i].first * (a[i].first - 1) / 2;
        }
    }
    cout << ans;
}
