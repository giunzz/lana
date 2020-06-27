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
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll n, a[13] = {0}, d[13] = {0};
map<ll, ll> dd;
vec(ll) ans;

void ql(ll vt){
    if(vt > n) {
        ll s = 0;
        stack<ll> st;
        st.push(a[1]);
        lp(i, 2, n){
            if(d[i]){
                s = st.top();
                st.pop();
                s *= a[i];
                s %= MOD;
                st.push(s);
            }
            else{
                st.push(a[i]);
            }
        }
        s = 0;
        while(!st.empty()) {s = (s + st.top()) % MOD; st.pop();}
        if(!dd[s]++){
            ans.push_back(s);
        }
    }
    else{
        lp(i, -1, 1){
            if(i == 1 && vt == 1) continue;
            if(i == -1){
                a[vt] *= i;
                ql(vt + 1);
                a[vt] *= i;
            }
            else if(i == 0){
                ql(vt + 1);
            }
            else {
                d[vt] = 1;
                ql(vt + 1);
                d[vt] = 0;
            }
        }
    }
}

ii main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    ql(1);
    cout << ans.size();
    cerr << clock() << " ms";
}
