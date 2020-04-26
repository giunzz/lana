#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define er(variable) cerr << variable << " "
#define erl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(ll variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type, type1) pair<type, type1>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

typedef struct{
    ll fir, sec, thi;
} pp3;

cll Max = 2e5 + 7;
ll n, k, d = 0, c = 0, tt, ans = 0;
pp(ll, ll) t[Max];
pp3 s[Max];

void setup(ll b){
    ans = 0;
    loop(i, 1, n){
        tt = 0;
        if (b <= t[i].first) 
            tt += s[i].fir*b;
        else{
            tt += s[i].fir*t[i].first;
            if (b <= t[i].second)
                tt += (b - t[i].first) * s[i].sec;
            else
                tt += s[i].sec*(t[i].second - t[i].first) + (b - t[i].second) * s[i].thi;
        }        
        ans += tt;
    }
}

int sol(ll l, ll r){
    ll mid;
    while(r - l > 1){
        mid = (r + l)/2;
        setup(mid);
        if (ans < k) l = mid;
        else if (ans > k) r = mid;
        else return mid;
    }
    setup(r);
    if (ans <= k) return r;
    else return l;
}

int main(){
    opt;
    file;
    cin >> n >> k;
    loop(i, 1, n){
        cin >> t[i].first >> t[i].second >> s[i].fir >> s[i].sec >> s[i].thi;
        c = max(c, t[i].second);
    }
    setup(c);
    if (ans == k){ cout << c; return 0;}
    if (ans < k){
        d = c;
        while (ans < k && c <= 1e18){
            c = min(c * 2, (ll)1e18);
            setup(c);
        }
    }
    cout << sol(d, c);
}