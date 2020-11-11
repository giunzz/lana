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

cll maxn = 1e6 + 7;
ll n, ct[maxn];
bool d[maxn] = {0};
vec(ll) snt, uc;

void init(){
    d[0] = d[1] = 1;
    for(ll i = 2; i < maxn; ++i){
        if(!d[i]){
            snt.push_back(i);
            for(ll j = i * i; j < maxn; j += i){d[j] = 1;}
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
        memset(ct, 0, sizeof(ct));
        cin >> n;
        ll tt = n, tt1 = n + 1, tt2 = n + 2;
        uc.clear();
        // uc.push_back(0);
        for(ll &i : snt){
            if(tt == 1 && tt1 == 1 && tt2 == 1) break;
            if(tt % i == 0 || tt1 % i == 0 || tt2 % i == 0) uc.push_back(i);
            else continue;
            while(tt % i == 0){
                ++ct[i];
                tt /= i;
            }
            while(tt1 % i == 0){
                ++ct[i];
                tt1 /= i;
            }
            while(tt2 % i == 0){
                ++ct[i];
                tt2 /= i;
            }
        }
        // tt = n+1;
        // for(ll &i : snt){
        //     if(tt == 1) break;
        //     if(tt%i) continue;
        //     while(tt % i == 0){
        //         ++uc.back();
        //         tt /= i;
        //     }
        //     uc.push_back(0);
        // }
        // tt = n + 2;
        // while(tt%2 == 0) ++uc[0], tt/=2;
        // for(ll &i : snt){
        //     if(tt == 1) break;
        //     if(tt%i) continue;
        //     while(tt % i == 0){
        //         ++uc.back();
        //         tt /= i;
        //     }
        //     uc.push_back(0);
        // }
        // // for(ll i : uc) cerr << i << ' ';
        // uc.pop_back();
        ll cnt = 1, cntt = 1;
        for(ll &i : uc){
            cnt *= (ct[i] + 1);
            cntt *= (ct[i] * 2 + 1);
        }
        cntt = (cntt + 1) / 2;
        cout << (cntt - cnt) << '\n';
    }
}