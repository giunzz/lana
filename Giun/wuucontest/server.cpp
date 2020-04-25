#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define er(variable) cerr << variable << " "
#define erl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
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

void setup(){
    ans = 0;
    loop(i, 1, n){
        tt = t[i].first*s[i].fir + (t[i].second - t[i].first)*s[i].sec;
        if(c > t[i].second) tt += (c - t[i].second) * s[i].thi;
        ans += tt;
    }
}

void sol(ll l, ll r){

}

int main(){
    opt;
    file;
    cin >> n >> k;
    loop(i, 1, n){
        cin >> t[i].first >> t[i].second >> s[i].fir >> s[i].sec >> s[i].thi;
        c = max(c, t[i].second);
    }
    setup();
    if (ans == k){ cout << c; return 0;}
    if (ans < k){
        d = c;
        while (ans < k && c <= 1e18){
            c = min(c * 2, (ll)1e18);
            setup();
        }
    }
    sol(d, c);
}