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
ll n, k, q, a[maxn][maxn], d[maxn], kp[maxn] = {0}, cnt = 0, ans = LLONG_MAX, f[2000][maxn];
vec(ll) truck[7];
vector<ll> city;

ll countbito(ll u){
    if(u == 0) return 0;
    return (u & 1) + countbito(u >> 1);
}

ll dp(ll stt, ll ed, ll r, ll nped){
    // cerr << r << ' ' << stt << '\n';
    if(countbito(stt) == 1) return a[0][ed];
    ll ttmp = 0;
    lp(i, 0, truck[r].size() - 1){
        ll ii = truck[r][i], tmp = LLONG_MAX;
        if(ed == ii) continue;
        if((1 << i) & stt){
            tmp = min(tmp, dp(stt ^ (1 << nped), ii, r, i) + a[ii][ed]);
            ttmp += tmp;
        }
        else continue;
    }
    return ttmp;
}

void gene(ll pos){
    if(n - pos + 1 < k - cnt) return;
    if(pos > n){
        ll a1 = 0;
        lp(i, 0, k - 1){
            // ll ttmp = LLONG_MAX;
            // ll stt = (1 << truck[i].size()) - 1;
            // if(countbito(stt) == 1) {
            //     a1 += a[truck[i][0]][0] + a[0][truck[i][0]];
            //     continue;
            // }
            // lp(j, 0, truck[i].size() - 1){
            //     ll ii = truck[i][j], tmp = LLONG_MAX;
            //     lp(z, 0, truck[i].size() - 1){
            //         ll jj = truck[i][z];    
            //         if(jj == ii) continue;
            //         tmp = min(dp(stt ^ (1 << j), jj, i, z) + a[jj][ii], tmp);
            //     }
            //     ttmp = min(ttmp, tmp + a[ii][0]);
            // }
            // a1 += ttmp;
            // // cerr << ttmp << ' ';
        }
        // cerr << '\n';
        ans = min(a1, ans);
        return;
    }
    lp(i, 0, k - 1){
        if(!kp[i]++) ++cnt;
        truck[i].push_back(pos);
        gene(pos + 1);
        truck[i].pop_back();
        if(!--kp[i]) --cnt;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
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