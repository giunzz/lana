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

ii t, n, a, b, c, d, k[4][4];

int main(){
    opt;
    //afi;
    cin >> t;
    while(t--){
        cin >> n >> a >> b >> c >> d;
        k[1][1] = (a - b)*n, k[1][2] = (a + b)*n, k[2][1] = c - d, k[2][2] = d + c;
        if (k[2][1] <= k[1][1] && k[1][2] <= k[2][2]) cout << "YES\n";
        else if(k[2][1] <= k[1][1] && k[1][1] <= k[2][2]) cout << "YES\n";
        else if(k[2][1] <= k[1][2] && k[1][2] <= k[2][2]) cout << "YES\n";
        else cout << "NO\n";
    }
}