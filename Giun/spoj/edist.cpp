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

ll t, n, m, f[2003][2003] = {{0}}; //fnm
string a, b;

ll sol(){
    ll cost;
    loop(i, 1, n){
        loop(j, 1, m){
            if(a[i] == b[j]) cost = 0;
            else cost = 1;
            f[i][j] = min(f[i - 1][j] + 1, min(f[i][j - 1] + 1, f[i-1][j-1] + cost));
        }
    }
    return f[n][m];
}

int main(){
    opt;
    fi;
    cin >> t;
    cin.ignore();
    loop(i, 0, 2002) f[i][0] = i, f[0][i] = i;
    while(t--){
        getline(cin, a);
        getline(cin, b);
        n = a.length(); m = b.length();
        a = "0" + a, b = "0" + b;
        if (!n) {cout << m << endl; continue;}
        if (!m) {cout << n << endl; continue;}
        cout << sol() << endl;
    }   
}