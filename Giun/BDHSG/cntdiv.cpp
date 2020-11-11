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
ll n;
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
    OF();
    init();
    ll cs;
    cin >> cs;
    while(cs--){
        cin >> n;
        ll tt = n;
        uc.clear();
        uc.push_back(0);
        for(ll &i : snt){
            if(!tt) break;
            while(tt % i == 0){
                ++uc.back();
                tt /= i;
            }
            uc.push_back(0);
        }
        tt = n+1;
        for(ll &i : snt){
            if(!tt) break;
            while(tt % i == 0){
                ++uc.back();
                tt /= i;
            }
            uc.push_back(0);
        }
        tt = n + 2;
        if(tt%2 == 0) tt/=2;
        for(ll &i : snt){
            if(!tt) break;
            while(tt % i == 0){
                ++uc.back();
                tt /= i;
            }
            uc.push_back(0);
        }
        uc.pop_back();
        ll cnt = 1, cntt = 1;
        for(ll &i : uc){
            cnt *= (i + 1);
            cntt *= (i + 3);
        }
        --cnt, cntt /= 2;
        cout << (cntt - cnt) << '\n';
    }
}