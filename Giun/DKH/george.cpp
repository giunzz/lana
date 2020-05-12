#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define loop(variable, valuegan, valuebehonbang) for(ll variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(ll variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(ll variable = valuegan; conditions; thaydoi) 
#define pp(type, type1) pair<type, type1>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 5e3 + 7;
ll n, m, k, a[maxn] = {0}, f[maxn][maxn] = {{0}};

int main(){
    opt;
    fi;
    cin >> n >> m >> k;
    loop(i, 1, n) cin >> a[i], a[i] += a[i - 1];
    loop(i, 1, k){
        loop(j, i * m, n){
            f[i][j] = max(f[i][j - 1], f[i - 1][j - m] + a[j] - a[j - m]);
        }
    }
    cout << f[k][n];
}