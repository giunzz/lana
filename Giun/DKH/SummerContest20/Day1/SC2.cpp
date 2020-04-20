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

int dzr(int n) 
{ 
    int cnt = 0; 
    for (int i = 5; n / i >= 1; i *= 5) 
        cnt += n / i; 
    return cnt; 
} 

ii t, n, k, ans;

int main(){
    opt;
    fi;
    cin >> t;
    while(t--){
        cin >> n >> k;
        cerr << dzr(n) << endl << dzr(k) << endl << dzr(n - k);
        ans = dzr(n) - (dzr(k) + dzr(n - k));
        cout << ans << "\n";
    }
}