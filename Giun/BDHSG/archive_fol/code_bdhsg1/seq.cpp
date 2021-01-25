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

cll maxn = 17000;
ll n, a[maxn];

ll dq(ll l, ll r){
    if(l >= r) return 0;
    ll mid = a[r] - a[l - 1];
    if(mid & 1) return 0;
    mid = (mid >> 1) + a[l - 1];
    ll x = l, y = r, t1 = 0, t2;
    while(x <= y){
        ll z = (x + y) >> 1;
        if(a[z] == mid){
            t1 = z;
            y = z - 1;
        }
        else if(a[z] > mid) y = z - 1;
        else x = z + 1;
    }
    if(!t1) return 0;
    x = t1, y = r;
    while(x <= y){
        ll z = (x + y) >> 1;
        if(a[z] == mid){
            t2 = z;
            x = z + 1;
        }
        else if(a[z] > mid) y = z - 1;
        else x = z + 1;
    }
    // cerr << l << ' ' << r << ' ' << t1 << ' ' << t2 << ' ' << mid << '\n';
    return max(dq(l, (t1 + t2)/2), dq((t1 + t2)/2 + 1, r)) + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    ll t;
    cin >> t;
    while(t--){
        cin >> n;
        a[0] = 0;
        lp(i, 1, n){
            cin >> a[i];
            a[i] += a[i - 1];
        }
        cout << dq(1, n) << '\n';
    }
}