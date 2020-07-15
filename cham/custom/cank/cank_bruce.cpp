#include <bits/stdc++.h>
#define ii int
#define ll long long
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
const string tenfile = "cank";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

ll n, k, a[25] = {0}, tt[25] = {0}, ok = 0;

void ql(ll vt){
    if(ok) return;
    if(vt > n){
        ll ct = k, cp = 0;
        lp(i, 1, n){
            if(tt[i]) cp += a[i];
            else ct += a[i];
        }
        if(cp == ct) ok = 1;
        return;
    }
    lp(i, 0, 1){
        tt[vt] = i;
        ql(vt + 1);
    }
}

int main(){
    opt;
    file;
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i];
    ql(1);
    if(ok) cout << "YES";
    else cout << "NO";
    cerr << clock();
}
