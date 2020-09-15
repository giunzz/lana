#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

cll maxn = 3e5 + 7;
ll n, k;
pp(ll, ll) h[maxn];
map<ll, ll> xe;

#define kl second
#define gt first

bool cpr(pp(ll, ll) &a, pp(ll, ll) &b){
    return a.gt > b.gt || (a.gt == b.gt && a.kl < b.kl);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("f");
    ll tmp, ans = 0;
    cin >> n >> k;
    lp(i, 1, n) cin >> h[i].kl >> h[i].gt;
    lp(i, 1, k) {cin >> tmp; ++xe[tmp];}
    sort(h + 1, h + 1 + n, cpr);
    // lp(i, 1, n){
    //     cerr << h[i].kl << ' ' << h[i].gt << endl;
    // }
    lp(i, 1, n){
        auto it = xe.lower_bound(h[i].kl);
        if((*it).second) --(*it).second, ans += h[i].gt; 
        if (!xe[(*it).first]) xe.erase((*it).first);
    }
    cout << ans;
}
