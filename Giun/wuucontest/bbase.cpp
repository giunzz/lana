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

cii Max = 2e3 + 3;
ll m, n, p, q, u, v, a[Max][Max], r[Max][Max];

int main(){
    opt;
    fi;
    loop(i, 0, Max) a[i][0] = 0, a[0][i] = 0;
    cin >> m >> n >> p >> q >> u >> v;
    loop(i, 1, m){
        loop(j, 1, n){
            cin >> r[i][j];
            a[i][j] = a[i][j - 1] - a[i - 1][j - 1] + a[i - 1][j] + r[i][j];
        }
    }
}