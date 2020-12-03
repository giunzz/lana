#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "brodo"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 3e5 + 7;
ll n, a[maxn], d[maxn] = {0};
vec(vec(ll)) res;
vec(ll) r;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
        --a[i];
        // cerr << a[i] << ' ';
    }
    // cerr << '\n';
    lp(i, 2, n){
        if(d[i]) continue;
        d[i] = 1;
        // cerr << a[i] << '\n';
        res.push_back(vec(ll)());
        res.back().push_back(a[i]);
        ll next = 2*a[i];
        lp(j, i + 1, n){
            if(a[j] == next){
                res.back().push_back(a[j]);
                d[j] = 1;
                next += a[i];
            }
            else if(a[j] > next) break;
        }
    }
    cout << res.size();
}