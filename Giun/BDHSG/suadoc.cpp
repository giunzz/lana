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

ll q, n, k, tt;

int main(){
    opt;
    //fi;
    cin >> q;
    while(q--){
        cin >> n >> k;
        if (n % 2) tt = (n / 2) * 8;
        else tt = (n / 2) * 3 + (n / 2 - 1) * 5;
        if (tt >= k) printf("YES\n");
        else printf("NO\n");
    }
}