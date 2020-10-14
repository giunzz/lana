#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxm = 1e5 + 7;
ll n, cnt[maxm] = {0};
vec(ll) a;

vec(ll) cpress(vec(ll) x){
    set<ll> tmp(x.begin()+1, x.end());
    vec(ll) tt(tmp.begin(), tmp.end());
    return tt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    OF();
    cin >> n;
    a.resize(n + 2);
    lp(i, 1, n + 1){
        cin >> a[i];
        ++cnt[a[i]];
    }
    a = cpress(a);
                                                       
}