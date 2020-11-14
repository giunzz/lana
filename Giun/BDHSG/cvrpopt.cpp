#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 17;
ll n, k, q, a[maxn][maxn], d[maxn], kp[maxn] = {0}, cnt = 0, ans = LLONG_MAX;
vec(ll) truck[7];
vector<ll> city;

ll countbito(ll u){
    if(u == 0) return 0;
    return (u & 1) + countbito(u >> 1);
}

ll dp(ll stt, ll ped){
    // cerr << r << ' ' << stt << '\n';
    ll ed = city[ped];
    if(countbito(stt) == 1) return a[0][ed];
    ll tmp = LLONG_MAX;
    lp(i, 0, city.size() - 1){
        ll ii = city[i];
        if(ed == ii) continue;
        if((1 << i) & stt){
            tmp = min(tmp, dp(stt ^ (1 << ped), i) + a[ii][ed]);
        }
    }
    return tmp;
}

void gene(ll pos){
    if(n - pos + 1 < k - cnt) return;
    if(pos > n){
        // lp(i, 0, k - 1){
        //     ll s = 0;
        //     if(truck[i].empty()) return;
        //     for(ll &j : truck[i]) s += d[j];
        //     if(s > q) return;
        // }
        ll a1 = 0;
        lp(r, 0, k - 1){
            city.clear();
            city = truck[r];
            ll ct = city.size() - 1, stt = (1 << city.size()) - 1, opt = LLONG_MAX;
            if(city.size() == 1){
                a1 += a[city[0]][0] + a[0][city[0]];
                continue;
            }
            // cerr << city.size() << ' ' << stt << '\n';
            lp(i, 0, ct){
                ll ii = city[i], optcase = LLONG_MAX;
                lp(j, 0, ct){
                    if(i == j) continue;
                    ll jj = city[j], tmp1 = dp(stt ^ (1 << i), j) + a[jj][ii];
                    if(tmp1 < optcase) optcase = tmp1;
                }
                // opt = min(opt, optcase + a[ii][0]);
                if(optcase + a[ii][0] < opt) opt = optcase + a[ii][0];
            }
            a1 += opt;
        }
        ans = min(a1, ans);
        return;
    }
    lp(i, 0, k - 1){
        if(kp[i] + d[pos] > q) continue;
        if(!kp[i]) ++cnt;
        kp[i] += d[pos];
        truck[i].push_back(pos);
        gene(pos + 1);
        truck[i].pop_back();
        kp[i] -= d[pos];
        if(!kp[i]) --cnt;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    cin >> n >> k >> q;
    lp(i, 1, n) cin >> d[i];
    lp(i, 0, n){
        lp(j, 0, n){
            cin >> a[i][j]; // i -> j
            // cerr << a[i][j] << ' ';
        }
        // cerr << '\n';
    }
    // lp(i, 0, k -1) truck[i].push_back(0);
    gene(1);
    cout << ans;
}