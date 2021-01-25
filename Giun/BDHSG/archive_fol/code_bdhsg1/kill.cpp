#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
cll esf = 1e-9;
const string tenfile = "kill";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 3;
ll n, k, ans[maxn];
pp(ll, ll) a[maxn], b[maxn], c[maxn], id[maxn];
priority_queue<ll, vector<ll>, greater<ll> > ap;

int main(){
    opt;
    file;
    cin >> n >> k;
    lp(i, 1, n) cin >> b[i].fi;
    lp(i, 1, n) cin >> b[i].se;
    //b = a;
    lp(i, 1, n) id[i].fi = b[i].fi, id[i].se = i;
    sort(b + 1, b + 1 + n);
    sort(id + 1, id + 1 + n);
    // lp(i, 1, n) cerr << id[i].fi << " " << id[i].se << endl;
    c[1] = make_pair(b[1].se, INT_MAX);
    // ap.push(0);
    lp(i, 2, k + 1){
        //c[i].se = ap.top();
        //ap.pop();
        // c[i].se = max(c[i].se, b[i].se);
        c[i].se = min(c[i - 1].se, b[i - 1].se);
        // if (i == 3) cerr << c[i].se;
        ap.push(b[i - 1].se);
        // if(i == 3) cerr << b[i - 1].se << endl;
        // c[i].fi = c[i - 1].fi - b[i - 1].se  + c[i].se + b[i].se;
        c[i].fi = c[i - 1].fi + b[i].se;
    }
    // cerr << ap.top();
    // ap.push(b[k + 1].se);
    // lp(i, 1, k + 1) cerr << c[i].fi << " ";
    lp(i, k + 2, n){
        // ap.pop();
        c[i].se = max(b[i - 1].se, ap.top());
        c[i].fi = c[i - 1].fi - b[i - 1].se + b[i].se - ap.top() + c[i].se;
        ap.pop();
        if(c[i].se == b[i - 1].se) c[i].se = ap.top();
        ap.push(c[i].se); 
        // if(i == n) cerr << ap.top();
    }
    // lp(i, 1, n) cerr << b[i].fi << " " << id[i].se << endl;
    // cerr << endl;
    // lp(i, 1, n) cerr << c[i].se << " ";
    // cerr << endl;
    lp(i, 1, n){
        // if(i == 3) cerr << c[id[4].se].fi << " ";
        ans[id[i].se] = c[i].fi;
    }
    lp(i, 1, n) cout << ans[i] << " ";
}
