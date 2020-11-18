#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
#pragma GCC optimize("Ofast")
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 3e5 + 7, maxhcn = 1e5 + 7, maxtd = 1e6 + 7;
ll n, k;
pp(ll, ll) p[2][maxn];
pp(pp(ll, ll), pp(ll, ll)) hcn[maxhcn];

#define x first 
#define y second

#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second

bool cpr(pp(ll, ll) const &Q, pp(ll, ll) const &P){
    return Q.x < P.x || (Q.x == P.x && Q.y < P.y);
}

bool cpr1(pp(ll, ll) const &Q, pp(ll, ll) const &P){
    return Q.y < P.y || (Q.y == P.y && Q.x < P.x);
}

void init(){
    cin >> n;
    lp(i, 1, n){
        cin >> p[0][i].x >> p[0][i].y;
        // px[i] = p[i];
        p[1][i] = p[0][i];
    }
    cin >> k;
    lp(i, 1, k){
        cin >> hcn[i].x1 >> hcn[i].y1 >> hcn[i].x2 >> hcn[i].y2;
    }
    sort(p[0] + 1, p[0] + 1 + n, cpr);
    sort(p[1] + 1, p[1] + 1 + n, cpr1);
    lp(i, 1, n) cerr << p[0][i].x << ' ' << p[0][i].y << '\n';
}

inline ll cnp(ll const &stt, ll l, ll r, ll const &tgx, ll const &tgy){ //1 -> n
    ll ans = 0;
    if(stt){
        while(l <= r){
            ll mid = (l + r) / 2;
            if(p[stt][mid].y > tgy) r = mid - 1;
            else if(p[stt][mid].y < tgy) l = mid + 1, ans = mid;
            else{
                if(p[stt][mid].x < tgx) ans = mid, l = mid + 1;
                else r = mid - 1;
            }
        }
    }
    else{
        while(l <= r){
            ll mid = (l + r) / 2;
            if(p[stt][mid].x > tgx) r = mid - 1;
            else if(p[stt][mid].x < tgx) l = mid + 1, ans = mid;
            else{
                if(p[stt][mid].y < tgy) ans = mid, l = mid + 1;
                else r = mid - 1;
            }
        }
    }
    return ans;
}

inline ll cnp1(ll const stt, ll l, ll r, ll const &tgx, ll const &tgy){ //1 -> n
    ll ans = 0;
    if(stt){
        while(l <= r){
            ll mid = (l + r) / 2;
            if(p[stt][mid].y > tgy) r = mid - 1;
            else if(p[stt][mid].y < tgy) l = mid + 1, ans = mid;
            else{
                if(p[stt][mid].x <= tgx) ans = mid, l = mid + 1;
                else r = mid - 1;
            }
        }
    }
    else{
        while(l <= r){
            ll mid = (l + r) / 2;
            if(p[stt][mid].x > tgx) r = mid - 1;
            else if(p[stt][mid].x < tgx) l = mid + 1, ans = mid;
            else{
                if(p[stt][mid].y <= tgy) ans = mid, l = mid + 1;
                else r = mid - 1;
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    init();
    lp(i, 1, k){
        ll a = cnp(0, 1, n, hcn[i].x1, hcn[i].y2) -
        cnp(0, 1, n, hcn[i].x1, hcn[i].y1);

        ll b = cnp(1, 1, n, hcn[i].y2, hcn[i].x2) -
        cnp(1, 1, n, hcn[i].y2, hcn[i].x1);
        
        ll c = cnp1(0, 1, n, hcn[i].x2, hcn[i].y2) -
        cnp1(0, 1, n, hcn[i].x2, hcn[i].y1);
        
        ll d = cnp1(1, 1, n, hcn[i].y1, hcn[i].x2) -
        cnp1(1, 1, n, hcn[i].y1, hcn[i].x1);
        
        // cerr << a << ' ' << b << ' ' << c << ' ' << d << '\n';
        cout << (a + b + c + d) << '\n';
    }
}