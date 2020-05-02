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
const string tenfile = "SC4";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll t, n, mod, k, tk, f, g, h, x;

ll Pow(ll a, ll n)
{
    if(n == 0) return 1;
    if(n == 1) {
        return a;
    } 
    else {
        ll t = Pow(a, n/2);
        if(n % 2 == 0)
            return (t * t) % mod;
        else
            return (((t * t) % mod) * a) % mod;
    }
}

int main(){
    opt;
    fi;
    //cin >> t;
    scanf("%I64d", &t);
    while(t--){
        f = 0, g = 0, h = 0;
        //cin >> x >> n >> mod;
        scanf("%I64d %I64d %I64d", &x, &n, &mod);
        k = sqrt(++n);
        tk = n/k;
        loop(i, 0, k - 1) f += Pow(x, i);
        loop(i, 0, tk - 1) g += Pow(x, i * k);
        loop(i, tk * k, n - 1) h += Pow(x, i);
        //cout << (((f % mod) * (g % mod)) % mod + h % mod) % mod << "\n";
        printf("%I64d\n", (((f % mod) * (g % mod)) % mod + h % mod) % mod);
    }
}
