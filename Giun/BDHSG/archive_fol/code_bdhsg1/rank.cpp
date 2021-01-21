#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "rank"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 3e5 + 7;
ll n, k, cnt[25] = {0}, a[maxn], ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> k;
    lp(i, 1, n){
        string s;
        cin >> s;
        a[i] = s.size();
    }
    lp(i, 1, k){
        ans += cnt[a[i]];
        ++cnt[a[i]];
    }  
    lp(i, k + 1, n){
        ans += cnt[a[i]];
        --cnt[a[(i - k)]];
        ++cnt[a[i]];
    }
    cout << ans;
}