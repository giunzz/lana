#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "meeting"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

struct quang{
    ll b, e, id = 0;
};

cll maxn = 2e5 + 7;
ll n, res[maxn] = {0}, ans = 0;
quang a[maxn];

bool cpr(const quang &x, const quang &y){
    if(x.b == y.b && (x.e - x.b) < (y.e - y.b)) return 1;
    // if(x.b == y.b && (x.e - x.b) == (y.e - y.b) && x.id < y.id) return 1;
    return (x.b < y.b);
}

// ll cnp(ll x, ll i){
//     ll l = i, r = n, tmp = 0;
//     while(l <= r){
//         ll mid = (l + r) / 2;
//         if(a[mid].b >= x){
//             tmp = mid;
//             r = mid - 1;
//         }
//         else l = mid + 1;
//     }
//     return tmp;
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].b >> a[i].e; 
        a[i].id = i;
    }
    // cerr << 1;
    sort(a + 1, a + 1 + n, cpr);
    // lp(i, 1, n) cerr << a[i].b << ' ' << a[i].e << '\n';
    ll ee;
    lp(i, 1, n){
        // cerr << 1;
        // mi = LLONG_MAX, vt = 0;
        // if(!res[a[i].id])
        //     res[a[i].id] = ++ans;
        // lp(j, i + 1, n){
        //     if(a[j].b >= a[i].e && !res[a[j].id] && mi >= (a[j].b - a[i].e)) mi = a[j].b - a[i].e, vt = j; 
        // }
        // vt = cnp(a[i].e, i + 1);
        // while(res[a[vt].id] && vt) ++vt;
        // if(vt) res[a[vt].id] = res[a[i].id];
        if(res[a[i].id]) continue;
        res[a[i].id] = ++ans;
        ee = a[i].e;
        lp(j, i + 1, n){
            if(a[j].b >= ee){
                res[a[j].id] = ans, ee = a[j].e;
            }
        }
    }
    cout << ans << '\n';
    // lp(i, 1, n){
    //     cout << res[i] << '\n';
    // }
}