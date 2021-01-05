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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    ll cs;
    cin >> cs;
    while(cs--){
        ll n, x, ans = 0, last = 0;
        cin >> n >> x;
        vec(pp(ll, ll)) a(n + 1);
        lp(i, 1, a.size() - 1){
            if(i <= n) {cin >> a[i].first; a[i].second = 1;}
            if(a[i].first % x){last = i; break;}
            // cerr << a[i].first << ' ' << a[i].second << ' ' << a[i].second * x << '\n';
            a.push_back({a[i].first/x, a[i].second * x});
            ans += a[i].first * a[i].second;
        }
        // cerr << last << '\n';
        if(last < n) lp(i, last + 1, n) {cin >> a[i].first; a[i].second = 1;} 
        if(last) lp(i, last, a.size() - 1) ans += a[i].first * a[i].second;
        cout << ans << '\n';
    }
}