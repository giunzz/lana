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

ii n, ans, x, y, ok = 0;
pp(ii, ii) a[1003];

int main(){
    opt;
    //fi;
    ifstream fin1, fin2;
    fin1.open("f.inp");
    fin2.open("f.out");
    fin1 >> n;
    loop(i, 1, n) fin1 >> a[i].first >> a[i].second;
    fin2 >> ans >> x;
    loop(i, 2, ans){
        fin2 >> y;
        if(a[x].second > a[y].first) ok = 1;
    }
    if(ok) cout << "WA";
    else cout << "AC";
}