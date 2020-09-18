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
const string node[] = {"Do", "Re", "Mi", "Fa", "Son", "La", "Si"};
const string tenfile = "ac4";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll qr, n, m, cnt;
string tmp;
vec(ll) a;
map<string, ll> dd;

void init(){
    lp(i, 0, 6) dd[node[i]] = i + 1;
}

int main(){
    opt;
    file;
    cin >> qr;
    init();
    while(qr--){
        a.clear(); cnt = 0;
        cin >> n >> m;
        lp(i, 1, n){
            cin >> tmp;
            a.push_back(dd[tmp]);
        } 
        lp(i, 1, a.size() - 2){
            if((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1])) ++cnt;
        }
        if(cnt >= m) cout << "YES\n";
        else cout << "NO\n";
    }
    // cerr << clock();
}
