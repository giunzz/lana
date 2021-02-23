#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "coolmac";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
ll n, m;
pp(ll, ll) a[maxn];
vec(pp(ll, ll)) res;

int main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n, greater<pp(ll, ll)>());
    res.push_back({-1, -1});
    lp(i, 1, n){
        ll b = a[i].first, e = a[i].second;
        if(res.size() == 1){
            res.push_back({b, e});
        }
        else{
            ll pree = res.back().second, preb = res.back().first;
            while((res.size() > 1 && pree <= e) || (res.size() > 2 && res[res.size() - 2].first <= e)) 
                res.pop_back(), pree = res.back().second, preb = res.back().first;
            if(res.size() > 1){
                if((preb == b && pree > e) || (e < preb)) continue;
            }
            res.push_back({b, e});
        }
    }
    // res.push_back({-1, -1});
    // lp(i, 1, res.size() - 1) cerr << res[i].first << ' ' << res[i].second << '\n';
    cin >> m;
    ll tmp = 0;
    lp(i, 1, m){
        ll num;
        cin >> num;
        if(res.size() == 1 || res[1].second != 1e5){
            // cout << -1 << '\n';
            tmp = -1;
            continue;
        }
        ll l = 1, r = res.size() - 1, ans = -1;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(res[mid].first <= num) ans = mid, r = mid - 1;
            else l = mid + 1; 
        }
        if(ans == -1) tmp = -1;
        else if(tmp != -1) tmp = max(tmp, ans);
        // cout << ans << '\n';
    }
    cout << tmp;
}
