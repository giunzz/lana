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
#define filln(a, b) memset(a, b, sizeof(a))
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 5e3 + 7;
ll choose[(ii)1e6 + 7], ans[(ii)1e6 + 7], n, a[maxn] = {0}, d[maxn];
struct stc{
    ll vl, vt;
};
vector<stc> c;

bool operator<(stc const &l, stc const &r){
    return (l.vl < r.vl);
}

void tinhluythua(){
    ll size = 1;
	for(ll i = 5000; i >= 0; i --) {
		ll t = choose[i];
		for(ll j = 0; j < size; j ++) {
			ans[j] = ans[j] * 2 + t;
			if(ans[j] > 9) {
				ans[j] -= 10;
				t = 1;
				if(j + 1 == size) size++;
			} 
            else t = 0;
		}
    }
    lpd(i, size - 1, 0) printf("%lld", ans[i]);
}

inline ll ops(ll a){
    return (a * -1);
}

void enter(){
    ll num;
    string str;
    lp(i, 1, n){
        cin >> str >> num;
        if(str == "sell") {c.push_back({num, i}); num = ops(num);}
        a[i] = num;
    }
}

void prc(){
    ll v, bg = 0;
    lpd(i, c.size() - 1, 0){
        v = c[i].vt;
        if(d[v]) continue;
        lpd(j, v - 1, 0){
            if(d[j]) break;
            if(a[j] == abs(c[i].vl)){
                bg = j;
                break;
            }
        }
        if(bg){
            lp(i, bg, v) d[i] = 1;
            choose[c[i].vl] = 1;
        }
    }
}

ii main(){
    opt;
    file;
    filln(choose, 0); filln(ans, 0); filln(d, 0);
    cin >> n;
    enter();    
    sort(c.begin(), c.end());
    prc();
    tinhluythua();
}
