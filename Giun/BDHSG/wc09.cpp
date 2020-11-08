#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "fairplay"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll k;
vec(pp(ll, ll)) ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    ll t;
    cin >> t;
    k = t;
    ll res, ct = 0;
    bool stt = 0;
    for(ll i = 2; i * i <= k; i++){
        // if(!(k % i) && stt){
        //     cout << "1\n" << (t / res);
        //     return 0;
        // }
        if(!(k % i)){
            // ++ct;
            res = i;
            ll cnt = 0;
            while(!(k % i)) k /= i, ++cnt;
            if(cnt > 1) {cout << "1\n" << (t / (res * res)); return 0;}
        }
    }
    cout << "2\n0";
}   

//tim 