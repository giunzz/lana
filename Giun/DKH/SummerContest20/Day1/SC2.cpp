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
const string tenfile = "SC2";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cii maxn = 1e5 + 7;
ii t, n, k, ans, u2[maxn], u5[maxn], b;

void demuoc(){
    u2[0] = 0, u5[0] = 0;
    loop(i, 1, n){
        b = i, u2[i] = u2[i - 1], u5[i] = u5[i - 1];
        while(!(b % 5) && b > 0) ++u5[i], b /= 5;
        while(!(b % 2) && b > 0) ++u2[i], b /= 2;
    }
}

int main(){
    opt;
    fi;
    cin >> t;
    while(t--){
        cin >> n >> k;
        demuoc();
        ans = min(u2[n] - (u2[k] + u2[n - k]), u5[n] - (u5[k] + u5[n - k]));
        cout << ans << "\n";
    }
}