#include <bits/stdc++.h>
#define ii int
#define ll long long
#define sr string
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 <= obj3; obj1++)
#define lpd(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 >= obj3; obj1--)
#define pp(obj1, obj2) pair<obj1, obj2>
#define vec(obj1) vector<obj1>
#define vecite(obj1) vector<obj1>::iterator
#define fi first
#define se second
#define mp(obj1, obj2) map<obj1, obj2>
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "btmax";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll maxn = 100;
ll n, a[maxn], s = 0, k, ans = INT_MIN;

void ql(ll vt){
    if(vt > n && !k){
        ans = max(ans, abs(s));
        return;
    }
    if(vt > n) return;
    lp(i, 0, 1){
        if(i && k){
            s += (-1 * a[vt]), --k;
            ql(vt + 1);
            s -= (-1 * a[vt]), ++k;
        }
        else{
            s += a[vt];
            ql(vt + 1);
            s -= a[vt];
        }
    }
}

int main(){
    opt;
    file;
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i];
    s = a[1];
    ql(2);
    cout << ans;
}
