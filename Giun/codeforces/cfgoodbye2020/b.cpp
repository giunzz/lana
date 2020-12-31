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
        ll n, cnt = 1, last = 0, num = 0, dem = 0;
        bool ok = 1;
        cin >> n;
        vec(ll) a(n + 1);
        lp(i, 1, n) cin >> a[i];
        ++a[n];
        lpd(i, n - 1, 1) if(a[i] < a[i + 1] - 1) ++a[i];
        set<ll> tmp(a.begin() + 1, a.end());
        cout << tmp.size() << '\n';
    }
}