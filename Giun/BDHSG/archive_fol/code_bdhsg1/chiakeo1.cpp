#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "chiakeo1"
// #define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 107;
ll n, a[maxn], res[maxn];
vec(ll) aa;

vec(ll) nen(vec(ll) &x){
    set<ll> tmp(x.begin(), x.end());
    vec(ll) tmp1(tmp.begin(), tmp.end());
    return tmp1;
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    OF();
    // cin >> n;
    scanf("%lld", &n);
    aa.push_back(1);
    memset(res, -1, sizeof(res));
    lp(i, 1, n){
        // cin >> a[i];
        scanf("%lld", &a[i]);
        ll d = 1;
        while(d <= a[i]){
            d = a[i] / (a[i] / d) + 1;
            aa.push_back(d);
        }
    }
    // lp(i, 0, maxn - 1) res[i] = LLONG_MAX;
    // aa.resize(distance(aa.begin(), unique(aa.begin(), aa.end())));
    aa = nen(aa);
    sort(a + 1, a + 1 + n);
    // for(ll &v : aa){
    //     cerr << v << ' ';
    // }
    lp(t, 0, aa.size() - 1){
        ll cnt = 1, tmp = a[1] / aa[t];
        lp(i, 2, n){
            if(a[i] / aa[t] == tmp) ++cnt;
            else{
                // res[cnt] = min(res[cnt], aa[t]);
                if(res[cnt] == -1) res[cnt] = aa[t];
                cnt = 1; tmp = a[i] / aa[t]; 
            }
        }
        if(res[cnt] == -1) res[cnt] = aa[t];
    }
    lp(i, 1, n){
        // if(res[i] == LLONG_MAX) {
        //     // cout << -1 << '\n';
        //     printf("-1\n");
        // }
        // else{
        //     printf("%lld\n", res[i]);
        //     // cout << res[i] << '\n';
        // }
        printf("%lld\n", res[i]);
    }
}