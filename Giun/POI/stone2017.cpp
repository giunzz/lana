#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 2e5 + 7;

struct quang{
    ll x, y;  
    quang() : x(0), y(0) {}
    quang(ll x, ll y) : x(x), y(y) {}
    quang operator+(const quang &q) const{
        return quang(this -> x + q.x, this -> y + q.y);
    }
};

ll dis(const quang &q){
    return q.x * q.x + q.y * q.y;
}

ll n;
quang a[maxn];
pp(quang, ll) f[maxn][4];

struct segTree{

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 1, n) cin >> a[i].x >> a[i].y;
    f[0].first = {0, 0};
    lp(i, 0, n) f[i].second = 0;
    ll res = 0, stt;
    lp(i, 1, n){
        lp(j, 0, 3) f[i][j] = f[q[j].top().second][j];
        lp(j, 0, 3){
            ll t = q[j].top().first;
            ll id = q[j].top().second;
            quang tmp = f[id][j].first + a[i];
            // if(dis(tmp) > f[i].second)
            //     f[i] = {tmp, dis(tmp)};
            if(tmp.x > 0 && tmp.y > 0){
                stt = 0;
            }
            else if(tmp.x > 0 && tmp.y < 0){
                stt = 1;
            }
            else if(tmp.x < 0 && tmp.y < 0){
                stt = 2;
            }
            else{
                stt = 3;
            }

            q.push({dis(tmp), i});
        }
        res = max(res, dis(tmp));
        // cerr << tmp.x << ' ' << tmp.y << ' ' << dis(tmp) << endl;
    }
    cout << res;
}