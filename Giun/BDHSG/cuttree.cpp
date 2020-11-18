#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "cuttree"
#pragma GCC optimize("Ofast")
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 3e5 + 7, maxhcn = 1e5 + 7, maxtd = 1e6 + 7;
ll n, k;
pp(ll, ll) p[maxn];
pp(pp(ll, ll), pp(ll, ll)) hcn[maxhcn];
vec(ll) lx[maxtd], ly[maxtd];

#define x first 
#define y second

#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second

void init(){
    set<ll> nen;
    cin >> n;
    lp(i, 1, n){
        cin >> p[i].x >> p[i].y;
        nen.insert(p[i].x);
        nen.insert(p[i].y);
    }
    cin >> k;
    lp(i, 1, k){
        cin >> hcn[i].x1 >> hcn[i].y1 >> hcn[i].x2 >> hcn[i].y2;
        nen.insert(hcn[i].x1);
        nen.insert(hcn[i].x2);
        nen.insert(hcn[i].y1);
        nen.insert(hcn[i].y2);
    }
    vec(ll) tmp(nen.begin(), nen.end());
    lp(i, 1, n){
        p[i].x = lower_bound(tmp.begin(), tmp.end(), p[i].x) - tmp.begin() + 1;
        p[i].y = lower_bound(tmp.begin(), tmp.end(), p[i].y) - tmp.begin() + 1;
        lx[p[i].x].push_back(p[i].y);
        ly[p[i].y].push_back(p[i].x);
    }  
    lp(i, 1, k){
        hcn[i].x1 = lower_bound(tmp.begin(), tmp.end(), hcn[i].x1) - tmp.begin() + 1;
        hcn[i].x2 = lower_bound(tmp.begin(), tmp.end(), hcn[i].x2) - tmp.begin() + 1;
        hcn[i].y1 = lower_bound(tmp.begin(), tmp.end(), hcn[i].y1) - tmp.begin() + 1;
        hcn[i].y2 = lower_bound(tmp.begin(), tmp.end(), hcn[i].y2) - tmp.begin() + 1;
    }
    lp(i, 1, maxtd - 1){
        sort(lx[i].begin(), lx[i].end());
        sort(ly[i].begin(), ly[i].end());
    }
}

inline ll cnp(vec(ll) const &w, ll l, ll const &rt, ll const &tg){
    ll r = rt - 1, ans = -1;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(w[mid] >= tg) r = mid - 1;
        else {
            ans = mid;
            l = mid + 1;
        }
    }
    return (ans + 1);
}

inline ll cnp1(vec(ll) const &w, ll l, ll const &rt, ll const &tg){
    ll r = rt - 1, ans = -1;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(w[mid] > tg) r = mid - 1;
        else {
            ans = mid;
            l = mid + 1;
        }
    }
    return (ans + 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    init();
    lp(i, 1, k){
        ll a = cnp(lx[hcn[i].x1], 0, lx[hcn[i].x1].size(), hcn[i].y2) -
        cnp(lx[hcn[i].x1], 0, lx[hcn[i].x1].size(), hcn[i].y1);

        ll b = cnp(ly[hcn[i].y2], 0, ly[hcn[i].y2].size(), hcn[i].x2) -
        cnp(ly[hcn[i].y2], 0, ly[hcn[i].y2].size(), hcn[i].x1);
        
        ll c = cnp1(lx[hcn[i].x2], 0, lx[hcn[i].x2].size(), hcn[i].y2) -
        cnp1(lx[hcn[i].x2], 0, lx[hcn[i].x2].size(), hcn[i].y1);
        
        ll d = cnp1(ly[hcn[i].y1], 0, ly[hcn[i].y1].size(), hcn[i].x2) -
        cnp1(ly[hcn[i].y1], 0, ly[hcn[i].y1].size(), hcn[i].x1);
        
        cout << (a + b + c + d) << '\n';
    }
}