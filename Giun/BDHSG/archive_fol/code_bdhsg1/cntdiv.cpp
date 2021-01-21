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

cll maxn = 1e6 + 10;
ll n, d[maxn] = {0}, ct[maxn];
vec(ll) uc;

void init(){
    d[1] = 0;
    for(ll i = 2; i * i < maxn; ++i){
        if(!d[i]){
            for(ll j = i * i; j < maxn; j += i) d[j] = i; 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    init();
    ll cs;
    cin >> cs;
    while(cs--){
        cin >> n;
        uc.clear();
        // memset(ct, 0, sizeof(ct));
        ll tt = n, i = (d[tt] ? d[tt] : tt);
        while(tt!=1){
            if(!ct[i]++) uc.push_back(i);
            tt /= i;
            if(tt == 1) break;
            i = (d[tt] ? d[tt] : tt);
        }
        tt = n + 1, i = (d[tt] ? d[tt] : tt);
        while(i){
            if(!ct[i]++) uc.push_back(i);
            tt /= i;
            if(tt == 1) break;
            i = (d[tt] ? d[tt] : tt);
        }
        tt = n + 2, i = (d[tt] ? d[tt] : tt);
        while(i){
            if(!ct[i]++) uc.push_back(i);
            tt /= i;
            if(tt == 1) break;
            i = (d[tt] ? d[tt] : tt);
        }
        ll cnt = 1, cntt = 1;
        for(ll &i : uc){
            cnt *= (ct[i] + 1);
            cntt *= (ct[i] * 2 + 1);
            ct[i] = 0;
        }
        cntt = (cntt + 1) / 2;
        cout << (cntt - cnt) << '\n';
    }
}