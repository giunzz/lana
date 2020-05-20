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
#define MOD 1e9 + 7
using namespace std;
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

pp(ii, ii) a, b, c, vtab, vtac;

int main(){
    opt;
    //fi;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    vtab.first = b.first - a.first;
    vtab.second = b.second - a.second;
    vtac.first = c.first - a.first;
    vtac.second = c.second - a.second;
    cout << (vtab.first*vtac.second == vtab.second*vtac.first);
}
