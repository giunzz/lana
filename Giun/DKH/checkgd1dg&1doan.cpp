
#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(variable, valuegan, valuebehonbang) for(ll variable = valuegan; variable <= valuebehonbang; variable++)
#define lpd(variable, valuegan, valuelonhonbang) for(ll variable = valuegan; variable >= valuelonhonbang; variable--)
#define lpdk(variable, valuegan, conditions, thaydoi) for(ll variable = valuegan; conditions; thaydoi)
#define pp(type, type1) pair<type, type1>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
#define MOD 1e9 + 7
#define fi fisrt
#define se second
using namespace std;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ii a, b, c;
pp(ii, ii) A, B;

int main(){
    opt;
    //file;
    cin >> a >> b >> c >> A.fi >> A.se >> B.fi >> B.se;
    if((A.fi * a + A.se * b + c) * (B.fi*a + B.se * b + c) <= 0) cout << "0";
    else << cout << "1";
}











