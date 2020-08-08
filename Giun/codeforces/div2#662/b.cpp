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
ll n, a[maxn], tt[maxn] = {0};
priority_queue<pp(ll,ll)> q;

void init(){
    vec(ll) tmp(a + 1, a + 1 + n);
    set<ll> tmp1(tmp.begin(), tmp.end());
    vec(ll) ans(tmp1.begin(), tmp1.end());
    for(ll x : ans){
        q.push({tt[x], x});
    }
}

void qpush(pp(ll, ll) x[]){
    lp(i, 0, 2) if(x[i] != make_pair((ll)0, (ll)0)) q.push(x[i]);
}

ii main(){
    opt;
    // file;
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
        ++tt[a[i]];
    }
    init();
    ll query, num;
    pp(ll, ll) tmp[3];
    char cc;
    cin >> query;
    while(query--){
        cin >> cc >> num;
        tmp[0] = {0, 0}, tmp[1] = {0, 0}, tmp[2] = {0, 0};
        if(cc == '+') ++tt[num];
        else --tt[num];
        q.push({tt[num], num});
        lp(i, 0, 2 && !q.empty()) {
            tmp[i] = q.top(), q.pop();
            while(!q.empty() && tmp[i].fi != tt[tmp[i].se]) tmp[i] = q.top(), q.pop();
            if(tmp[i].fi != tt[tmp[i].se]) tmp[i] = {0, 0};
        }
        if(tmp[0].fi < 4) {cout << "NO\n"; qpush(tmp); continue;}
        if(tmp[0].fi >= 8){cout << "YES\n"; qpush(tmp); continue;}
        if(tmp[0].fi >= 6 && tmp[1].fi >= 2){cout<<"YES\n"; qpush(tmp); continue;}
        if(tmp[0].fi >= 4 && tmp[1].fi >= 4){cout<<"YES\n";qpush(tmp);continue;}
        if(tmp[0].fi >= 4 && tmp[1].fi >= 2 && tmp[2].fi >= 2){cout<<"YES\n"; qpush(tmp); continue;}
        qpush(tmp);
        cout<<"NO\n";
    }
}
