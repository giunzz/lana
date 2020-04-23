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
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll t, n, m, x, y, ans;

ll Pow(ll a, ll n)
{
    if(n == 0) return 1;
    if(n == 1) {
        return a;
    } 
    else {
        ll t = Pow(a, n/2);
        if(n % 2 == 0)
            return (t * t) % m;
        else
            return (((t * t) % m) * a) % m;
    }
}

int main(){
    opt;
    fi;
    cin >> t;
    while(t--){
        cin >> x >> n >> m;
        //y = Pow(x, n + 1);
        //if (x == 2) cerr  << y;
        //ans = ((y - 1)/(x - 1)) % m;
        loop(i, 0, n) ans += Pow(x, i);
        cout << ans % m << "\n";
        ans = 0;       
    }
}