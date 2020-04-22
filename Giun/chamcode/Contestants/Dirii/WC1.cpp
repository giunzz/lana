#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define er(variable) cerr << variable << " "
#define erl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type, type1) pair<type, type1>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "WC1";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7, mod = 68718952446;
ll t, n, a[maxn], b[maxn], e[maxn];

ll nhan(ll x, ll y){
    if(y < 1e8) return ((x % mod)*(y%mod))%mod;
    if(x == 1) return y;
    ll p = nhan(x, y / 2);
    p = (p + p) % mod;
    if (y % 2 == 1) p = (p + x) % mod;
    return p;
}

int main(){
    opt;
    fi;
    scanf("%I64d", &t);
    b[0] = 1;
    while (t--)
    {
        scanf("%I64d", &n);
        e[n + 1] = 1;
        loop(i, 1, n){
            scanf("%I64d", &a[i]);
            b[i] = (a[i] * b[i - 1]) % mod;
        }
        loopd(i, n, 1) e[i] = (a[i] * e[i + 1]) % mod;
        loop(i, 1, n){
            printf("%I64d ", nhan(b[i - 1], e[i + 1]));
        }
        printf("\n");
    }
}