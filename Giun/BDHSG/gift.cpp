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

cll maxDg = 17, maxCar = 17;
ll f[maxDg + 1][maxCar][2][2][2], pow3[100], lt, pow2[100];
string n;

struct quang{
    ll n1, n2, n3;
};

ll sol(ll pos, ll car, bool ok1, bool ok2, bool ok3){
    if(pos == -1) return((car == 0 && ok1 && ok2 && ok3) ? 0 : -1);
    if(f[pos][car][ok1][ok2][ok3] > -1) return f[pos][car][ok1][ok2][ok3];
    ll cnt = -1;
    quang res;
    lp(x, 0, 9) lp(y, 0, 9) lp(z, 0, 9){
        ll s = x + y + z;
        if((x > y && !ok2) || (y > z && !ok3)) continue;
        bool nok1 = x | ok1, nok2 = (x < y) | ok2, nok3 = (y < z) | ok3;
        lp(ncar, 0, 2){
            if((s + ncar) / 10 != car || (s + ncar) % 10 != n[pos] - '0') continue;
            // quang nt = {t.n1 * 10 + x, t.n2 * 10 + y, t.n3 * 10 + z};
            ll tmp = sol(pos - 1, ncar, nok1, nok2, nok3);
            if(tmp > -1 && tmp + s > cnt){
                cnt = tmp + s;
                // res = nt;
            }
        }
    }
    // t = res;
    f[pos][car][ok1][ok2][ok3] = cnt;
    return cnt;
}

vec(pp(ll, ll)) gt(ll num){
    if(num == 1){
        return {{0, 0}};
    }
    vec(pp(ll, ll)) tmp;
    if(~num & 1){
        tmp = gt(num >> 1);
        for(pp(ll, ll) &i : tmp){
            ++i.first;
        }
        return tmp;
    }
    ll p3 = lower_bound(pow3, pow3 + lt + 1, num) - pow3;
    if(pow3[p3] > num) --p3;
    if(pow3[p3] == num){
        return {{0, p3}};
    }
    tmp = gt(num - pow3[p3]);
    tmp.push_back({0, p3});
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    pow3[0] = 1, pow2[0] = 1;;
    lp(i, 1, 99){
        pow3[i] = pow3[i - 1] * 3, lt = i;
        if(pow3[i] > 1e16) break;
    }
    lp(i, 1, 99){
        pow2[i] = pow2[i - 1] * 2;
        if(pow2[i] > 1e16) break;
    }
    ll cs;
    cin >> cs;
    while(cs--){
        cin >> n;
        while(n.size() <= maxDg) n = '0' + n;
        reverse(n.begin(), n.end());
        memset(f, -1, sizeof(f));
        quang t = {0, 0, 0};
        ll ans = sol(maxDg, 0, 0, 0, 0);
        if(ans == -1){
            cout << ans << '\n';
            continue;
        }
        vec(pp(ll, ll)) ans1 = gt(t.n1), ans2 = gt(t.n2), ans3 = gt(t.n3);
        cout << ans1.size() << ' ' << ans2.size() << ' ' << ans3.size() << ' ';
        for(pp(ll, ll) i : ans1)
            cout << pow2[i.first] * pow3[i.second] << ' ';
        for(pp(ll, ll) i : ans2)
            cout << pow2[i.first] * pow3[i.second] << ' ';
        for(pp(ll, ll) i : ans3)
            cout << pow2[i.first] * pow3[i.second] << ' ';
        cout << '\n';
    }
}