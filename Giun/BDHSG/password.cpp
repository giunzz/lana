#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "password"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 2e4 + 7;
string s[maxn];
ll n;
map<string, ll> mp;
map<string, bool> d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    ll ans = 0;
    cin >> n;
    lp(i, 1, n){
        cin >> s[i];
        // string tmp;
        ++mp[s[i]];
    }
    lp(i, 1, n){
        d.clear();
        string tmp;
        lp(j, 0, s[i].size() - 1){
            tmp.clear();
            lp(z, j, s[i].size() - 1){
                tmp.push_back(s[i][z]);
                // cerr << tmp << ' ';
                if(d[tmp]) continue;
                d[tmp] = 1;
                ans += mp[tmp];
            }
        }
        --ans;
        // cerr << '\n' << ans;
        // cerr << '\n';
    }
    cout << ans;
}