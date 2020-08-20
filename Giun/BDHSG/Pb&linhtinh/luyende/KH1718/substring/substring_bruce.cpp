#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".ans").c_str(), "w", stdout);
}

ll n, k;
string s;

ll cnt(string a){
    set<ll> b(a.begin(), a.end());
    return b.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    file("substring");
    cin >> n >> k >> s;
    --n;
    string sub;
    ll ans = 0, tmp;
    lp(i, 0, n){
        lp(j, i, n){
            sub.clear();
            sub = s.substr(i, j - i + 1);
            if(cnt(sub) == k) ans = max(ans, j - i + 1);
        }
    }
    cout << ans;
}