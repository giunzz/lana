#include <bits/stdc++.h>
#define f0(i, n) for(int i(0); i < (n); i++)
#define f1(i, n) for(int i(1); i <= n; i++)
#define bit(x, y) (((x) >> (y))&(1ll))

using namespace std;
typedef long long ll;
const int N = 42;

int n, a, b;
map <ll, int> g;
ll k, mod = 1;

void fix(ll &x){
    ll y = x/mod;
    x = x - y*1ll*mod;
}

void print(int x, int y, int k1, int k2){
    ll cur = 0;
    for(k1 = k1 - 1; k1 >= 0; k1--){
        int bit = bit(x, k1);
        if(bit==0) cout << a;
        else cout << b;
    }
    for(k2 = k2 - 1; k2 >= 0; k2--){
        int bit = bit(y, k2);
        if(bit==0) cout << a;
        else cout << b;
    }
    ///cout << endl << cur;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    freopen("MODULO.inp", "r", stdin);
    freopen("MODULO.out", "w", stdout);

    cin >> a >> b;
    cin >> n >> k;
    f1(i, n) mod = mod*2ll;

    int m = n/2;
    int remain = n - m;
    ll cur = 1;
    f1(i, remain) cur = (cur*10)%mod;
    for(int i = 0; i < (1ll << m); i++){
        ll now = 0;
        for(int j = m - 1; j >= 0; j--){
            if(bit(i, j)==0){
                now = now*10 + a;
            }
            else{
                now = now*10 + b;
            }
            fix(now);
        }
        now = now*1ll*cur;
        fix(now);
        g[now] = i;
    }
    for(int i = 0; i < (1ll << remain); i++){
        ll now = 0;
        for(int j = remain - 1; j >= 0; j--){
            if(bit(i, j)==0){
                now = now*10 + a;
            }
            else now = now*10 + b;
            fix(now);
        }
        ll x;
        if(now <= k){
            x = k - now;
        }
        else{
            x = mod + k - now;
        }
        if(g.find(x) != g.end()){
            print(g[x], i, m, remain);
        }
    }
    cout << -1;
}

