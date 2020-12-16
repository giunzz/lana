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
cll MOD = 998244353;
const double esf = 1e-9;
const string tenfile = "gift11";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 2e3 + 7;
ll n, a[maxn];
pp(ll, ll) s[maxn];

void sub2(){
    ll ans = 1, tmp = 0;
    lp(i, 1, n){
        tmp += s[i].first;
    }
    if(tmp % 11){
        cout << "0\n";
    } 
    else{
        lp(i, 1, n) (ans *= i) %= MOD;
        cout << ans << '\n';
    }
}

int main(){
    opt;
    file;
    ll cs;
    cin >> cs;
    while(cs--){
        bool sub = 0, ok = 1;
        cin >> n;
        lp(i, 1, n){
            cin >> a[i];
            ll tmp = 0, cnt = 0, d = -1;
            while(a[i]){
                tmp += d * (a[i] % 10);
                d  = -d;
                a[i] /= 10;
                ++cnt;
            }
            if(cnt & 1) tmp = -tmp;
            s[i] = {tmp, cnt};
            if(i > 1 && (s[i - 1].second & 1) != (s[i].second & 1)) ok = 0;
        }
        // if(ok){
        //     if(s[n].second % 2){
        //         sub3();
        //     }
        //     else sub2();
        // }
        sub2();
    }
}
