#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "history"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 2507;
ll n, a[maxn] = {0}, ans = 0;
map<string, ll> id;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    string s;
    lp(i, 1, n){
        cin >> s;
        id[s] = i;
    }
    lp(i, 1, n){
        cin >> s;
        a[i] = id[s];
        lp(j, 1, i - 1)
            if(a[j] < a[i]) ++ans;
    }
    cout << ans << '/' << n * (n - 1) / 2;
}