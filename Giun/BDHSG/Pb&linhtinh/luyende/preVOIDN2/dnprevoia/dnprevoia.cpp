#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

cll maxn = 1e6 + 7, maxlt = 31622, maxx = 29;
ll n;
ll s[maxn] = {0};

inline ll poww(ll a, ll b){
    if(b == 1) return a;
    ll tmp = poww(a, b / 2);
    if(b & 1) return tmp * tmp * a;
    return tmp * tmp;
}

// inline ll pow1(ll a, ll b){
//     if(b == 1) return a;
//     ll tmp = poww(a, b / 2);
//     if(tmp == -1) return -1;
//     if(tmp > 1e9 / tmp) return -1;
//     if(b & 1) return tmp * tmp * a;
//     return tmp * tmp;
// }

inline void bruce(){
    ll tmp = n, cnt = 0, tg = 0, tp = 0;
    bool ok = 0;
    for(ll i = 2; i*i <= n; ++i){
        if(n % i == 0){
            tg = i, cnt = 1, tp = i;
            while(tp < n) tp *= i, ++cnt;  
            if(tp == n){
                ok = 1;
                break;
            }
        }
    }
    if(ok){
        while(cnt != 1){
            cout << tg << ' ' << cnt << '\n';
            tg = poww(tg, s[cnt]), cnt /= s[cnt];
        }
    }   
    cout << n << ' ' << 1 << "\n\n";
}

// ll cnp(ll l, ll r, ll id){
//     while(l <= r){
//         ll mid = (l + r) / 2, tmp = pow1(mid, id);
//         if(tmp == -1 || tmp > n) r = mid - 1;
//         else if(tmp == n){
//             return tmp;
//         }
//         else l = mid + 1;
//     }
//     return -1;
// }

// inline void sol(){

//     lpd(i, maxx, 2){
//         ll x = cnp(1, n, i);
//     }
// }

int main(){
    file("dnprevoia");
    ll t;
    for(ll i = 2; i <= 1e6; ++i){
        for(ll j = i * i; j <= 1e6; j += i){
            if(!s[j]) s[j] = i;
        }
        if(!s[i]) s[i] = i;
    }
    cin >> t;
    while(t--){
        cin >> n;
        bruce();
        // sol();   
    }
}