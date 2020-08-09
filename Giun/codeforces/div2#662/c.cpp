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
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
ll t, n, a[maxn], num;

ii main(){
    opt;
    file;
    cin >> t;
    while(t--){
        cin >> n;
        memset(a, 0, sizeof(a));
        lp(i, 1, n) cin >> num, ++a[num];
        sort(a + 1, a + 1 + n);
        reverse(a + 1, a + 1 + n);
        ll x = 0;
        lp(i, 1, n){
            if(a[i] == a[1]) ++x;
            else break;
        }
        n -= x; //bo di cac so nhieu nhat o cuoi chi quan tam khoang vs cac so it xuat hien hon
        n /= (a[1] - 1); //chia khoang theo so xuat hien nhieu nhat 
        cout << (n-1)<<endl;
    }
}
